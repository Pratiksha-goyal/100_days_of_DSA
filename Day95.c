// Given n real numbers in [0,1), sort using bucket sort algorithm.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    float data;
    struct Node* next;
};

void insertSorted(struct Node** head, float value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL || (*head)->data >= value) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* curr = *head;
    while (curr->next != NULL && curr->next->data < value) {
        curr = curr->next;
    }

    newNode->next = curr->next;
    curr->next = newNode;
}

void bucketSort(float arr[], int n) {
    struct Node* buckets[n];

    for (int i = 0; i < n; i++) {
        buckets[i] = NULL;
    }

    for (int i = 0; i < n; i++) {
        int idx = arr[i] * n;
        insertSorted(&buckets[idx], arr[i]);
    }

    int k = 0;

    for (int i = 0; i < n; i++) {
        struct Node* temp = buckets[i];

        while (temp != NULL) {
            arr[k++] = temp->data;
            temp = temp->next;
        }
    }
}

int main() {
    int n;

    printf("Enter number of elements:\n");
    scanf("%d", &n);

    float arr[n];

    printf("Enter elements in range [0,1):\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    bucketSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }

    return 0;
}