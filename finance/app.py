import os

from cs50 import SQL
from datetime import datetime
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    id = session.get("user_id")
    information = db.execute("SELECT symbol, amount FROM stocks WHERE userID = ?", id)
    balance = db.execute("SELECT cash FROM users WHERE id = ?", id)[0]["cash"]
    total = balance
    for row in information:
        symbol = row["symbol"]
        row["price"] = lookup(symbol)["price"]
        row["total"] = round(row["price"] * row["amount"], 2)
        total += row["total"]
    return render_template("index.html", balance=round(balance, 2), stocks=information, total=round(total, 2))

@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    if request.method == "POST":
        symbol = request.form.get("symbol")
        shares = request.form.get("shares")
        if symbol == "":
            return apology("Input a symbol")
        try:
            shares = float(shares)
        except ValueError:
            return apology("Shares should be a number")
        if shares < 0 or shares % 1 != 0:
            return apology("Shares should be a integer higher than 0")
        symbol = symbol.upper()
        stock = lookup(symbol)
        if stock == None:
            return apology("Stock symbol doesn't exist")
        price = round(stock["price"] * shares, 2)
        id = session.get("user_id")
        balance = db.execute("SELECT cash FROM users WHERE id = ?", id)[0]["cash"]
        if balance < price:
            return apology("Your balance isn't enough")
        db.execute("UPDATE users SET cash = cash - ? WHERE id = ?", price, id)
        dateTime = datetime.now()
        db.execute("INSERT INTO history(date, type, price, stockSymbol, userID, shares) VALUES (?, 'buy', ?, ?, ?, ?)", dateTime, price, symbol, id, shares)
        print(symbol)
        stocksOwen = db.execute("SELECT amount FROM stocks WHERE userID = ? AND symbol = ?", id, symbol)
        if len(stocksOwen) == 0:
            db.execute("INSERT INTO stocks(symbol, amount, userID) VALUES (?, ?, ?)", symbol, shares, id)
        else:
            db.execute("UPDATE stocks SET amount = amount + ? WHERE userID = ? AND symbol = ?", shares, id, symbol)
        return redirect("/")
    return render_template("buy.html")

@app.route("/history")
@login_required
def history():
    transactions = db.execute("SELECT date, type, price, stockSymbol, shares FROM history WHERE userID = ? ORDER BY date DESC", session.get("user_id"))
    return render_template("history.html", transactions=transactions)

@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    if request.method == "POST":
        symbol = request.form.get("symbol").upper()
        information = lookup(symbol)
        if information != None:
            return render_template("quoted.html", symbol=symbol, company=information["name"], price=round(information["price"], 2))
        return apology("Invalid symbol input")
    return render_template("quote.html")

@app.route("/register", methods=["GET", "POST"])
def register():
    if request.method == "POST":
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")
        if confirmation == password and confirmation != "" and password != "":
            username = request.form.get("username")
            if username != "":
                hash = generate_password_hash(password)
                try:
                    db.execute("INSERT INTO users(username, hash) VALUES (?, ?)", username, hash)
                    return redirect("/login")
                except ValueError:
                    return apology("Username already exist")
            return apology("Invalid username input")
        return apology("Invalid password input")
    return render_template("register.html")

@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    id = session.get("user_id")
    symbols = db.execute("SELECT symbol FROM stocks WHERE userID = ?", id)
    if request.method == "POST":
        symbol = request.form.get("symbol")
        stock = lookup(symbol)
        if stock != None:
            shares = request.form.get("shares")
            try:
                shares = int(float(shares))
                if shares > 0:
                    sharesOwened = db.execute("SELECT amount FROM stocks WHERE symbol = ?", symbol)[0]["amount"]
                    if sharesOwened >= shares:
                        price = round(stock["price"] * shares, 2)
                        dateTime = datetime.now()
                        if sharesOwened != shares:
                            db.execute("UPDATE stocks SET amount = amount - ? WHERE userID = ? AND symbol = ?", shares, id, symbol)
                        else:
                            db.execute("DELETE FROM stocks WHERE userID = ? AND symbol = ?", id, symbol)
                        db.execute("UPDATE users SET cash = cash + ? WHERE id = ?", price, id)
                        db.execute("INSERT INTO history(date, type, price, stockSymbol, userID, shares) VALUES (?, 'sell', ?, ?, ?, ?)", dateTime, price, symbol, id, shares)
                        return redirect("/")
            except ValueError:
                pass
            return apology("Invalid shares input", 4004)
        return apology("Invalid symbol input")
    return render_template("sell.html", symbols=symbols)
