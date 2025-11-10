//AIM:8	Write a program which accepts undirected graph and a starting node,
// determine the lengths of the shortest paths from the starting node to all other nodes in the graph.
// If a node is unreachable, its distance is -1. Nodes will be numbered consecutively from 1 to n, and edges will have varying distances or lengths.
// Find the sub tree using Dijikstra algorithm.	
//ROLL NO.102
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 1000

int adj[MAX_NODES][MAX_NODES]; // Adjacency matrix
int visited[MAX_NODES];
int distance[MAX_NODES];

void bfs(int start, int n) {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        distance[i] = -1;
    }

    int queue[MAX_NODES], front = 0, rear = 0;
    queue[rear++] = start;
    visited[start] = 1;
    distance[start] = 0;

    while (front < rear) {
        int current = queue[front++];
        for (int i = 0; i < n; i++) {
            if (adj[current][i] && !visited[i]) {
                visited[i] = 1;
                distance[i] = distance[current] + 1;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    int n, e;
    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &n, &e);

    // Initialize adjacency matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("Enter %d edges (u v):\n", e);
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // Undirected graph
    }

    int start;
    printf("Enter starting node: ");
    scanf("%d", &start);

    bfs(start, n);
printf("Shortest distances from node %d:\n", start);
    for (int i = 0; i < n; i++) {
        printf("Node %d: %d\n", i, distance[i]);
    }

    return 0;
}