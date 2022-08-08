
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello, World!\n");

    int *list = malloc (3 * sizeof(int));
    list[0] = 1;
    list[1] = 15;
    list[2] = 3;

    int *list2 = malloc (4 * sizeof(int));
    for (int i = 0; i < 3; i++)
    {
        list2[i] = list[i];
    }
    
    list2[3] = 4;
    free(list);
    list = list2;

    for (int i = 0; i < 4; i++)
    {
        printf("%d\n", list[i]);
    }
    free(list2);
    return 0;
}