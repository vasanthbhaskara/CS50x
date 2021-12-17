#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(char word[]);

int main(void)
{
    char word1[50], word2[50];
    // Get input words from both players
    printf("Player 1: ");
    scanf("%s", word1);
    printf("Player 2: ");
    scanf("%s", word2);

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie\n");
    }


}

int compute_score(char word[])
{
    int result[50];
    int n = strlen(word);
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        int ascii = (int)(toupper(word[i]));
        if (ascii >= 65 && ascii <= 90)
        {
            result[i] = POINTS[ascii - 65];
        }

        else
        {
            result[i] = 0;
        }


    }

    for (int j = 0; j < n; j++)
    {
        total = total + result[j];
    }

    return total;


}