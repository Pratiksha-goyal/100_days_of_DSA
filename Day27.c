// Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);

    if(head == NULL)
        return newNode;

    struct Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

struct Node* findIntersection(struct Node* head1, struct Node* head2) {

    struct Node* ptr1 = head1;

    while(ptr1 != NULL) {
        struct Node* ptr2 = head2;

        while(ptr2 != NULL) {
            if(ptr1->data == ptr2->data)
                return ptr1;

            ptr2 = ptr2->next;
        }

        ptr1 = ptr1->next;
    }

    return NULL;
}

int main() {

    int n, m, value;
    struct Node *head1 = NULL, *head2 = NULL;

    printf("Enter number of elements in first list: ");
    scanf("%d", &n);

    printf("Enter elements of first list:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &value);
        head1 = insertEnd(head1, value);
    }

    printf("Enter number of elements in second list: ");
    scanf("%d", &m);

    printf("Enter elements of second list:\n");
    for(int i = 0; i < m; i++) {
        scanf("%d", &value);
        head2 = insertEnd(head2, value);
    }

    struct Node* intersection = findIntersection(head1, head2);

    if(intersection != NULL)
        printf("Intersection point value: %d\n", intersection->data);
    else
        printf("No Intersection\n");

    return 0;
}

