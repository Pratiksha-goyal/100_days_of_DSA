// Given a queue of integers, reverse the queue using a stack.
#include <stdio.h>

#define MAX 100

int queue[MAX];
int stack[MAX];
int front = 0, rear = -1;
int top = -1;

void enqueue(int value)
{
    queue[++rear] = value;
}

int dequeue()
{
    return queue[front++];
}

void push(int value)
{
    stack[++top] = value;
}

int pop()
{
    return stack[top--];
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);

    for(int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        enqueue(x);
    }

    while(front <= rear)
    {
        push(dequeue());
    }

    front = 0;
    rear = -1;

    while(top != -1)
    {
        enqueue(pop());
    }

    printf("\nReversed Queue:\n");

    for(int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    return 0;
}