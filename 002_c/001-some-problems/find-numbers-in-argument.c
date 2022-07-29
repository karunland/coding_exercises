#include <stdio.h>
#include <string.h>

int *SayiBul(char *);
void SayiSirala(int *);

// gcc find-numbers-in-argument.c -o find-numbers-in-argument && ./find-numbers-in-argument arg120h45015a4

int main(int argc, char *argv[])
{
    char p[] = "12harun15";
    int numbers[30] = {0};
    int *number;
    number = numbers;
    number = SayiBul(argv[1]);

    SayiSirala(number);
    for (int i = 0; i < sizeof(p); i++)
    {
        if (number[i] != 0)
            printf("%d\n", number[i]);
    }

    char messsagep[10] = "harun";

    return 0;
}

int *SayiBul(char *buff)
{
    int i = 0, j = 0, k = 0, size = strlen(buff);

    static int result[20] = {0};

    while (buff[i])
    {
        if (buff[i] <= '9' && buff[i] >= '0')
        {
            result[k] *= 10;
            result[k] += buff[i] - 48;
        }
        else
            k++;
        i++;
    }

    return result;
}

void SayiSirala(int *arr)
{
    int temp = 0, i = 0;
    for (; i < sizeof(arr);)
    {
        for (int j = 0; j < i;)
        {
            // sort
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            j++;
        }
        i++;
    }
}
