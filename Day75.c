// Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.
#include <stdio.h>

int main() {
    int n;

    // Input size of array
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    printf("Enter elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = 0, max_len = 0;

    int index[1000];
    
    // Initialize index array with -1
    for(int i = 0; i < 1000; i++)
        index[i] = -1;

    for(int i = 0; i < n; i++) {
        sum += arr[i];

        if(sum == 0)
            max_len = i + 1;

        if(index[sum + 500] != -1) {
            int len = i - index[sum + 500];
            if(len > max_len)
                max_len = len;
        } else {
            index[sum + 500] = i;
        }
    }

    printf("Length of longest zero sum subarray: %d\n", max_len);

    return 0;
}