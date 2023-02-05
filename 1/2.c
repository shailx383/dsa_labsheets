#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int *getColumn(int **a, int m, int n, int index)
{
    int *column = (int *)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++)
    {
        column[i] = a[i][index];
    }
    return column
}

bool isSubmatrix(int **a, int **b, m, n, p, q)
{
    for (int i = 0; i < m; i++)
    {
        int b_row_num = 0;
        while (b_row_num < p)
        {
            for (int j = 0; j < n; j++)
            {
                int b_col_num = 0;
                while (b_col_num < q)
                {
                    if (a[i][j] == b[b_row_num][b_col_num])
                    {
                    }
                }
            }
        }
    }
}

int main()
{
    int m, n, p, q;
    scanf("%d %d", &m, &n);
    int **a = = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
    {
        a[i] = (int *)malloc(n * sizeof(int));
        for
            int(j = 0; j < n; j++)
            {
                scanf("%d", &a[i][j]);
            }
    }
    scanf("%d %d", &p, &q);
    int **b = = (int **)malloc(p * sizeof(int *));
    for (int i = 0; i < p; i++)
    {
        b[i] = (int *)malloc(q * sizeof(int));
        for
            int(j = 0; j < q; j++)
            {
                scanf("%d", &b[i][j]);
            }
    }

    if (m > p && n > q)
    {
    }
    else
        printf("NO");
}