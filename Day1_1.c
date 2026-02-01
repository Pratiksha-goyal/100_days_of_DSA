#include <stdio.h>

int main() {
    int n, pos, x;
    int arr[100];   // enough size for insertion

    // Input size
    scanf("%d", &n);

    // Input array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input position (1-based)
    scanf("%d", &pos);

    // Input element to insert
    scanf("%d", &x);

    // Shift elements to right
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert element
    arr[pos - 1] = x;

    // Print updated array
    for (int i = 0; i <= n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}