def main() -> None:
    while True:
        try:
            height: int = int(input("Enter a height between 1 and 8: "))
            if height > 8 or height < 1:
                print("Height out of range")
                continue
        except ValueError:
            print("Enter a numeric height")
            continue
        break
    print_stair(height)

def print_stair(height: int) -> None:
    for x in range(1, height + 1):
        print(" " * (height-x) + "#" * x + "  " + "#" * x)

if __name__ == '__main__':
    main()
