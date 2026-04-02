// Build a graph with n vertices and m edges using adjacency matrix representation. The graph may be directed or undirected.

#include <stdio.h>

int main() {
    int n, m, i;
    
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter number of edges: ");
    scanf("%d", &m);
    
    int adj[n][n];
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }
    
    int choice;
    printf("Enter 1 for Directed Graph, 2 for Undirected Graph: ");
    scanf("%d", &choice);
    
    int u, v;
    
    printf("Enter %d edges (u v):\n", m);
    for(i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        
        adj[u][v] = 1;
        
        if(choice == 2) {
            adj[v][u] = 1;
        }
    }
    
    printf("\nAdjacency Matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}