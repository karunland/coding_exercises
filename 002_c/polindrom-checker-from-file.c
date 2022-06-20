#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// gcc polindrom-checker-from-file.c -o polindrom-checker-from-file && ./polindrom-checker-from-file polindrom.txt

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("no args\n");
        return 0;
    }

    FILE *p;

    p = fopen(argv[1], "r");
    char temp[100];

    int j, flag;
    while (fscanf(p, "%s\n", temp))
    {
        flag = 0;

        printf("\n%-15s:", temp);
        for (int i = 0; i < strlen(temp); i++)
        {
            if (temp[i] != temp[strlen(temp) - i - 1])
            {
                flag++;
            }
        }
        if (flag < 1)
        {
            printf(" is a polindrom");
        }
        else
        {
            printf(" is not a polindrom");
        }
        if (feof(p))
        {
            break;
        }
    }
    fclose(p);
    return 0;
}
