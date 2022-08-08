// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file

    uint8_t buffer[HEADER_SIZE];

    size_t ret = fread(buffer, ARRAY_SIZE(buffer), sizeof(*buffer), input);

    if (ret != sizeof(*buffer))
    {
        fprintf(stderr, "fread() failed: %zu\n", ret);
        exit(EXIT_FAILURE);
    }
    ret = fwrite(buffer, ARRAY_SIZE(buffer), sizeof(*buffer), output);
    if (ret != sizeof(*buffer))
    {
        fprintf(stderr, "fwrite() failed: %zu\n", ret);
        exit(EXIT_FAILURE);
    }
    int16_t mainbuf;

    // make sure that if it's valid
    // for(int i = 0 ;i < 44 ; i++)
    // {
    //     printf("%02x", buffer[i]);
    // }

    while (fread(&mainbuf, sizeof(uint16_t), 1, input))
    {
        mainbuf *= factor;
        fwrite(&mainbuf, sizeof(uint16_t), 1, output);
    }

    // TODO: Read samples from input file and write updated data to output file

    // Close files
    fclose(input);
    fclose(output);
}
