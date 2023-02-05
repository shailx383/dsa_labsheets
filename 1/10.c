#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printarr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

char *bubbleSort(char *str)
{
    int i, j;
    for (i = 0; i < strlen(str) - 1; i++)
        for (j = 0; j < strlen(str) - i - 1; j++)
        {
            if (str[j] > str[j + 1])
            {
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
}

int findIndex(char *str, char c)
{
    int index;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == c)
        {
            index = i;
            break;
        }
    }
    return index;
}

char *copy(char *str)
{
    int n = strlen(str);
    char *new = (char *)malloc(strlen(str) * sizeof(char));
    for (int i = 0; i < n; i++)
    {
        new[i] = str[i];
    }
    return new;
}

int main()
{
    char s[100];
    char a[100];
    scanf("%s", s);
    scanf("%s", a);
    char *initial_s = copy(s);
    char *initial_a = copy(a);
    bubbleSort(s);
    bubbleSort(a);
    if (strlen(a) == strlen(s))
    {
        if (strcmp(a, s) == 0)
        {
            int *index_arr = (int *)malloc((int)strlen(a) * sizeof(int));
            for (int i = 0; i < strlen(a); i++)
            {
                index_arr[i] = findIndex(initial_s, initial_a[i]) + 1;
            }
            printf("POSSIBLE\n");
            printarr(index_arr, strlen(a));
        }
        else
            printf("NOT POSSIBLE\n");
    }
    else
        printf("NOT POSSIBLE\n");
}