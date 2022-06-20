#include <stdio.h>
#include <string.h>

// gcc write2file.c -o write2file && ./write2file words.txt

int main(int argc, char *argv[])
{
    FILE *fl;
    char val[50];
    int i, j = 0;

    if (fl == NULL)
    {
        return -1;
    }

    fl = fopen(argv[1], "a+");

    do
    {
        gets(val);
        fprintf(fl, "%s\n", val);
    } while (strlen(val));

    fclose(fl);
    return 0;
}