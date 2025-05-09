def main() -> None:
    text: str = input("Enter the text")
    words: int = get_words(text)
    sentences: int = get_sentences(text)
    letters: int = get_letters(text)
    grade: int = get_grade(words=words, sentences=sentences, letters=letters)
    if grade < 1:
        print("Before Grade 1")
    elif grade > 1 and grade < 16:
        print(f"Grade {grade}")
    else:
        print("Grade 16+")

def get_grade(words: int, sentences: int, letters: int) -> str:
    grade: int = round(0.0588 * (letters/words * 100) - 0.296 * (sentences/words * 100) - 15.8)
    return grade

def get_words(text: str) -> int:
    return text.count(" ") + 1

def get_sentences(text: str) -> int:
    return text.count(".") + text.count("?") + text.count("!")

def get_letters(text: str) -> int:
    letters: int = 0
    for letter in text:
        if letter.isalpha():
            letters += 1
    return letters

if __name__ == "__main__":
    main()
