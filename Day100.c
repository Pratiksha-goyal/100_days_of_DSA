// For each element, count how many smaller elements appear on right side. Use merge sort technique or Fenwick Tree (BIT).
#include <stdio.h>
#include <stdlib.h>

struct Pair {
    int value;
    int index;
};

void merge(struct Pair arr[], int left, int mid, int right,
           int counts[], struct Pair temp[]) {

    int i = left;
    int j = mid + 1;
    int k = left;

    int rightCount = 0;

    while (i <= mid && j <= right) {

        // Right element is smaller
        if (arr[j].value < arr[i].value) {
            temp[k++] = arr[j++];
            rightCount++;
        }
        else {
            // Add smaller right elements count
            counts[arr[i].index] += rightCount;
            temp[k++] = arr[i++];
        }
    }

    // Remaining left elements
    while (i <= mid) {
        counts[arr[i].index] += rightCount;
        temp[k++] = arr[i++];
    }

    // Remaining right elements
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy back
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

void mergeSort(struct Pair arr[], int left, int right,
               int counts[], struct Pair temp[]) {

    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid, counts, temp);
    mergeSort(arr, mid + 1, right, counts, temp);

    merge(arr, left, mid, right, counts, temp);
}

int main() {
    int n;

    printf("Enter number of elements:\n");
    scanf("%d", &n);

    int nums[n];
    struct Pair arr[n], temp[n];
    int counts[n];

    printf("Enter elements:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);

        arr[i].value = nums[i];
        arr[i].index = i;

        counts[i] = 0;
    }

    mergeSort(arr, 0, n - 1, counts, temp);

    printf("Count of smaller elements on right:\n");

    for (int i = 0; i < n; i++) {
        printf("%d ", counts[i]);
    }

    return 0;
}