#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#define BUFFERSIZE 512

bool isInputCorrect();
void findLostJpegs();

int main(int argc, char *argv[])
{
    // Open memory card
    FILE *file = fopen(argv[1], "r");

    if (!isInputCorrect(argc, argv, file))
    {
        return 1;
    }

    findLostJpegs(file);

    // Close file
    fclose(file);

    return 0;
}









void findLostJpegs(FILE *file)
{
    // Buffer array
    unsigned char buffer[BUFFERSIZE];

    // File to write to
    FILE *image;
    char jpegname[8];

    // JPEG counter
    int cntr = 0;


    // Repeat until end of card
    // Read 512 bytes into a buffer
    while (fread(buffer, BUFFERSIZE, 1, file) == 1)
    {
        // If start of new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // If not first JPEG
            if (cntr > 0)
            {
                // Close current file
                fclose(image);

            }
            // Name new file
            sprintf(jpegname, "%03i.jpg", cntr);

            // Open new file
            image = fopen(jpegname, "w");

            cntr++;
        }
        if (cntr > 0)
        {
        // Write to file
        fwrite(buffer, BUFFERSIZE, 1, image);
        }
    }

    // Close file
    fclose(image);

}

bool isInputCorrect(int argc, char *argv[], FILE *file)
{
    // If command line arguments is anything besides 1 then provide user with correct input format
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return false;
    }
    // If the forensic image cannot be opened for reading, your program should inform the user as much, and main should return 1
    if (file == NULL)
    {
        printf("Could not open image.\n");
        return false;
    }
    return true;
}