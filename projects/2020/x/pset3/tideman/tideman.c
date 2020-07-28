#include <cs50.h>
#include <stdio.h>
#include <string.h>

void bubbleSortMax();
void mergeSort();
void merge();
bool isCycle();

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

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

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
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // for first place vote
    for (int i = 0; i < candidate_count; i++)
    {
        if (ranks[0] == i)
        {
            for (int j = 0; j < candidate_count; j++)
            {
                if (j != ranks[0])
                {
                    preferences[i][j]++;
                }
            }
        }
    }
    // for second place vote
    for (int i = 0; i < candidate_count; i++)
    {
        if (ranks[1] == i)
        {
            for (int j = 0; j < candidate_count; j++)
            {
                if (j != ranks[1] && j != ranks[0])
                {
                    preferences[i][j]++;
                }
            }
        }
    }

    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // Check first row
    for (int i = 0; i < candidate_count - 1; i++)
    {
        int n = i + 1;
        int cntr = n;
        for (int j = n; cntr < candidate_count; j++)
        {

            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
            else if (preferences[i][j] < preferences[j][i])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count++;
            }
            cntr++;
        }
    }
    /*
    // Check last pair
    for (int i = 1; i < candidate_count - 1; i++)
    {
        for (int j = 1; j < candidate_count; j++)
        {

            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
            else if (preferences[i][j] < preferences[j][i])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count++;
            }
        }
    }*/
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    int sorted[pair_count];
    int pairsAgain = 0;
    for (int i = 0; i < candidate_count - 1; i++)
    {
        int n = i + 1;
        int cntr = n;
        for (int j = n; j <= candidate_count - 1; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                if (preferences[i][j] - preferences[j][i] > 0)
                {
                    sorted[pairsAgain] = preferences[i][j] - preferences[j][i];
                    pairsAgain++;
                }
            }
            else if (preferences[i][j] < preferences[j][i])
            {
                if (preferences[i][j] - preferences[j][i] < 0)
                {
                    sorted[pairsAgain] = preferences[j][i] - preferences[i][j];
                    pairsAgain++;
                }
            }
            cntr++;
        }
    }
    //mergeSort(sorted,0,pair_count - 1);
    bubbleSortMax(sorted);
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        if (!isCycle(pairs[i].loser, pairs[i].winner))
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    int i;
    for (i = 0; i < candidate_count; i++)
    {
        bool pointing = false;
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][i] == true)
            {
                pointing = true;
                break;
            }
        }
        if (!pointing)
        {
            printf("%s\n", candidates[i]);
            return;
        }
    }

    return;
}

bool isCycle(int b, int a)
{
    if (b == a) // if (locked[b][a])
    {
        return true;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[b][i]) //if (locked[i][a] == true && isCycle(i,b))
        {
            if (isCycle(i, a))
            {
                return true;
            }
        }
    }
    return false;
}

void mergeSort(int sorted[], int left, int right)
{
    int mid;
    if (left < right)
    {
        mid = (left + right) / 2;
        // Sort first half
        mergeSort(sorted, left, mid);
        // Sort second half
        mergeSort(sorted, mid + 1, right);
        // Merge the sorted halves together
        merge(sorted, left, mid, mid + 1, right);
    }
}

void merge(int sorted[], int counter11, int counter12, int counter22, int counter21)
{
    int temp_sorted[pair_count];
    int c1, c2, c3, temp1 = 0, temp2 = 0;
    c1 = counter11;
    c2 = counter22;
    c3 = 0;
    while (c1 <= counter12 && c2 <= counter21)
    {
        if (sorted[c1] > sorted[c2])
        {
            temp1 = pairs[c3].winner;
            temp2 = pairs[c3].loser;
            pairs[c3].winner = pairs[c1].winner;
            pairs[c3].loser = pairs[c1].loser;
            pairs[c1].winner = temp1;
            pairs[c1].loser = temp2;

            temp_sorted[c3++] = sorted[c1++];
        }
        else
        {
            temp1 = pairs[c3].winner;
            temp2 = pairs[c3].loser;
            pairs[c3].winner = pairs[c2].winner;
            pairs[c3].loser = pairs[c2].loser;
            pairs[c2].winner = temp1;
            pairs[c2].loser = temp2;

            temp_sorted[c3++] = sorted[c2++];
        }
    }
    while (c1 <= counter12)
    {

        temp1 = pairs[c3].winner;
        temp2 = pairs[c3].loser;
        pairs[c3].winner = pairs[c1].winner;
        pairs[c3].loser = pairs[c1].loser;
        pairs[c1].winner = temp1;
        pairs[c1].loser = temp2;

        temp_sorted[c3++] = sorted[c1++];
    }
    while (c2 <= counter21)
    {
        temp1 = pairs[c3].winner;
        temp2 = pairs[c3].loser;
        pairs[c3].winner = pairs[c2].winner;
        pairs[c3].loser = pairs[c2].loser;
        pairs[c2].winner = temp1;
        pairs[c2].loser = temp2;

        temp_sorted[c3++] = sorted[c2++];
    }
    for (c1 = counter11, c2 = 0; c1 <= counter21; c1++, c2++)
    {
        sorted[c1] = temp_sorted[c2];
    }
}

void bubbleSortMax(int sorted[])
{
    int i, j, temp = 0, temp1 = 0, temp2 = 0;
    // Sort in descending order
    for (i = 0; i < pair_count - 1; i++)
    {
        for (j = i + 1; j < pair_count; j++)
        {
            if (sorted[i] < sorted[j]) // 1 0 2 1 //
            {
                temp1 = pairs[i].winner;
                temp2 = pairs[i].loser;
                pairs[i].winner = pairs[j].winner;
                pairs[i].loser = pairs[j].loser;
                pairs[j].winner = temp1;
                pairs[j].loser = temp2;
                temp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = temp;
            }
        }
    }
}