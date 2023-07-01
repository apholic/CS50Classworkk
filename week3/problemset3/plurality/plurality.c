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
    // Check for invalid usage
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

        // Check for invalid vote
        if (vote(name) == false)
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
    int m;
    for (m = 0; m < candidate_count; m++)
    {
        if(strcmp(candidates[m].name, name) == 0)
        {
            candidates[m].votes += 1;
            return true;
            break;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{   
    //sort candidates in the order of vote numbers
    candidate winner[candidate_count];
    for (int i = 0, n = candidate_count; i < n && n > 0; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if (candidates[i].votes < candidates[j].votes )
            {
                winner[i] = candidates[j];
            }
            else if (candidates[i].votes == candidates[j].votes)
            {
                winner[i] = candidates[i];
                winner[i+1] = candidates[j];
            }
            else
            {
                winner[i] = candidates[i];
            }
        }
        n -= 1;
    }

    int i = 0;
    if(winner[i].votes > winner[i + 1].votes)
    {
        printf("%s\n", winner[i].name);
        return;
    }
    while (winner[i].votes == winner[i + 1].votes && i < candidate_count)
    {
        printf("%s\n", winner[i].name);
        printf("%s\n", winner[i + 1].name);
        i++;
    }
}
