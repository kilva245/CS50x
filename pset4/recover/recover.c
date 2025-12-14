#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover card.raw\n");
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    uint8_t buffer[BLOCK_SIZE];
    FILE *output = NULL;

    int file_count = 0;
    char filename[8];
    bool found_jpeg = false;

    // Read blocks
    while (fread(buffer, BLOCK_SIZE, 1, input) == 1)
    {
        bool is_jpeg = buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
                       (buffer[3] & 0xf0) == 0xe0;

        if (is_jpeg)
        {
            if (found_jpeg)
            {
                fclose(output);
            }

            sprintf(filename, "%03i.jpg", file_count);
            output = fopen(filename, "w");
            file_count++;
            found_jpeg = true;
        }

        if (found_jpeg)
        {
            fwrite(buffer, BLOCK_SIZE, 1, output);
        }
    }

    if (output != NULL)
    {
        fclose(output);
    }

    fclose(input);
    return 0;
}
