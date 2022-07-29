#include <stdio.h>

enum
{
    N = 3
};

int buf[N];    // N elements circular buffer
int end = 0;   // write index
int start = 0; // read index

void put(int item)
{
    buf[end++] = item;
    end %= N;
}

int get(void)
{
    int item = buf[start++];
    start %= N;
    return item;
}

int main(int argc, char **argv)
{
    int i;
    int g;
    for (int i = 0; i < 20; i++)
    {
        put(i);
        g = get();
    }
    
    return 0;
}