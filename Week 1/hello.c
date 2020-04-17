#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("What is your name?\n"); // Get the name of the user
    printf("hello, %s\n", name); // Say hello to the user
}