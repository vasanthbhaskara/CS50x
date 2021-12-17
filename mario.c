#include <stdio.h>
#include <cs50.h>

void brick(int k); // Prototyping
void dot(int z);   // Prototyping

int main(void)
{
    int p;
    
    do
    {
        p = get_int("Height: ");
    }
    while (p > 8 || p < 1);

    for (int a = 1; a < p + 1; a++)
    {
        dot(p - a);
        brick(a);
        printf("\n");
        
    }

}

void brick(int k) // Printing k number of bricks
{
    for (int j = 0; j < k; j++)
    {
        printf("#");
    }

}

void dot(int z) // Printing z number of dots
{
    for (int e = 0; e < z; e++) 
    {
        printf(" ");
    }


}
