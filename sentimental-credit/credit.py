def check(cardNum: str) -> bool:
    result = 0
    length = len(cardNum)
    for x in range(1, length + 1):
        digit = int(cardNum[length - x])
        if x % 2 == 0:
            digit *= 2
            result += digit // 10 + digit % 10
        else:
            result += digit
    if result % 10 == 0:
        return True
    return False

def type(cardNum: str) -> str:
    length: int = len(cardNum)
    first: str = cardNum[:2]
    if length == 16:
        if int(first) >= 51 and int(first) <= 55:
            return "MASTERCARD"
        elif first[0] == "4":
            return "VISA"
        else:
            print("INVALID")
    elif length == 15:
        if first == "34" or first == "37":
            return "AMEX"
        else:
            return "INVALID"
    elif length == 13:
        if first[0] == "4":
            return "VISA"
        else:
            return "INVALID"
    else:
        return "INVALID"

def main() -> None:
    cardNum: str = input("What's the card number? ")
    if check(cardNum):
        print(type(cardNum))
    else:
        print("INVALID")

if __name__ == '__main__':
    main()
