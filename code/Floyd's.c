Program:
#include <stdio.h>
#define INF 99999
#define MAX_V 20
void floydWarshall(int graph[MAX_V][MAX_V], int V) {
    int dist[MAX_V][MAX_V], i, j, k;
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    printf("Shortest distances between every pair of vertices:\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int V, i, j;
    int graph[MAX_V][MAX_V];
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    if (V > MAX_V) {
        printf("Vertex count too high. Max %d\n", MAX_V);
        return 1;
    }
    printf("Enter adjacency matrix (use %d for no edge/infinity):\n", INF);
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    floydWarshall(graph, V);
    return 0;
}
