#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <strings.h>
//defining max limit
 int mc = 9;
 int mv = 9;
//defining data structure- candidate
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;
candidate candidates[9];

int candidate_count;
int voter_count;

int preferences[9][9];

bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);
int main(int argc, string argv[])
{
    if (mc < argc - 1)
    {
        printf("Limit Exceeded\n");
        return 1;
    }
    if (1 > argc - 1)
    {
        printf("Usage: runoff [candidates...]\n");
        return 1;
    }

    candidate_count = argc - 1;
    //assigning names to candidates array
    for (int i = 0; i < argc; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }
    //asking for vote count
    voter_count = get_int("Number of voters: ");
    //getting votes in
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", (j + 1));
            if (vote(i, j, name) == false)
            {
                printf("Invalid vote.\n");
                //j--;
            }
        }
        printf("\n");
    }
    int min = find_min();
    do
    {
        tabulate();
        if (print_winner() == true)
        {
            return 0;
        }

        if (is_tie(min) == true)
        {
            printf("Tie\n");
        }
        eliminate(min);
    }
    while ((print_winner() == false) && (is_tie(min) == false));
    return 0;
}


bool vote(int voter, int rank, string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcasecmp(name, candidates[i].name) == 0)
        {
            preferences[voter][rank] = i;
            return true;
        }

    }
    return false;
}

void tabulate(void)
{
    int p = 0;
    for (int i = 0; i < voter_count; i++)
    {

        for (int j = 0; j < candidate_count; j++)
        {

                if (candidates[preferences[i][j]].eliminated == false)
                {
                    candidates[preferences[i][j]].votes++;
                    break;
                }


        }
    }
}



bool print_winner(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        double p = (float) candidates[i].votes / voter_count;
        if((p * 100) > 50)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}


int find_min(void)
{
    int n = 10;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == false)
        {
            if (candidates[i].votes < n)
            {
                n = candidates[i].votes;
            }
        }
    }
    return n;
}

bool is_tie(int min)
{
     for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == false)
        {
            if (candidates[i].votes != min)
            {
                return false;
            }
        }
    }
    return true;
}

void eliminate(int min)
{
     for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == false)
        {
            if (candidates[i].votes == min)
            {
                candidates[i].eliminated = true;
            }
        }
    }
}
//more  than half means win


//if not elimanate the last person
