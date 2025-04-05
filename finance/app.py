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
    stocks = db.execute("SELECT symbol, COUNT(shares), COUNT(price) FROM history WHERE userID = ? GROUP BY symbol", session.get("user_id"))
    print(stocks)
    return render_template("index.html")


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    if request.method == "POST":
        symbol = request.form.get("symbol")
        information = lookup(symbol)
        if information is not None:
            try:
                shares = int(request.form.get("shares"))
                price = information["price"] * shares
                userID = session.get("user_id")
                balance = db.execute("SELECT cash FROM users WHERE id = ?", userID)[0]["cash"]
                if balance > price:
                    balance -= price
                    dateTime = datetime.now()
                    db.execute("UPDATE users SET cash = ? WHERE id = ?", balance, userID)
                    db.execute("INSERT INTO history(shares, price, date, userID, symbol) VALUES (?, ?, ?, ?, ?)", shares, price, dateTime, userID, symbol)
                    return redirect("/")
            except ValueError:
                return apology("Invalid number of shares")
        else:
            return apology("Invalid stock's symbol")
    return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


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
        symbol = request.form.get("symbol")
        informations = lookup(symbol)
        name = informations["name"]
        price = informations["price"]
        return render_template("quoted.html", symbol=symbol, name=name, price=price)
    return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")
        if confirmation == password and (confirmation != "" and password != ""):
            username = request.form.get("username")
            hash = generate_password_hash(password)
            if username != "":
                try:
                    db.execute("INSERT INTO users(username, hash) VALUES (?, ?)", username, hash)
                except ValueError:
                    return apology("Username in use")
            else:
                return apology("Invalid username input")
        else:
            return apology("Invalid password input")
    return render_template("register.html")

@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    return apology("TODO")
