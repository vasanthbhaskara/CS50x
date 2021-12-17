#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
    if (argc == 1)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }


    for (int k = 0, y = strlen(argv[1]); k < y; k++)

    {
        if ((argc > 2 || (argv[1][k] <= 48 || argv[1][k] >= 57)))
        {
            printf("Usage: ./caesar key\n");
            return 0;

        }
    }


    char ptext[100];
    int cscii[100];
    int a;
    char encipher[100];
    int key = atoi(argv[1]);
    printf("plaintext: ");
    scanf("%[^\n]%*c", ptext);

    int n = strlen(ptext);
    for (int i = 0; i < n; i++)
    {

        if (toupper(ptext[i]) >= 65 && toupper(ptext[i]) <= 90)
        {
            if (isupper(ptext[i]))
            {
                cscii[i] = (((ptext[i]) - 65) + key) % 26;
                encipher[i] = cscii[i] + 65;
            }

            else
            {
                cscii[i] = (((ptext[i]) - 97) + key) % 26;
                encipher[i] = cscii[i] + 97;
            }
        }
        else
        {
            encipher[i] = ptext[i];
        }

    }

    encipher[n] = '\0';

    printf("ciphertext: %s\n", encipher);

}