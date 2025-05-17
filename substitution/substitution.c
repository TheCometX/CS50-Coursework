#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    for (int v = 0; v < 26; v++) {
        argv[1][v] = tolower(argv[1][v]);
    }

    for (int z = 0; z < 26; z++)
    {
        char key = argv[1][z];
        if (!isalpha(key))
        {
            printf("Key must contain only letters\n");
            return 1;
        }
        else if (strchr(argv[1], key) != strrchr(argv[1], key))
        {
            printf("Repeating character\n");
            return 1;
        }
    }

    char letters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    string text = get_string("plaintext: ");

    for (int x = 0; x < strlen(text); x++)
    {
        char letter = text[x];
        for (int y = 0; y < 26; y++)
        {
            char alpha = letters[y];
            if (tolower(letter) == alpha)
            {
                if (isupper(letter))
                {
                    text[x] = toupper(argv[1][y]);
                }
                else
                {
                    text[x] = tolower(argv[1][y]);
                }
            }
        }
    }

    printf("ciphertext: %s\n", text);
    return 0;
}
