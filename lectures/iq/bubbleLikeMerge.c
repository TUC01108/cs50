#include <stdio.h>
#include <cs50.h>

void mergeSort();
void merge();
void bubbleSortMax();

// Max number of candidates
#define MAX 9

int pair_count = 4;


// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

pair pairs[MAX * (MAX - 1) / 2];

typedef struct
{
    int winner;
    int loser;
}
bubble;

bubble bubbles[MAX * (MAX - 1) / 2];

int main(void)
{

    int sorted[] = {1,0,2,1};
    int sorted2[] = {1,0,2,1};

    for (int i = 0; i < pair_count; i++)
    {
        if (i == 0)
        {
            pairs[i].winner = 0;
            pairs[i].loser = 1;
            bubbles[i].winner = 0;
            bubbles[i].loser = 1;
        }
        if (i == 1)
        {
            pairs[i].winner = 2;
            pairs[i].loser = 0;
            bubbles[i].winner = 2;
            bubbles[i].loser = 0;
        }
        if (i == 2)
        {
            pairs[i].winner = 2;
            pairs[i].loser = 1;
            bubbles[i].winner = 2;
            bubbles[i].loser = 1;
        }
        if (i == 3)
        {
            pairs[i].winner = 3;
            pairs[i].loser = 1;
            bubbles[i].winner = 3;
            bubbles[i].loser = 1;
        }
    }


    mergeSort(sorted,0,pair_count - 1); // sends in sorted array{1,0,2}, 0, 2
    bubbleSortMax(sorted2);
    printf("\nmerge: ");
    for (int i = 0; i < pair_count; i++)
    {
        printf("[%d, %d]", pairs[i].winner, pairs[i].loser);
    }
    printf("\nbubble: ");
    for (int i = 0; i < pair_count; i++)
    {
        printf("[%d, %d]", bubbles[i].winner, bubbles[i].loser);
    }
    printf("\n");
}

void mergeSort(int sorted[],int left,int right)
{
    int mid;
    if(left<right)
    {
        mid=(left+right)/2;
        // Sort first half
        mergeSort(sorted,left,mid);
        // Sort second half
        mergeSort(sorted,mid+1,right);
        // Merge the sorted halves together
        merge(sorted,left,mid,mid+1,right);
    }
}

void merge(int sorted[],int counter11,int counter12,int counter22,int counter21)
{
    int temp_sorted[pair_count];
    int c1,c2,c3, temp1 = 0, temp2 = 0;
    c1=counter11;
    c2=counter22;
    c3=0;
    while(c1<=counter12 && c2<=counter21)
    {
        if(sorted[c1]>sorted[c2])
        {
        temp1 = pairs[c3].winner;
        temp2 = pairs[c3].loser;
        pairs[c3].winner = pairs[c1].winner;
        pairs[c3].loser = pairs[c1].loser;
        pairs[c1].winner = temp1;
        pairs[c1].loser = temp2;


        temp_sorted[c3++]=sorted[c1++];
        }
        else
        {
        temp1 = pairs[c3].winner;
        temp2 = pairs[c3].loser;
        pairs[c3].winner = pairs[c2].winner;
        pairs[c3].loser = pairs[c2].loser;
        pairs[c2].winner = temp1;
        pairs[c2].loser = temp2;

        temp_sorted[c3++]=sorted[c2++];
        }
    }
    while(c1<=counter12)
    {
        temp1 = pairs[c3].winner;
        temp2 = pairs[c3].loser;
        pairs[c3].winner = pairs[c1].winner;
        pairs[c3].loser = pairs[c1].loser;
        pairs[c1].winner = temp1;
        pairs[c1].loser = temp2;

        temp_sorted[c3++]=sorted[c1++];
    }
    while(c2<=counter21)
    {
        temp1 = pairs[c3].winner;
        temp2 = pairs[c3].loser;
        pairs[c3].winner = pairs[c2].winner;
        pairs[c3].loser = pairs[c2].loser;
        pairs[c2].winner = temp1;
        pairs[c2].loser = temp2;

        temp_sorted[c3++]=sorted[c2++];
    }
    for(c1=counter11,c2=0;c1<=counter21;c1++,c2++) // for(c1=counter11,c2=0;c1<=counter21;c1++,c2++)
    {
        sorted[c1]=temp_sorted[c2];
        printf("%d ", sorted[c1]);
        printf("c1-%d,c2-%d\n", c1, c2);
    }
}

