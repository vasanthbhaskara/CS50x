#include <stdio.h>
#include <math.h>

int countdigits(long digits);
void extracter(long check, int digitnumber, long extracterbox[]);

int main(void)
{
    int evensum, oddsum = 0;
    int f, g = 0;
    long number;
    printf("Number: ");
    scanf("%ld", &number);
    int noofdts = countdigits(number);
    long digitbox[noofdts];

    extracter(number, noofdts, digitbox);


    for (int j = 1; j <= (noofdts / 2); j++)
    {

        evensum = evensum + 2 * digitbox[(2 * j) - 1];


        f = (int)((2 * digitbox[(2 * j) - 1]) % 100);

        if (f >= 10)
        {
            evensum = evensum - 2 * digitbox[(2 * j) - 1] + (((2 * digitbox[(2 * j) - 1]) % 10) + 1);
        }

    }


    for (int k = 1; k <= ((noofdts + 1) / 2); k++)
    {
        oddsum = oddsum + digitbox[(2 * (k - 1))];


    }


    if (((evensum + oddsum) % 10) == 0)

    {
        if (noofdts == 15 && (((long)(number / pow(10, noofdts - 2)) == 34) ||
                              ((long)(number / pow(10, noofdts - 2)) == 37)))

        {
            printf("AMEX\n");
        }


        else if ((noofdts == 16 || noofdts == 13) && (long)(number / pow(10, noofdts - 1)) == 4)
        {
            printf("VISA\n");

        }

        else if ((noofdts == 16) && (((long)(number / pow(10, noofdts - 2)) == 51)
                                     || ((long)(number / pow(10, noofdts - 2)) == 52)
                                     || ((long)(number / pow(10, noofdts - 2)) == 53) || ((long)(number / pow(10, noofdts - 2)) == 54)
                                     || ((long)(number / pow(10, noofdts - 2)) == 55)))
        {
            printf("MASTERCARD\n");

        }

        else
        {
            printf("INVALID\n");
        }
    }

    else
    {
        printf("INVALID\n");

    }

}


int countdigits(long digits)
{
    int counter = 0;
    while (digits != 0)
    {
        digits /= 10;
        counter++;
    }

    return counter;
}

void extracter(long check, int digitnumber, long extracterbox[])
{

    int i = 0;

    while (check != 0)
    {
        extracterbox[i] = check % 10;
        i++;
        check /= 10;

    }

}