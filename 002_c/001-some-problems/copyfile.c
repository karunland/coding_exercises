#include <stdio.h>

// gcc copyfile.c -o copyfile && ./copyfile copyfile.c  newwords.txt

void main(int argc, char *argv[])
{
    FILE *p1, *p2;
    if (argc > 2)
    {
        printf("f1: %s f2: %s\n", argv[1], argv[2]);
    }

    p1 = fopen(argv[1], "r");
    p2 = fopen(argv[2], "w");

    char temp;

    while (1)
    {
        temp = getc(p1);
        if (feof(p1))
        {
            break;
        }
        putc(temp, p2);
    }

    fclose(p1);
    fclose(p2);
}