/*
pair pairs starts as {{0,1},{2,0},{2,1},{3,1}
sorted array 1 0 2 1
left = 0
right = pair_count - 1 = 3
if 0 < 3
mid = (0+3)/2 = 1.5 = 1
        // Sort first half
        mergeSort(sorted,0,1);
        // Sort second half
        mergeSort(sorted,2,1);
        // Merge the sorted halves together
        merge(sorted,0,1,2,1);
         while(c1<=counter12 && c2<=counter21) // c1 = 0, counter12 = 1, c2 = 2, counter21 = 1 NO
        {
        }
        else
        {
        }
    }
    while(c1<=counter12) // 0<=1
    {
        temp1 = pairs[c3].winner; // pairs[0].winner // pairs[1].winner
        temp2 = pairs[c3].loser; // pairs[0].loser // pairs[1].loser
        pairs[c3].winner = pairs[c1].winner; // pairs[0].winner = pairs[0].winner now pairs[0].winner = 0
        pairs[c3].loser = pairs[c1].loser; // pairs[0].loser = pairs[0].loser now pairs[0].loser = 1
        pairs[c1].winner = temp1; // pairs[0].winner = 0 // pairs[1].winner = 2
        pairs[c1].loser = temp2; // pairs[0].loser = 1 // pairs[1].loser = 0

        temp_sorted[c3++]=sorted[c1++]; temp[0] = sorted[0] = 1 c3 =1 c1 = 1
    }
    while(c2<=counter21)
    {
        temp1 = pairs[c3].winner;
        temp2 = pairs[c3].loser;
        pairs[c3].winner = pairs[c2].winner;
        pairs[c3].loser = pairs[c2].loser;
        pairs[c2].winner = temp1;
        pairs[c2].loser = temp2;

        temp_sorted[c3++]=sorted[c2++];
    }
    for(c1=counter11,c2=pair_count - 1;c1<=counter21;c1++,c2--) // {2,0}{0,1}
    {
        sorted[c1]=temp_sorted[c2];
    }
SORT LEFT
mergeSort(sorted,0,1);
if 0 < 1
mid = (0+1)/2 = 0

NOT if 0 < 0

SORT RIGHT mergeSort(sorted,2,3);

MERGE

if sorted[0] = 1 < sorted[1] = 0
if sorted[0] = 1 < sorted[2] = 2 sorted[0] now = 2 sorted[2] now = 1
bubbles[0].winner = 0 for bubbles[2].winner = 2 and bubbles[0].loser = 1 for bubbles[2].loser = 1
bubbles is now {{2,1},{2,0},{0,1},{3,1}
2 0 1 1

*/

// sorting from most to least
void bubbleSortMax(int sorted2[])
{
    int i, j, temp = 0, temp1 = 0, temp2 = 0;
    // Sort in descending order
    for (i = 0; i < pair_count - 1; i++)
    {
        for (j = i + 1; j < pair_count; j++)
        {
            if (sorted2[i] < sorted2[j]) // 1 0 2 1 //
            {
                temp1 = bubbles[i].winner;
                temp2 = bubbles[i].loser;
                bubbles[i].winner = bubbles[j].winner;
                bubbles[i].loser = bubbles[j].loser;
                bubbles[j].winner = temp1;
                bubbles[j].loser = temp2;
                temp = sorted2[i];
                sorted2[i] = sorted2[j];
                sorted2[j] = temp;
            }
        }
    }
}
/*
bubbles array starts as {{0,1},{2,0},{2,1},{3,1}
1 0 2 1
if sorted[0] = 1 < sorted[1] = 0
if sorted[0] = 1 < sorted[2] = 2 sorted[0] now = 2 sorted[2] now = 1
bubbles[0].winner = 0 for bubbles[2].winner = 2 and bubbles[0].loser = 1 for bubbles[2].loser = 1
bubbles is now {{2,1},{2,0},{0,1},{3,1}
2 0 1 1
if sorted[0] = 2 < sorted[3] = 1
i = 1
if sorted[1] = 0 < sorted[2] = 1 sorted[1] now = 1 sorted[2] now = 0
bubbles[1].winner = 2 for bubbles[2].winner = 0 and bubbles[1].loser = 0 for bubbles[2].loser = 1
bubbles is now {{2,1},{0,1},{2,0},{3,1}
2 1 0 1
if sorted[1] = 2 < sorted[3] = 1
i = 2
if sorted[2] = 0 < sorted[3] = 1 sorted[2] now = 1 sorted[3] now = 0
bubbles[2].winner = 2 for bubbles[3].winner = 3 and bubbles[2].loser = 0 for bubbles[3].loser = 1
bubbles is now {{2,1},{0,1},{3,1},{2,0}
2 1 1 0


*/