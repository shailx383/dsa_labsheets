#include <stdio.h>

int new_x(int old_x, char mov)
{
    if (mov == 'r')
        return old_x;
    else if (mov == 'l')
        return old_x;
    else if (mov == 'u')
        return old_x - 1;
    else
        return old_x + 1;
}

int new_y(int old_y, char mov)
{
    if (mov == 'r')
        return old_y + 1;
    else if (mov == 'l')
        return old_y - 1;
    else if (mov == 'u')
        return old_y;
    else
        return old_y;
}

int main()
{
    int n;
    scanf("%d", &n);
    int ctr = 2;
    int m[2 * n - 1][2 * n - 1];
    for (int i = 0; i < 2 * n - 1; i++)
    {
        for (int j = 0; j < 2 * n - 1; j++)
        {
            m[i][j] = 3;
        }
    }
    int x, y;
    int half_ring = 1;
    if (n % 2 == 1)
    {
        x = n - 1;
        y = n - 1;
        m[x][y] = ctr;
        ctr += 2;
        while (1)
        {
            if (half_ring > n / 2)
            {
                for (int i = 0; i < n - 1; i++)
                {
                    x = new_x(x, 'r');
                    y = new_y(y, 'r');
                    m[x][y] = 0;
                    x = new_x(x, 'r');
                    y = new_y(y, 'r');
                    m[x][y] = ctr;
                    ctr += 2;
                }
                break;
            }
            else
            {
                for (int i = 0; i < (2 * half_ring - 1); i++)
                {
                    x = new_x(x, 'r');
                    y = new_y(y, 'r');
                    m[x][y] = 0;
                    x = new_x(x, 'r');
                    y = new_y(y, 'r');
                    m[x][y] = ctr;
                    ctr += 2;
                }
                for (int i = 0; i < (2 * half_ring - 1); i++)
                {
                    x = new_x(x, 'u');
                    y = new_y(y, 'u');
                    m[x][y] = 1;
                    x = new_x(x, 'u');
                    y = new_y(y, 'u');
                    m[x][y] = ctr;
                    ctr += 2;
                }
                for (int i = 0; i < (2 * half_ring); i++)
                {
                    x = new_x(x, 'l');
                    y = new_y(y, 'l');
                    m[x][y] = 0;
                    x = new_x(x, 'l');
                    y = new_y(y, 'l');
                    m[x][y] = ctr;
                    ctr += 2;
                }
                for (int i = 0; i < (2 * half_ring); i++)
                {
                    x = new_x(x, 'd');
                    y = new_y(y, 'd');
                    m[x][y] = 1;
                    x = new_x(x, 'd');
                    y = new_y(y, 'd');
                    m[x][y] = ctr;
                    ctr += 2;
                }
                half_ring++;
            }
        }
    }
    else
    {
        x = n - 2;
        y = n;
        m[x][y] = ctr;
        ctr += 2;
        while (1)
        {
            if (half_ring >= n / 2)
            {
                for (int i = 0; i < n - 1; i++)
                {
                    x = new_x(x, 'l');
                    y = new_y(y, 'l');
                    m[x][y] = 0;
                    x = new_x(x, 'l');
                    y = new_y(y, 'l');
                    m[x][y] = ctr;
                    ctr += 2;
                }
                for (int i = 0; i < n - 1; i++)
                {
                    x = new_x(x, 'd');
                    y = new_y(y, 'd');
                    m[x][y] = 1;
                    x = new_x(x, 'd');
                    y = new_y(y, 'd');
                    m[x][y] = ctr;
                    ctr += 2;
                }
                for (int i = 0; i < n - 1; i++)
                {
                    x = new_x(x, 'r');
                    y = new_y(y, 'r');
                    m[x][y] = 0;
                    x = new_x(x, 'r');
                    y = new_y(y, 'r');
                    m[x][y] = ctr;
                    ctr += 2;
                }
                break;
            }
            else
            {
                for (int i = 0; i < (2 * half_ring - 1); i++)
                {
                    x = new_x(x, 'l');
                    y = new_y(y, 'l');
                    m[x][y] = 0;
                    x = new_x(x, 'l');
                    y = new_y(y, 'l');
                    m[x][y] = ctr;
                    ctr += 2;
                }
                for (int i = 0; i < (2 * half_ring - 1); i++)
                {
                    x = new_x(x, 'd');
                    y = new_y(y, 'd');
                    m[x][y] = 1;
                    x = new_x(x, 'd');
                    y = new_y(y, 'd');
                    m[x][y] = ctr;
                    ctr += 2;
                }
                for (int i = 0; i < (2 * half_ring); i++)
                {
                    x = new_x(x, 'r');
                    y = new_y(y, 'r');
                    m[x][y] = 0;
                    x = new_x(x, 'r');
                    y = new_y(y, 'r');
                    m[x][y] = ctr;
                    ctr += 2;
                }
                for (int i = 0; i < (2 * half_ring); i++)
                {
                    x = new_x(x, 'u');
                    y = new_y(y, 'u');
                    m[x][y] = 1;
                    x = new_x(x, 'u');
                    y = new_y(y, 'u');
                    m[x][y] = ctr;
                    ctr += 2;
                }
                half_ring++;
            }
        }
    }
    for (int i = 0; i < 2 * n - 1; i++)
    {
        for (int j = 0; j < 2 * n - 1; j++)
        {
            if (m[i][j] == 3)
                printf("%-3c", ' ');
            else if (m[i][j] == 1)
                printf("%-3c", '|');
            else if (m[i][j] == 0)
                printf("%-3c", '-');
            else
                printf("%-3d", m[i][j]);
        }
        printf("\n");
    }
}