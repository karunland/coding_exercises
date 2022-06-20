#include <stdio.h>

// gcc copyfile2.c -o copyfile2 && ./copyfile2 copyfile2.c  newwords.txt

int main(int argc, char *argv[])
{
    FILE *p1, *p2;
    if (argc > 2)
    {
        printf("f1: %s f2: %s\n", argv[1], argv[2]);
    }

    p1 = fopen(argv[1], "r");
    p2 = fopen(argv[2], "a");

    char temp;

    while ((temp = getc(p1)) != EOF)
    {
        putchar(temp); // To screen
        putc(temp, p2);
    }
    fclose(p1);
    fclose(p2);
    return 0;
}