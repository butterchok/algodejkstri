#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <locale.h>

#define V 5

int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX;
    int min_index;
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printG(int dist[]) {
    printf("Вершина \t Расстояние от старта");
    char* x = "ABCDE";
    for (int i = 0; i < V; i++)
        printf("%c \t\t %d\n", x[i], dist[i]);
}

void dijkstra(int graph[V][V], int start) {
    int dist[V];
    bool sptSet[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[start] = 0;

    for (int count = 0; count < V - 1; count++) {

        int u = minDistance(dist, sptSet);

        sptSet[u] = true;

        for (int v = 0; v < V; v++)

            if (!sptSet[v] && graph[u][v]
                && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printG(dist);
}
int main() {
    setlocale(LC_ALL, "Rus");

    int graph[V][V] = {
        {0, 2, 1000, 2, 1000},
        {2, 0, 4, 1000, 2},
        {1000, 4, 0, 2, 1},
        {2, 1000, 2, 0, 7},
        {1000, 2, 1, 7, 0},
    };

    dijkstra(graph, 0);

    return 0;
}