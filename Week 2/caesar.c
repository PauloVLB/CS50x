#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");    // checks if the user gave less or more arguments than expected
        return 1;
    }

    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");    // checks if the user gave a non-digit number
            return 1;
        }
    }

    int k = atoi(argv[1]);

    string p = get_string("plaintext: ");   // prompts the user for the plaintext
    int n = strlen(p);
    char c[n];

    printf("ciphertext: ");
    for (int i = 0; i < n; i++)
    {
        if (isalpha(p[i]) && islower(p[i]))
        {
            p[i] -= 97; // lower case shift
            c[i] = (p[i] + k) % 26;
            c[i] += 97;
        }
        else if (isalpha(p[i]) && isupper(p[i]))
        {
            p[i] -= 65; // upper case shift
            c[i] = (p[i] + k) % 26; // shifts the char by the key
            c[i] += 65;
        }
        else
        {
            c[i] = p[i];
        }

        printf("%c", c[i]);     // shows the ciphertext
    }
    printf("\n");

    return 0;
}