#include <stdio.h>
#include <stdbool.h>

#define V 5 // Düğüm sayısı

// --- BFS için Kuyruk (Queue) Yapısı ---
int queue[V];
int front = -1, rear = -1;

void enqueue(int item) {
    if (rear == V - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = item;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

// --- Algoritmalar ---

// 1. DFS (Recursive/Özyinelemeli)
void DFS(int graph[V][V], int node, bool visited[]) {
    visited[node] = true;
    printf("%d ", node);

    for (int i = 0; i < V; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            DFS(graph, i, visited);
        }
    }
}

// 2. BFS (Iterative/Kuyruk kullanarak)
void BFS(int graph[V][V], int startNode) {
    bool visited[V] = {false};
    
    visited[startNode] = true;
    enqueue(startNode);

    printf("BFS Siralamasi: ");
    while (front != -1 && front <= rear) {
        int curr = dequeue();
        printf("%d ", curr);

        for (int i = 0; i < V; i++) {
            if (graph[curr][i] == 1 && !visited[i]) {
                visited[i] = true;
                enqueue(i);
            }
        }
    }
    printf("\n");
}

int main() {
    // Örnek Graf (0-1, 0-2, 1-3, 1-4 bağlantıları)
    int graph[V][V] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0}
    };

    bool visitedDFS[V] = {false};

    printf("DFS Siralamasi: ");
    DFS(graph, 0, visitedDFS);
    printf("\n");

    BFS(graph, 0);

    return 0;
}