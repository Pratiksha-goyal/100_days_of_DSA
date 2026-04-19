// Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.
#include <stdio.h>

#define SIZE 100
#define INF 999999

int graph[SIZE][SIZE];
int visited[SIZE];

int main() {
    int n, m;
    int u, v, w;

    printf("Enter number of nodes and edges:\n");
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
        for (int j = 1; j <= n; j++) {
            graph[i][j] = INF;
        }
    }

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < m; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &u, &v, &w);

        graph[u][v] = w;
        graph[v][u] = w; 
    }

    int totalWeight = 0;
    visited[1] = 1; 

    for (int count = 1; count < n; count++) {
        int min = INF;
        int x = -1, y = -1;

        for (int i = 1; i <= n; i++) {
            if (visited[i]) {
                for (int j = 1; j <= n; j++) {
                    if (!visited[j] && graph[i][j] < min) {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        if (x != -1 && y != -1) {
            printf("Selected edge: %d - %d (weight %d)\n", x, y, graph[x][y]);
            totalWeight += graph[x][y];
            visited[y] = 1;
        }
    }

    printf("\nTotal weight of MST: %d\n", totalWeight);

    return 0;
}