// write hello world program in c
#include <stdio.h>

int main()
{
    char *name = "harun korkmaz";
    int i = 0;
    while(*(name + i) != '\0')
    {
        printf("%c", *(name + i));
        i++;
    }   
    
    printf("\n");
    
    return 0;
}