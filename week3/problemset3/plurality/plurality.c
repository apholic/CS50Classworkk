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
    for (int m = 0; m < candidate_count; m++)
    {
        if (strcmp(candidates[m].name, name) == 0)
        {
            candidates[m].votes += 1;
            //printf("%s: %i\n", candidates[m].name, candidates[m].votes);
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{   
    //find the candidate with maximum number of votes;
    candidate winner[candidate_count];
    winner[0].name = "temp";
    winner[0].votes = 0;
    for (int i = 0, j = 1, n = candidate_count; i < n && j < n; i++)
    {   
        if (candidates[i].votes < 
            winner[0].votes)  //go to the next candidates if their votes are less than the noted maximum number of votes;
        {
            break;
        }
        else if (candidates[i].votes > winner[0].votes)
        {
            winner[0] = candidates[i];
        }
        else
        {
            winner[0 + j] = candidates[i];
            //printf("two winners\n");
            j++;
        }
    }
    
    printf("%s\n", winner[0].name);
    
    for (int i = 0; i < (candidate_count - 1); i++)
    {
        if (winner[i].votes == winner[i + 1].votes)
        {
            printf("%s\n", winner[i + 1].name);
        }
    }

    return;
}
