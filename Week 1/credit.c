#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long n;
    do
    {
        n = get_long("Number: ");;
    }
    while (n <= 0);
    
    int digits = 0;
    int sum = 0;
    string anwser = "INVALID";
    long copyN = n;
    int startsWith = 0;
    int c = 1;
    while (n)
    {   
        int currentDigit = n % 10; // take the current digit
        sum = (digits % 2 == 0 ? sum + currentDigit : sum + ((currentDigit * 2) % 10) + ((currentDigit * 2) / 
                10));  // adds the correspodent thing to the sum
        n /= 10;

        digits++; // count the digits
        
        
        if (digits >= 14)
        {
            startsWith += currentDigit * c;
            c *= 10;
        }
    }

    bool valid = sum % 10 == 0; // is it valid or not
    
    if (digits == 16) 
    {
        startsWith /= 10; 
    }
    
    if (valid)
    {
        if (digits == 13)
        {
            anwser =  "VISA";
        }
        else if (digits == 15) // amex
        {
            if (startsWith == 34 || startsWith == 37) // cheking amex
            {
                anwser = "AMEX";
            }
        }
        else if (digits == 16) // visa or master
        {
            if (startsWith == 51 || startsWith == 52 || startsWith == 53 || startsWith == 54 || startsWith == 55)
            {
                anwser = "MASTERCARD";
            }
            else if (startsWith / 10 == 4) // looking if starts with 4 to be visa
            {
                anwser = "VISA";
            }
        }
    }

    printf("%s\n", anwser);


}