// Implement Binary Search Iterative - Implement the algorithm.
#include <stdio.h>

int main() {
    int n;

    printf("Enter number of elements:\n");
    scanf("%d", &n);

    int arr[n];

    printf("Enter sorted array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int target;
    printf("Enter target value:\n");
    scanf("%d", &target);

    int left = 0, right = n - 1;
    int index = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            index = mid;
            break;
        } 
        else if (arr[mid] < target) {
            left = mid + 1;
        } 
        else {
            right = mid - 1;
        }
    }

    if (index != -1)
        printf("Element found at index %d\n", index);
    else
        printf("Element not found\n");

    return 0;
}