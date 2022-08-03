#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("What's your name? "); // ask name for user
    printf("hello, %s\n", name);    // get user name from terminal

    return (0); // return successfull
}