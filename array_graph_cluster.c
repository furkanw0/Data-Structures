#include <stdio.h>
#include <stdbool.h>

#define V 6 // Düğüm (Vertex) sayısı

// DFS ile küme elemanlarını bulan fonksiyon
void DFS(int graph[V][V], int node, bool visited[]) {
    visited[node] = true;
    printf("%d ", node); // Küme elemanını yazdır

    for (int i = 0; i < V; i++) {
        // Eğer komşuluk varsa (1 ise) ve daha önce ziyaret edilmemişse
        if (graph[node][i] == 1 && !visited[i]) {
            DFS(graph, i, visited);
        }
    }
}

void findClusters(int graph[V][V]) {
    bool visited[V];
    // Başlangıçta tüm düğümleri ziyaret edilmedi (false) olarak işaretle
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    int clusterCount = 0;
    printf("Graf Cluster'lari:\n");

    for (int i = 0; i < V; i++) {
        // Eğer düğüm henüz bir kümeye dahil edilmemişse yeni bir cluster başlat
        if (!visited[i]) {
            clusterCount++;
            printf("Cluster %d: ", clusterCount);
            DFS(graph, i, visited);
            printf("\n");
        }
    }
    printf("\nToplam Cluster Sayisi: %d\n", clusterCount);
}

int main() {
    /* Örnek Adjacency Matrix (Komşuluk Matrisi)
       Düğümler: 0, 1, 2, 3, 4, 5
       Küme 1: 0-1-2
       Küme 2: 3-4
       Küme 3: 5 (Yalnız düğüm)
    */
    int graph[V][V] = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0},
        {1, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0}
    };

    findClusters(graph);

    return 0;
}