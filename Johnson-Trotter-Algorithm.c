#include <stdio.h>
#define LEFT -1
#define RIGHT 1
int getMobileIndex(int a[], int dir[], int n)
{
    int mobile = 0;
    int mobileIndex = -1;
    for(int i = 0; i < n; i++)
    {
        if(dir[a[i]] == LEFT && i != 0)
        {
            if(a[i] > a[i - 1] && a[i] > mobile)
            {
                mobile = a[i];
                mobileIndex = i;
            }
        }
        if(dir[a[i]] == RIGHT && i != n - 1)
        {
            if(a[i] > a[i + 1] && a[i] > mobile)
            {
                mobile = a[i];
                mobileIndex = i;
            }
        }
    }
    return mobileIndex;
}

void print(int a[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void johnsonTrotter(int n)
{
    int a[n];
    int dir[n + 1];
    for(int i = 0; i < n; i++)
        a[i] = i + 1;
    for(int i = 1; i <= n; i++)
        dir[i] = LEFT;
    print(a, n);
    while(1)
    {
        int mobileIndex = getMobileIndex(a, dir, n);
        if(mobileIndex == -1)
            break;
        int mobile = a[mobileIndex];
        if(dir[mobile] == LEFT)
        {
            int temp = a[mobileIndex];
            a[mobileIndex] = a[mobileIndex - 1];
            a[mobileIndex - 1] = temp;
            mobileIndex--;
        }
        else
        {
            int temp = a[mobileIndex];
            a[mobileIndex] = a[mobileIndex + 1];
            a[mobileIndex + 1] = temp;
            mobileIndex++;
        }
        for(int i = 0; i < n; i++)
        {
            if(a[i] > mobile)
                dir[a[i]] *= -1;
        }
        print(a, n);
    }
}
int main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    johnsonTrotter(n);
    return 0;
}
