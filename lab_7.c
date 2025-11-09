// AIM:  Consider the undirected graph G, consisting of n nodes laid out in a 3 -by- 3 grid:
// Start searching at node 1, and break ties for exploring the next node based on lower numerical order (i.e. add nodes to a queue low to high, add nodes to a stack high to low). (a) In what order are nodes marked as explored by BFS 
// (b) In what order are nodes marked as explored by DFS?
//Roll no 102

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 9 // Total nodes in a 3x3 grid

 
int graph[N + 1][4]; // Each node can have at most 4 neighbors
int degree[N + 1];   // Degree of each node

// Stack for DFS
int stack[N];
int top = -1;

// Queue for BFS
int queue[N];
int front = 0, rear = 0;

// Visited array
bool visited[N + 1];

// Push to stack
void push(int node) {
    stack[++top] = node;
}

// Pop from stack
int pop() {
    return stack[top--];
}

// Enqueue to queue
void enqueue(int node) {
    queue[rear++] = node;
}

// Dequeue from queue
int dequeue() {
    return queue[front++];
}

// Add edge to the graph
void addEdge(int u, int v) {
    graph[u][degree[u]++] = v;
    graph[v][degree[v]++] = u;
}

 
void sortNeighbors(int node, bool descending) {
    for (int i = 0; i < degree[node] - 1; i++) {
        for (int j = i + 1; j < degree[node]; j++) {
            if ((descending && graph[node][i] < graph[node][j]) ||
                (!descending && graph[node][i] > graph[node][j])) {
                int temp = graph[node][i];
                graph[node][i] = graph[node][j];
                graph[node][j] = temp;
            }
        }
    }
}

// Perform DFS
void dfs(int start) {
    printf("DFS: ");
    push(start);
    visited[start] = true;

    while (top != -1) {
        int node = pop();
        printf("%d ", node);

        // Sort neighbors in descending order for DFS
        sortNeighbors(node, true);

        for (int i = 0; i < degree[node]; i++) {
            int neighbor = graph[node][i];
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                push(neighbor);
            }
        }
    }
    printf("\n");
}

// Perform BFS
void bfs(int start) {
    printf("BFS: ");
    enqueue(start);
    visited[start] = true;

    while (front != rear) {
        int node = dequeue();
        printf("%d ", node);

        // Sort neighbors in ascending order for BFS
        sortNeighbors(node, false);

        for (int i = 0; i < degree[node]; i++) {
            int neighbor = graph[node][i];
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                enqueue(neighbor);
            }
        }
    }
    printf("\n");
}

int main() {
    // Create the 3x3 grid graph
    for (int i = 1; i <= 9; i++) {
        if (i % 3 != 0) addEdge(i, i + 1); // Horizontal edges
        if (i + 3 <= 9) addEdge(i, i + 3); // Vertical edges
    }

    // Perform DFS
    for (int i = 1; i <= N; i++) visited[i] = false;
    dfs(1);

    // Perform BFS
    for (int i = 1; i <= N; i++) visited[i] = false;
    bfs(1);

    return 0;
}
