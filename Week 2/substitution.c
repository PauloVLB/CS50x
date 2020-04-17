#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");  // checks if the user gave different than 2 arguments
        return 1;
    }

    string key = argv[1];   // takes the key to check
    int n = strlen(key);

    if (n != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must have alpha only\n");   // check if the current char of the given key is a alpha
            return 1;
        }
        for (int j = i + 1; j < n; j++)
        {
            if (tolower(key[i]) == tolower(key[j]))
            {
                printf("Key can't have repeated characters\n"); // loops the array to see if the current char is repeated
                return 1;
            }
        }
    }

    string p = get_string("plaintext: ");   // prompts the user
    n = strlen(p);
    char c[n];

    printf("ciphertext: ");
    for (int i = 0; i < n; i++)
    {
        int index = 0;
        if (isalpha(p[i]) && isupper(p[i]))
        {
            index = p[i] - 65;  // take the index to search on the key to upper cases
            c[i] = toupper(key[index]);
        }
        else if (isalpha(p[i]) && islower(p[i]))
        {
            index = p[i] - 97;  // take the index to search on the key to lower cases
            c[i] = tolower(key[index]);
        }
        else
        {
            c[i] = p[i];
        }
        printf("%c", c[i]);
    }
    printf("\n");


    return 0;
}