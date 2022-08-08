#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
// typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }
    // 0xff 0xd8 0xff
    FILE *f = fopen(argv[1], "r");

    if (f == NULL)
    {
        printf("Could not open file\n");
        return 2;
    }

    int c = 0;

    unsigned char buffer[512] = {0};
    FILE *moutput = NULL;

    char *filename = malloc(8 * sizeof(char));

    while (fread(buffer, sizeof(char), 512, f))
    {
        if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && ((buffer[3] & 0xf0) == 0xe0))
        {
            sprintf(filename, "%03i.jpg", c);
            moutput = fopen(filename, "w");
            c++;
        }
        if (moutput != NULL)
        {
            fwrite(buffer, 1, 512, moutput);
        }
    }
    free(filename);
    fclose(moutput);
    fclose(f);

    return 0;
}