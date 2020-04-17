#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    string text = get_string("Text: ");
    float l, s;
    int letters = 0;
    int sentences = 0;
    int words = 0;

    for (int i = 0, n = strlen(text); i < n; i++)    // loops the all sentence
    {
        if (isalpha(text[i]))
        {
            letters++;  // count the letters
        }
        if (isspace(text[i]))
        {
            words++;    // count the words
        }
        bool isPeriod = text[i] == 33 || text[i] == 46 || text[i] == 63; // check if the char is ? ! or .
        if (isPeriod)
        {
            sentences++;    // count the sentences
        }
    }

    words++;

    l = (letters * 100) / (float) words;
    s = (sentences * 100) / (float) words;
    float index = 0.0588 * l - 0.296 * s - 15.8;

    index = round(index);

    if (index < 1)
    {
        printf("%s\n", "Before Grade 1");
    }
    else if (index > 16)
    {
        printf("%s\n", "Grade 16+");
    }
    else
    {
        printf("Grade %.0f\n", index);
    }
}