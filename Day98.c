// Given intervals, merge all overlapping ones.
#include <stdio.h>
#include <stdlib.h>

struct Interval {
    int start;
    int end;
};

// Compare function for sorting
int compare(const void* a, const void* b) {
    struct Interval* x = (struct Interval*)a;
    struct Interval* y = (struct Interval*)b;

    return x->start - y->start;
}

int main() {
    int n;

    printf("Enter number of intervals:\n");
    scanf("%d", &n);

    struct Interval arr[n];

    printf("Enter intervals (start end):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    // Sort intervals
    qsort(arr, n, sizeof(struct Interval), compare);

    // Merge intervals
    struct Interval result[n];
    int idx = 0;

    result[idx] = arr[0];

    for (int i = 1; i < n; i++) {

        // Overlapping intervals
        if (arr[i].start <= result[idx].end) {

            // Merge
            if (arr[i].end > result[idx].end) {
                result[idx].end = arr[i].end;
            }

        } else {
            // Non-overlapping
            idx++;
            result[idx] = arr[i];
        }
    }

    // Print merged intervals
    printf("Merged intervals:\n");

    for (int i = 0; i <= idx; i++) {
        printf("[%d, %d] ", result[i].start, result[i].end);
    }

    return 0;
}
