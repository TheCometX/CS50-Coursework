def main() -> None:
    height: int = int(input("What is the height?"))
    for x in range(height - 1, -1, -1):
        spaces: str = " " * x
        stair: str = "#" * (height - x)
        line: str = spaces + stair + "  " + stair
        print(line)

if __name__ == '__main__':
    main()
