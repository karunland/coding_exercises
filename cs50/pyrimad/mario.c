#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int b = 0;

    while (1)
    {
        b = get_int("Enter an int: ");
        if (b < 9 && b > 0)
            break;
    }

    for (int i = 1; i <= b; ++i) // outer loop
    {
        for (int j = i; j < b; j++)
        {
            printf(" ");
        }
        for (int k = 1; k <= i; k++)
        {
            printf("*"); // print the Star
        }
        printf("\n");
    }

    return (0);
}