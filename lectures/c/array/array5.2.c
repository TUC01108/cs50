#include <stdio.h>

int main(void)
{
    int n;
    printf("How many elements will you use?\n");
    scanf("%d", &n);
    int element[n];
    int i;
    printf("Input %d elements into the array.\n", n);
    for (i = 0; i < n; i++)
    {
        printf("element - %d : ", i);
        scanf("%d", &element[i]);
    }
    int j, k, m = 0;
    // Check before the current element and check after
    printf("Total number of duplicate elements found in the array is : ");
    for (i = 0; i < n - 1; i++)
    {
        // Check element before current element
        for (j = 0; j < i - 1; j++)
        {
            if (element[i] == element[j])
            {
                m++;
            }
        }
        // Check element after current element
        for (k = i + 1; k < n; k++)
        {
            if (element[i] == element[k])
            {
                m++;
            }
        }
    }
    printf("%2d\n", m);
}
// 3 elements
// 5 1 1
// i = 0
// i at element[0] = 5
// j = 0
// j not < i
// k = 1
// k at element[1] = 1
// not equal
// k = 2
// k at element[2] = 1
// not equal
// i = 1
// i at element[1] = 1
// j not < i - 1        // j = 0
                        // j at element[0] = 5
                        // not equal
                        // j = 1
                        // j not < i
// k = 2
// k at element[2] = 1
// equal, m = 1
// i = 2
// i at element[2] = 1
// j = 0
// j at element[0] = 5
// not equal
// j not < i - 1        // j = 1
                        // j at element[1] = 1
                        // equal, m = 2
                        // j = 2
                        // j not < i
// k = 3
// k not < n


// 4 elements
// 1  1  5  5
//[0][1][2][3]
// n = 4
// m = 0

// i = 0
// i < n - 1
// i at element[0] = 1
// j is not < i - 1
// k = 1
// k at element[1] = 1
// equal, m = 1
// k = 2
// k at element[2] = 5
// not equal
// k = 3
// k at element[3] = 5
// not equal
// k not < n
// i = 1
// i at element[1] = 1
// j = 0
// j not < i - 1        // j at element[0] = 1
                        // equal, m = 2
// k = 2
// k at element[2] = 5
// not equal
// k = 3
// k at element[3] = 5
// not equal
// k not < n
// i = 2
// i at element[2] = 5
// j = 0
// j at element[0] = 1
// not equal
// j = 1
// j not < i - 1
// k = 3
// k at element[3] = 5
// equal, m = 2
// k not < n


// at i = 0 we dont check before
// at i = 1 we check before and after
// at i = 2