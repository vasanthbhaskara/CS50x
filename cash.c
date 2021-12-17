#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void)
{   
    int cents;
    do
    {
        int input = round(100 * get_float("Change owed: "));
        cents = input;
    }
    while (cents < 0);
    
    int try1 = cents / 25;
    cents = cents % 25; // same as cents = cents - try1*25;
    int try2 =  cents / 10;
    cents = cents % 10; // same as cents = cents - try2*10;
    int try3 = cents / 5;
    cents = cents % 5; // same as cents = cents - try2*5;
    int try4 = cents;

    printf("\n%i", try1 + try2 + try3 + try4);
    
}