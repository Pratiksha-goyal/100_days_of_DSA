// Find shortest distances from source vertex in a weighted graph with non-negative weights.
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1000

typedef struct {
    int vertex;
    int dist;
} Node;

Node heap[MAX];
int size = 0;

void swap(Node *a, Node *b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int i) {
    while (i > 0 && heap[(i - 1) / 2].dist > heap[i].dist) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapifyDown(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left].dist < heap[smallest].dist)
        smallest = left;
    if (right < size && heap[right].dist < heap[smallest].dist)
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

void push(int v, int d) {
    heap[size].vertex = v;
    heap[size].dist = d;
    heapifyUp(size);
    size++;
}

Node pop() {
    Node root = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
    return root;
}

typedef struct Edge {
    int v, w;
    struct Edge* next;
} Edge;

Edge* adj[MAX];

void addEdge(int u, int v, int w) {
    Edge* e1 = (Edge*)malloc(sizeof(Edge));
    e1->v = v; e1->w = w;
    e1->next = adj[u];
    adj[u] = e1;

    Edge* e2 = (Edge*)malloc(sizeof(Edge));
    e2->v = u; e2->w = w;
    e2->next = adj[v];
    adj[v] = e2;
}

void dijkstra(int n, int src) {
    int dist[MAX];

    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;
    push(src, 0);

    while (size > 0) {
        Node curr = pop();
        int u = curr.vertex;
        int d = curr.dist;

        if (d > dist[u]) continue;

        Edge* temp = adj[u];
        while (temp != NULL) {
            int v = temp->v;
            int w = temp->w;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(v, dist[v]);
            }

            temp = temp->next;
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }
    printf("\n");
}

int main() {
    int n, m, u, v, w, src;

    printf("Enter number of vertices and edges:\n");
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
        adj[i] = NULL;

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < m; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    printf("Enter source vertex:\n");
    scanf("%d", &src);

    printf("Shortest distances:\n");
    dijkstra(n, src);

    return 0;
}