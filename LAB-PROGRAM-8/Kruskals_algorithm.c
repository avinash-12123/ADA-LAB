#include <stdio.h>
#include <time.h>
int set[10];
int getParent(int node) {
    while(set[node] != 0) {
        node = set[node];
    }
    return node;
}
int connect(int x, int y) {
    if(x != y) {
        set[y] = x;
        return 1;
    }
    return 0;
}
int main() {
    int graph[10][10];
    int n;
    int i, j;
    int minCost = 0;
    int edgeCount = 0;
    int a, b;
    int p, q;
    clock_t start, end;
    double time_taken;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if(graph[i][j] == 0) {
                graph[i][j] = 999;
            }
        }
    }
    start = clock();
    printf("\nEdges in Minimum Spanning Tree:\n");
    while(edgeCount < n - 1) {
        int min = 999;
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                if(graph[i][j] < min) {
                    min = graph[i][j];
                    a = p = i;
                    b = q = j;
                }
            }
        }
        p = getParent(p);
        q = getParent(q);
        if(connect(p, q)) {
            printf("%d --> %d  cost = %d\n", a, b, min);
            minCost += min;
            edgeCount++;
        }
        graph[a][b] = graph[b][a] = 999;
    }
    end = clock();
    printf("\nMinimum Cost = %d\n", minCost);
    time_taken = ((double)(end - start) / CLOCKS_PER_SEC) * 1000;
    printf("Time Taken = %f ms\n", time_taken);
    return 0;
}
