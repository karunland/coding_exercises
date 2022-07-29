#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

// gcc bubble-file.c -o bubble-file && ./bubble-file

int main()
{
    FILE *p;
    p = fopen("numbers.txt", "r");
    int temp = 0;

    unsigned char a;
    int arr[100] = {0}, i = 0;

    while (!feof(p))
    {

        fscanf(p, "%c\n", &a);
        if (a < '0' || a > '9')
            continue;
        arr[i] = (int)a - 48;
        printf("%d\n", arr[i]);
        i++;
    }

    for (i = 0; arr[i]; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] < arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for (i = 0; arr[i]; i++)
    {
        printf("%d", arr[i]);
    }

    fclose(p);
    return 0;
}
