#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int start, end, time = 0;
    
    // Prompting the user for start size
    do
    {
        int input1 = get_int("Starting Size: ");
        start = input1;
    }
    while (start < 9);
       
    // Prompting the user for end size
    do
    {
        int input2 = get_int("Ending Size: ");	
        end = input2;
    }
    while (end < start);
    
    
    
    // Here I am able to access the variables declared in main, outside while loop.
    while (start < end)
    {
        time = time + 1;
        start = (start) + (start / 3) - (start / 4);
    }
        
    printf("Years: %i\n", time);
    return 0;
}