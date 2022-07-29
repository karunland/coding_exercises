#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("argc < 1 \n");
        return -1;
    }

    printf("file is:%s %s\n ", __FILE__, argv[1]);
    // puts(argv[1]);

    // bubble sort arguments
    for (int i = 1; i < argc; i++)
    {
        for (int j = i + 1; j < argc; j++)
        {
            // if (strcmp(argv[i], argv[j]) > 0)
            int temp2 = atoi(argv[i]);
            int temp3 = atoi(argv[j]);

            if (temp2 > temp3)
            {
                char *temp = argv[i];
                argv[i] = argv[j];
                argv[j] = temp;
            }
        }
    }
    // print arguments
    for (int i = 1; i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }

    return 0;
}