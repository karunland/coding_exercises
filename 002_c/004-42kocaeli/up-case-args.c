#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// gcc up-case-args.c -o up-case-args && ./up-case-args 'harun KORKMAZ'

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("argc < 1 \n");
        return(-1);
    }

    printf("file is:%s and argumant is \"%s\"\n ", __FILE__, argv[1]);

    puts(argv[1]);
    printf("%lu\n", strlen(argv[1]));

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
        {
            argv[1][i] -= 'a' - 'A';
        }
        else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
        {
            argv[1][i] += 'a' - 'A';
        }
    }
    
    puts(argv[1]);
    return (0);
}