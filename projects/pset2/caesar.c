#include <stdio.h>
#include <cs50.h>
#include <string.h>     // 'strlen()'
#include <ctype.h>      // 'isdigit()', 'ispunct()', 'isspace()'
#include <stdlib.h>     // 'atoi()'

bool isInputCorrect();
bool isAsciiDigit();
string cipherText();
void addEncryptionKeyToText();

int main(int argc, string argv[])
{
    if (!isInputCorrect(argc, argv))
    {
        return 1;
    }

    int encryption_key = atoi(argv[1]) % 26;

    string text = get_string("plaintext: ");

    addEncryptionKeyToText(text, encryption_key);
}









bool isInputCorrect(int argc, string argv[])
{
    // If command line arguments is anything but 2 then provide user with correct input format
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return false;
    }
    // If input is not a numeric ascii digit from 0-9
    if (!isAsciiDigit(argv))
    {
        return false;
    }
    return true;
}

bool isAsciiDigit(string argv[])
{
    int i;
    for (i = 0; i < strlen(argv[1]); i++)
    {
        // Only accept ascii values from 0 to 9
        if (isdigit(argv[1][i]) == 0)
        {
            return false;
        }
    }
    return true;
}

string cipherText(string text, int encryption_key)
{
    int i;
    for (i = 0; i < strlen(text); i++)
    {
        // Check for non-ascii letters and digits
        if ((ispunct(text[i]) != 0) || (isspace(text[i]) != 0))
        {
            // Print original text's punctuations and spaces
            text[i] = text[i];
        }
        // Check for values greater than lowercase 'z'
        else if (text[i] + encryption_key > 122)
        {
            text[i] = ((text[i] + encryption_key) - 26);
        }
        // Else print as is with encryption key
        else
        {
            text[i] = text[i] + encryption_key;
        }
    }
    return text;
}

void addEncryptionKeyToText(string text, int encryption_key)
{
    printf("ciphertext: %s\n", cipherText(text, encryption_key));
}