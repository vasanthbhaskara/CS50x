#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int lettercounter(char texty[]);
int wordcounter(char wordy[]);
int sentencecounter(char senty[]);

int main(void)
{
    float L, S;
    int index, county, wordi, senti;
    char text[1000];
    printf("Text: ");
    scanf("%[^\n]%*c", text);
    county = lettercounter(text);
    wordi = wordcounter(text);
    senti = sentencecounter(text);
    L = ((float)county / wordi) * 100;
    S = ((float)senti / wordi) * 100;
    index = round(0.0588 * L - 0.296 * S - 15.8);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }


}

int lettercounter(char texty[])
{
    int counter = 0;
    for (int i = 0, n = strlen(texty); i < n; i++)
    {
        if (toupper(texty[i]) >= 65 && toupper(texty[i]) <= 90)
        {
            counter = counter + 1;
        }
        else
        {
            continue;
        }

    }

    return counter;
}

int wordcounter(char wordy[])
{
    int counter = 0;
    for (int i = 0, n = strlen(wordy); i < n; i++)
    {
        if (wordy[i] == 32)
        {
            counter = counter + 1;
        }
        else
        {
            continue;
        }

    }

    return counter + 1;
}

int sentencecounter(char senty[])
{
    int counter = 0;
    for (int i = 0, n = strlen(senty); i < n; i++)
    {
        if (senty[i] == 33 || senty[i] == 46 || senty[i] == 63)
        {
            counter = counter + 1;
        }
        else
        {
            continue;
        }

    }

    return counter;
}