// Implement push and pop operations on a stack and verify stack operations.
#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push more elements.\n");
        return;
    }
    stack[++top] = value;
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow! No more elements to pop.\n");
        return;
    }
    top--;
}

int main() {
    int n, m, i, value;

    printf("Enter number of elements to push: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        push(value);
    }

    printf("Enter number of elements to pop: ");
    scanf("%d", &m);

    for (i = 0; i < m; i++) {
        pop();
    }

    if (top == -1) {
        printf("Stack is empty after popping.\n");
    } else {
        printf("Remaining stack elements (Top to Bottom):\n");
        for (i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
    }

    return 0;
}