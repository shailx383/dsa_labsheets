#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool f(int arr[], int len, int sum)
{
    static int flag = 0;
    if (sum == 0)
    {
        flag = 1;
        return 1;
    }
    if (len == 0 && sum != 0)
        return 0;
    if (flag == 1)
        return 1;
    else
    {
        bool a = f(arr, len - 1, sum - arr[len - 1]);
        bool b = f(arr, len - 1, sum);
        if (a)
        {
            printf("%d ", len - 1);
        }
        return a || b;
    }
}

void printarr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            printf("%d ", i);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int sum;
    scanf("%d", &sum);
    bool result = f(arr, n, sum);
    if (result)
    {
        exit(0);
    }
    else
        printf("NOT POSSIBLE");
}