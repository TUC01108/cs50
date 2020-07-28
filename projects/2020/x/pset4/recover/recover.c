#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdint.h>

#define BUFFERSIZE 512

bool isInputCorrect();
void fixCorruptJPEG();

int main(int argc, char *argv[])
{
    // Open memory card
    FILE *file = fopen(argv[1], "r");

    if (!isInputCorrect(argc, argv, file))
    {
        return 1;
    }

    fixCorruptJPEG(file);

    // Close file
    fclose(file);

    return 0;
}









void fixCorruptJPEG(FILE *file)
{
    // New type to store bytes of data
    typedef uint8_t BYTE;

    // Buffer array
    BYTE buffer[BUFFERSIZE];

    // JPEG counter
    int cntr = 0;

    // File to write to
    FILE *img;
    char filename[8];

    // Repeat until end of card
    // Read 512 bytes into a buffer
    while (fread(&buffer, BUFFERSIZE, 1, file) == 1)
    {
        // If start of new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {

            // If not first JPEG
            if (cntr > 0)
            {
                // Close current file
                fclose(img);

                // Name new file
                sprintf(filename, "%03i.jpg", cntr);
                cntr++;

                // Open new file
                img = fopen(filename, "w");

                // Write to file
                fwrite(&buffer, BUFFERSIZE, 1, img);
            }
            // If first JPEG
            if (cntr == 0)
            {
                // Name new file starting at 000.jpg
                sprintf(filename, "%03i.jpg", cntr);
                cntr++;

                // Open new file
                img = fopen(filename, "w");

                // Write to file
                fwrite(&buffer, BUFFERSIZE, 1, img);
            }
        }
        // If already found JPEG
        else if (cntr > 0)
        {
            // Keep writing to file
            fwrite(&buffer, BUFFERSIZE, 1, img);
        }
    }

    // Close file
    fclose(img);

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