#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *p;
    int c;
    char val[50];
    if (argc < 2)
    {
        printf("argc < 1 \n");
        return -1;
    }
    printf("file name is %s\n", argv[1]);

    p = fopen(argv[1], "r");

    while (!(feof(p)))
    {
        fscanf(p, "%s ", val);
        printf("%s \n", val);
    }

    fclose(p);
    return 0;
}