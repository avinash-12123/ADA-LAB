#include <stdio.h>
#include <time.h>
int main() {
    int n, i, j;
    int graph[10][10];
    int visited[10] = {0};
    int edgeCount = 0;
    int totalCost = 0;
    clock_t start, end;
    double time_taken;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);

            if(graph[i][j] == 0 && i != j) {
                graph[i][j] = 999;
            }
        }
    }
    start = clock();
    visited[0] = 1;
    printf("\nEdges selected for MST:\n");
    while(edgeCount < n - 1) {
        int min = 999;
        int x = -1, y = -1;

        for(i = 0; i < n; i++) {
            if(visited[i]) {
                for(j = 0; j < n; j++) {
                    if(!visited[j] && graph[i][j] < min) {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }
        if(x != -1 && y != -1) {
            printf("%d --> %d  cost = %d\n", x, y, min);

            totalCost += min;
            visited[y] = 1;
            edgeCount++;
        }
    }
    end = clock();
    printf("\nMinimum Cost = %d\n", totalCost);
    time_taken = ((double)(end - start) / CLOCKS_PER_SEC) * 1000;
    printf("Time Taken = %f ms\n", time_taken);
    return 0;
}
