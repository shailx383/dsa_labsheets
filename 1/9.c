#include <stdio.h>
#include <stdlib.h>

void main()
{
    int k, n;
    printf("Enter k: ");
    scanf("%d", &k);
    printf("Enter n: ");
    scanf("%d", &n);
    int A[n];
    printf("Enter elements of A: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    int mid = (1 + k) / 2;

    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            int temp;
            if (A[i] > mid && A[i + 1] <= mid)
            {
                temp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = temp;
            }
            else if (A[i] < mid && A[i - 1] >= mid)
            {
                temp = A[i - 1];
                A[i - 1] = A[i];
                A[i] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
}