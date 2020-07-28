#include <stdio.h>
#include <cs50.h>
#include <string.h>     // 'strlen()'
#include <math.h>       // 'round()'
#include <ctype.h>      // 'isupper()', 'islower()'

int countLetters();
int countWords();
int countSentences();
int getGradeLevel();
string printGradeLevel();

int main(void)
{
    string bookText = get_string("Text: ");

    int numLetters = countLetters(bookText);
    int numSentences = countSentences(bookText);
    int numWords = countWords(bookText);

    int gradeLevel = getGradeLevel(numLetters, numSentences, numWords);

    printGradeLevel(gradeLevel);
}









int countLetters(string bookText)
{
    int letters = 0;
    int i;
    for (i = 0; i < strlen(bookText); i++)
    {
        if ((islower(bookText[i]) != 0) || (isupper(bookText[i]) != 0))
        {
            letters++;
        }
    }
    return letters;
}

int countWords(string bookText)
{
    int spaces = 1;
    int i;
    for (i = 0; i < strlen(bookText); i++)
    {
        if (isspace(bookText[i]) != 0)
        {
            spaces++;
        }
    }
    return spaces;
}

int countSentences(string bookText)
{
    int sentences = 0;
    int i;
    for (i = 0; i < strlen(bookText); i++)
    {
        if ((bookText[i] == 46) || (bookText[i] == 33) || (bookText[i] == 63)) // variable name better than number
        {
            sentences++;
        }
    }
    return sentences;
}

int getGradeLevel(int numLetters, int numSentences, int numWords)
{
    float W = numWords;
    // L = average number of letters per 100 words
    float L = (((float) numLetters / (float)W) * 100);
    // S = average number of sentences per 100 words
    float S = ((float)((numSentences / (float)W) * 100));
    // g = 0.0588 * L - 0.296 * S - 15.8
    float grade = round((float)0.0588 * (float)L - (float)0.296 * (float)S - (float)15.8);
    return grade;
}

string printGradeLevel(int gradeLevel)
{
    if (gradeLevel < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (gradeLevel > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", gradeLevel);
    }
    return 0;
}