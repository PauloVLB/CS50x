#include <cs50.h>
#include <stdio.h>

int get_height(void);

int main(void)
{
    int height =  get_height();     // Get the height
    
    for (int i = 1; i <= height; i++)
    {
        for (int j = 1; j <= height; j++)
        {
            if ((i + j) > height) 
            {
                printf("#");     // Every time i + j is bigger than the height, prints #
            }
            else
            { 
                printf(" ");   // Otherwise, prints a space
            }
        }
        printf("\n");   // Go to the next line
    }
}

int get_height(void)
{
    int h;
    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);  // Condition to don't let the height be bigger than 8 or smaller than 1

    return h;
}