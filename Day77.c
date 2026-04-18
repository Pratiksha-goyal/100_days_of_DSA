// Using BFS or DFS, check if the entire graph is connected.
#include <stdio.h>

#define SIZE 100

int graph[SIZE][SIZE];
int visited[SIZE];

void dfs(int node, int n) {
    visited[node] = 1;

    for (int i = 1; i <= n; i++) {
        if (graph[node][i] == 1 && visited[i] == 0) {
            dfs(i, n);
        }
    }
}

int main() {
    int n, m, u, v;

    int showPrompt = 1;

    if (showPrompt)
        printf("Enter number of nodes and edges:\n");

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
        for (int j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
    }

    if (showPrompt)
        printf("Enter edges (u v):\n");

    for (int i = 0; i < m; i++) {
        if (showPrompt)
            printf("Edge %d: ", i + 1);

        scanf("%d %d", &u, &v);

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    dfs(1, n);

    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            printf("NOT CONNECTED\n");
            return 0;
        }
    }

    printf("CONNECTED\n");

    return 0;
}