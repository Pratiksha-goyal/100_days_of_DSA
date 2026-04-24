// Given a sorted array of integers and a target value x, implement the Lower Bound and Upper Bound operations using Binary Search.
#include <stdio.h>

int lowerBound(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    int ans = n;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] >= x) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return ans;
}

int upperBound(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    int ans = n;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] > x) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return ans;
}

int main() {
    int n;

    printf("Enter size of array:\n");
    scanf("%d", &n);

    int arr[n];

    printf("Enter sorted array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int x;
    printf("Enter target value:\n");
    scanf("%d", &x);

    int lb = lowerBound(arr, n, x);
    int ub = upperBound(arr, n, x);

    printf("%d %d\n", lb, ub);

    return 0;
}