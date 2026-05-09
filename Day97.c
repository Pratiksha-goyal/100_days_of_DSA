// Given meeting intervals, find minimum number of rooms required.
#include <stdio.h>
#include <stdlib.h>

struct Interval {
    int start;
    int end;
};

int compare(const void* a, const void* b) {
    struct Interval* x = (struct Interval*)a;
    struct Interval* y = (struct Interval*)b;

    return x->start - y->start;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapInsert(int heap[], int* size, int value) {
    int i = (*size)++;
    heap[i] = value;

    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapify(int heap[], int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;

    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, size, smallest);
    }
}

int extractMin(int heap[], int* size) {
    int root = heap[0];

    heap[0] = heap[--(*size)];

    heapify(heap, *size, 0);

    return root;
}

int main() {
    int n;

    printf("Enter number of meetings:\n");
    scanf("%d", &n);

    struct Interval meetings[n];

    printf("Enter start and end times:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &meetings[i].start, &meetings[i].end);
    }

    qsort(meetings, n, sizeof(struct Interval), compare);

    int heap[n];
    int heapSize = 0;

    heapInsert(heap, &heapSize, meetings[0].end);

    for (int i = 1; i < n; i++) {

        if (meetings[i].start >= heap[0]) {
            extractMin(heap, &heapSize);
        }

        heapInsert(heap, &heapSize, meetings[i].end);
    }

    printf("Minimum meeting rooms required: %d\n", heapSize);

    return 0;
}