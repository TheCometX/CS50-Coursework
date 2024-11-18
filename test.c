char letters = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    string text = get_string("plaintext: ");
    for (int y = 0; y < 25; y++) {
        char letter = (argv[2])[y];
        if (isalpha(letter) && isdigit(letter) != false) {
            for (int x = 0; x < 25; x++) {
                char letter2 = letters[x];
                int times = 1;
                if (letter == letter2) {
                    if (times == 1) {
                        printf("%c", toupper(letter))
                    }
                    else {
                        printf("%c", letter)
                    }
                }
            }
        }
    }
