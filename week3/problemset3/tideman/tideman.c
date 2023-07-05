#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

typedef struct
{
    int prefnum;
    int pairnum;
}
sortpair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];
sortpair sortpairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;        //ranks[rank] records the number that stands for the candidate
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = (i + 1); j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]] += 1;    //update preferences by rank. Count every candidates ranked after the candidate with rank 0, 1, 2...   
            //printf("preference[%i][%i]: %i\n", ranks[i], ranks[j], preferences[ranks[i]][ranks[j]]);
        }   
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{   
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if ((preferences[i][j] != 0) 
                && (i != j) 
                && (preferences[i][j] > preferences[j][i]))     //only count winning pairs where i is preferred to j
            {   
                pairs[pair_count].winner = i;   //record i, j in preference with pairs and count pair_count, starting from 0.
                pairs[pair_count].loser = j;    //here the order of pair_count is not sorted.
                //printf("pairs[%i].winner = %i\n", pair_count, pairs[pair_count].winner);
                //printf("pairs[%i].loser = %i\n", pair_count, pairs[pair_count].loser);
                sortpairs[pair_count].pairnum = pair_count;
                sortpairs[pair_count].prefnum = preferences[pairs[pair_count].winner][pairs[pair_count].loser];
                //printf("sortpairs[%i].pairnum = %i\n", pair_count, sortpairs[pair_count].pairnum);
                //printf("sortpairs[%i].prefnum = %i\n", pair_count, sortpairs[pair_count].prefnum);
                pair_count += 1;
                //printf("\n");
            }
        }
    }   
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    int k = 0;
    for (int i = 0; i < pair_count; i++)
    {   
        //find maximum preference number for each loop
        int max = 0;
        for (int j = i; j < pair_count; j++)
        {
            if (sortpairs[j].prefnum > max)
            {
                max = sortpairs[j].prefnum;     
            }
        }
        //printf("the %ith max number: %i\n", i + 1, max);
        //printf("\n");
        int temppref;
        int temppair;
        if (sortpairs[i].prefnum == max)
        {   
            //swap values
            temppref = sortpairs[k].prefnum;    
            temppair = sortpairs[k].pairnum;

            sortpairs[k].prefnum = sortpairs[i].prefnum;
            sortpairs[k].pairnum = sortpairs[i].pairnum;

            sortpairs[i].prefnum = temppref;
            sortpairs[i].pairnum = temppair;
            
            //printf("sorted order:\n");
            //printf("sortpairs[%i].prefnum = %i\n", k, sortpairs[k].prefnum);
            //printf("sortpairs[%i].pairnum = %i\n", k, sortpairs[k].pairnum);
            k++;
            //printf("\n");
        }
    }

    for (int i = 0; i < pair_count; i++)
    {
        pair temppair;
        temppair = pairs[i];
        pairs[i] = pairs[sortpairs[i].pairnum];
        pairs[sortpairs[i].pairnum] = temppair;
        //printf("pairs[%i].winner = %i\n", i, pairs[i].winner);
        //printf("pairs[%i].loser = %i\n", i, pairs[i].loser);
    }
    
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {   
        if (pairs[pair_count - 1].loser == pairs[0].winner)
        {
            locked[pairs[pair_count - 1].winner][pairs[0].winner] = false;
            //printf("locked[%i][%i]: false\n", pairs[pair_count].winner, pairs[0].winner);
        }
        else
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
            printf("locked[%i][%i]: true\n", pairs[i].winner, pairs[i].loser);
        }
    }
    return;
}


// Print the winner of the election
void print_winner(void)
{
    int i, j;
    for (i = 0; i < candidate_count; i ++)
    {
        for (j = 0; j < candidate_count; j++)
        {
            if (locked[pairs[i].winner][pairs[i].loser] == true && 
                locked[pairs[j].winner][pairs[i].winner] == false)
            {
                
                break;
            } 
        }
    }
    return;
}