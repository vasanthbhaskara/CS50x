#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];


// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Checi for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Checi for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes += 1;
            return true;
        }

    }


    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int temp;
    string keep;
    int counter = 404;
    int same = 1;
    // Let's first Sort the data, 5 6 4 3, 3 4 5 6, Use Bubble Sort

    for (int i = 0; i < candidate_count - 1; i++)
    {

        for (int j = 0; j < candidate_count - 1 - i; j++)
        {
            if (candidates[j].votes > candidates[j + 1].votes)
            {
                temp = candidates[j].votes;
                candidates[j].votes = candidates[j + 1].votes;
                candidates[j + 1].votes = temp;
                counter = 0;


                keep = candidates[j].name;
                candidates[j].name = candidates[j + 1].name;
                candidates[j + 1].name = keep;
            }

        }

        if (counter != 0)
        {
            break;
        }

    }



    for (int n = 1; n < candidate_count; n++)
    {
        if (candidates[candidate_count - 1].votes == candidates[candidate_count - 1 - n].votes)
        {
            same++;
        }
    }



    if (same == 1)
    {
        printf("%s\n", candidates[candidate_count - 1].name);
    }

    else
    {
        for (int j = 0; j < same; j++)
        {
            printf("%s\n", candidates[candidate_count - 1 - j].name);
        }
    }







    return;
}
