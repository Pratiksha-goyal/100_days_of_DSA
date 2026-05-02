//Given n boards of different lengths and k painters, each painter paints contiguous boards. Painting a unit length of board takes one unit of time. Determine the minimum time required to paint all boards.

#include <stdio.h>
int isPossible(int arr[], int n, int k, int maxTime) {
    int painters = 1;
    int currTime = 0;

    for (int i = 0; i < n; i++) {
        if (currTime + arr[i] <= maxTime) {
            currTime += arr[i];
        } else {
            painters++;
            currTime = arr[i];

            if (painters > k)
                return 0;
        }
    }
    return 1;
}

int main() {
    int n, k;

    printf("Enter number of boards and painters:\n");
    scanf("%d %d", &n, &k);

    int arr[n];

    printf("Enter board lengths:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max = arr[0], sum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        sum += arr[i];
    }

    int left = max, right = sum;
    int ans = sum;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (isPossible(arr, n, k, mid)) {
            ans = mid;
            right = mid - 1; 
        } else {
            left = mid + 1;
        }
    }

    printf("%d\n", ans);

    return 0;
}