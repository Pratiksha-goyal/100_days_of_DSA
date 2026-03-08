// Circular Queue Using Array - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = 0;
int rear = -1;
int size = 0;

void enqueue(int value)
{
    rear = (rear + 1) % MAX;
    queue[rear] = value;
    size++;
}

int dequeue()
{
    int value = queue[front];
    front = (front + 1) % MAX;
    size--;
    return value;
}

void display()
{
    int i = front;

    for(int count = 0; count < size; count++)
    {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX;
    }
}

int main()
{
    int n, m;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++)
    {
        int x;
        scanf("%d",&x);
        enqueue(x);
    }

    printf("Enter number of dequeue operations: ");
    scanf("%d",&m);

    for(int i = 0; i < m; i++)
    {
        int temp = dequeue();
        enqueue(temp);
    }

    display();

    return 0;
}