#include <stdio.h>
#include <stdlib.h>

void printmatrix(int **mat, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int **transform_matrix(int **matrix, int m, int n)
{
    int *mid = (int *)malloc(m * n * sizeof(int));
    int *transform = (int *)malloc(m * n * sizeof(int));
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mid[count] = matrix[i][j];
            count++;
        }
    }
    int sum = 0;
    for (int k = 0; k < m * n; k++)
    {
        sum += mid[k];
        transform[k] = sum;
    }
    count = 0;
    int **result = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
    {
        result[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
        {
            result[i][j] = transform[count];
            count++;
        }
    }
    free(mid);
    free(transform);
    return result;
}

int main()
{
    int m, n;
    int ri, ci, rh, ch;
    scanf("%d %d", &m, &n);
    int **a = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
    {
        a[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    scanf("%d %d %d %d", &ri, &ci, &rh, &ch);
    int **b = transform_matrix(a, m, n);
    printmatrix(b, m, n);
    int sum = 0;
    if ((ri + rh - 1 <= m) && (ci + ch - 1 <= n))
    {
        for (int i = ri; i < ri + rh; i++)
        {
            for (int j = ci; j < ci + ch; j++)
            {
                sum += b[i][j];
            }
        }
        printf("%d", sum);
    }
    else
        printf("NOT POSSIBLE");
    free(a);
    free(b);
    return 0;
}