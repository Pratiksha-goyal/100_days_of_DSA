// Implement linear search to find key k in an array. Count and display the number of comparisons performed.
#include <stdio.h>

int main() 
{
    int n, k;
    int found = 0, index = -1;
    int comparisons = 0;

    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &k);

    for (int i = 0; i < n; i++) 
    {
        comparisons++;
        if (arr[i] == k) 
        {
            found = 1;
            index = i;
            break;
        }
    }

    if (found) 
    {
        printf("Found at index %d\n", index);
    } 
    else 
    {
        printf("Not Found\n");
    }

    printf("Comparisons = %d\n", comparisons);

    return 0;
}