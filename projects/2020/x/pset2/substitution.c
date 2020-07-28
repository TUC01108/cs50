#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
                    // #include <math.h>
                    // #include <stdlib.h>
                    // #include <stdbool.h>

bool isInputCorrect();
void makeEncryptionKey();
bool isUnique();
bool isNonLetter();
int isLetter();
char *cipherText();
void addEncryptionKeyToText();

int main(int argc, string argv[])
{
    if (!isInputCorrect(argc, argv))
    {
        return 1;
    }

    int encryption_key[strlen(argv[1])];

    makeEncryptionKey(argv, encryption_key);

    if (!isUnique(argv, encryption_key))
    {
        return 1;
    }

    string text = get_string("plaintext: ");

    addEncryptionKeyToText(text, encryption_key);
}









bool isInputCorrect(int argc, char *argv[], char *encryption_key)
{
    int i;
    // If command line arguments is anything but 2 then provide user with correct input format
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return false;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return false;
    }

    for (i = 0; i < strlen(argv[1]); i++)
    {
        // Only accept ascii values  A to Z and a to z
        if ((isupper(argv[1][i]) == 0) && (islower(argv[1][i]) == 0))
        {
            return false;
        }
        else
        {
            // If lowercase copy into array with value % 64 - 32
            if ((islower(argv[1][i]) != 0))
            {
                encryption_key[i] = ((int)argv[1][i] % 64) - 32;
            }
            else
            {
                encryption_key[i] = (int)argv[1][i] % 64;
            }
        }
    }
    return true;
}

void makeEncryptionKey(char *argv[], int encryption_key[])
{
    int i;
    for (i = 0; i < strlen(argv[1]); i++)
    {
        // If lowercase copy into array with value % 64 - 32
        if ((islower(argv[1][i]) != 0))
        {
            encryption_key[i] = ((int)argv[1][i] % 64) - 32;
        }
        else
        {
            encryption_key[i] = (int)argv[1][i] % 64;
        }
    }
}

// Function that checks for duplicates in array
bool isUnique(char *argv[], int encryption_key[])
{
    // Check to see if there are duplicate elements in array
    int n = strlen(argv[1]);
    int i, j, k, count, arr2[n];;
    for (i = 0; i < n; i++)
    {
        arr2[i] = -1;
        count = 1;
        // Check duplicate after the current position and
        // increase counter by 1 if found.
        for (j = i + 1; j < n; j++)
        {
            if (encryption_key[i] == encryption_key[j])
            {
                count++;
                arr2[j] = 0;
            }
        }
        if (arr2[i]!=0)
        {
            arr2[i] = count;
        }
    }
    for (i = 0; i < n; i++)
    {
        if (arr2[i] > 1)
        {
            return false;
        }
    }
    return true;
}

bool isNonLetter(string text, int i)
{
    if ((int)text[i] <= 64)
    {
        return true;
    }
    return false;
}

int isLetter(string text, int i)
{
    return ((int)text[i] - 32) % 64;
}

char *cipherText(string text, int encryption_key[])
{
    int i;
    for (i = 0; i < strlen(text); i++)
    {
        // Check for non-ascii letters
        if (isNonLetter(text, i))
        {
            text[i] = text[i];
        }
        // Check for lowercase values
        else if (isLetter(text, i) <= 26)
        {
            text[i] = (int)text[i] + ((int)encryption_key[(isLetter(text, i)) - 1] - (isLetter(text, i)));
        }
        // Check for uppercase values
        else if (((((int)text[i]) % 64) <= 26))
        {
            text[i] = (int)text[i] + ((int)encryption_key[(((int)text[i]) % 64) - 1] - (((int)text[i]) % 64));
        }
        // Else they fall into the correct value print them with the key
        else
        {
            text[i] = (int)text[i] + ((int)encryption_key[(isLetter(text, i)) - 1] - (isLetter(text, i)));
        }
    }
    return text;
}

void addEncryptionKeyToText(string text, int encryption_key[])
{
    printf("ciphertext: %s\n", cipherText(text, encryption_key));
}