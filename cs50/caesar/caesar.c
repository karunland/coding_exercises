#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int i;
    for (i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int a = atoi(argv[1]);

    string mtext = get_string("Plaintext: ");

    printf("Ciphertext: ");

    for (i = 0; i < strlen(mtext); i++)
    {
        if (isupper(mtext[i]))
        {
            printf("%c", (mtext[i] - 65 + a) % 26 + 65);
        }
        else if (islower(mtext[i]))
        {
            printf("%c", (mtext[i] - 97 + a) % 26 + 97);
        }
        else
        {
            printf("%c", mtext[i]);
        }
    }

    printf("\n");
    return 0;
}