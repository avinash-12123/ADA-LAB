#include <stdio.h>
#include <time.h>
int max(int a , int b)
{
    return (a > b) ? a : b;
}
void knapsack(int n, int W, int wt[], int val[], int table[n+1][W+1])
{
    for(int i = 0; i <= n; i++)
        table[i][0] = 0;
    for(int j = 0; j <= W; j++)
        table[0][j] = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= W; j++)
        {
            if(j < wt[i-1])
                table[i][j] = table[i-1][j];
            else
                table[i][j] = max(table[i-1][j],
                                  val[i-1] + table[i-1][j - wt[i-1]]);
        }
    }
}
void printResult(int n , int W , int table[n+1][W+1])
{
    printf("\nDP Table:\n\n");
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= W; j++)
        {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
    printf("\nMaximum profit = %d\n", table[n][W]);
}
int main()
{
    int n, W;
    printf("Enter number of items: ");
    scanf("%d", &n);
    int wt[n], val[n];
    printf("Enter the weights:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &wt[i]);
    printf("Enter the values:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &val[i]);
    printf("Enter knapsack capacity: ");
    scanf("%d", &W);
    int table[n+1][W+1];
    clock_t start, end;
    start = clock();
    knapsack(n, W, wt, val, table);
    end = clock();
    printResult(n, W, table);
    double time_taken = ((double)(end - start) / CLOCKS_PER_SEC);
    printf("\nTime Taken = %.6f seconds\n", time_taken);
    return 0;
}
