#include <stdio.h>
#include <stdlib.h>

void printarr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void rotate_subarray(int arr[], int l, int r)
{
    int temp = arr[r];
    for (int j = r; j > l - 1; j--)
    {
        arr[j] = arr[j - 1];
    }
    arr[l] = temp;
}

void separate(int arr[], int n)
{

    int last_neg = -1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            last_neg += 1;
            int temp = arr[i];
            arr[i] = arr[last_neg];
            arr[last_neg] = temp;
            if (i - last_neg >= 2)
                rotate_subarray(arr, last_neg + 1, i);
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
    separate(arr, n);
    printarr(arr, n);
}