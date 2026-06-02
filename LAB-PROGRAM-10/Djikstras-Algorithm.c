#include <stdio.h>
void main() {
    int c[100][100], s[100], dist[100], v, n, u;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter cost matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &c[i][j]);
            if(c[i][j] == 0 && i != j)
                c[i][j] = 999;
        }
    }
    printf("Enter source vertex: ");
    scanf("%d", &v);
    for(int i = 0; i < n; i++) {
        s[i] = 0;
        dist[i] = c[v][i];
    }
    s[v] = 1;
    dist[v] = 0;
    for(int w = 0; w < n - 1; w++) {
        int min = 999;
        u = -1;
        for(int i = 0; i < n; i++) {
            if(s[i] == 0 && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }
        if(u == -1) break;
        s[u] = 1;
        for(int k = 0; k < n; k++) {
            if(s[k] == 0 && dist[k] > dist[u] + c[u][k]) {
                dist[k] = dist[u] + c[u][k];
            }
        }
    }
    printf("\nShortest distances:\n");
    for(int i = 0; i < n; i++) {
        printf("dist[%d] = %d\n", i, dist[i]);
    }
}
