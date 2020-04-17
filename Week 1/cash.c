#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void) 
{
    float value;
    do
    {
        value = get_float("Change owed: ");
    }
    while (value < 0); // prompts the users to a non-negative value

    int cents = round(value * 100); // turn to a integer
    int quarters = cents / 25;
    cents %= 25;
    int dimes = cents / 10;
    cents %= 10;
    int nickels = cents / 5;
    cents %= 5;
    int pennies = cents / 1;

    printf("%i\n", (quarters + dimes + nickels + pennies)); // count the coins

}