#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    char arr[] = "Hello World";
    char *ptr = arr;
    // while (*ptr != '\0')
    // {
    //     printf("%c", *ptr);
    //     ptr++;
    // }
    // print first arg with loop
    char arra[3] = "11a";
    int a = isdigit(arra);printf("%d\n", a);
    for (int i = 0; argv[1][i]; i++)
    {
        printf("%c", argv[1][i]+ atoi(argv[2]));
    }

    

    return 0;
}