#include <stdio.h>
#include <stdlib.h>
#define int long long

void initialize(int *arr, int n)
{
    for (int i = 0; i < n; i++) arr[i] = 0;
}
void enqueue(int *queue, int n, int *ptr, int element, int *countarr)
{
    *(ptr) = *(ptr) + 1;
    if (*ptr < n)
    {
        queue[*ptr] = element;
        countarr[element]++;
    }
}
int dequeue(int *queue, int *ptr, int n, int *countarr, int *front)
{
    while (countarr[queue[*front]] != 1)
    {
        *front = *front + 1;
        if (*front > *ptr)
            return -1;
    }
    return queue[*front];
}

int main()
{
    int n;
    scanf("%lld", &n);
    int *countarr = malloc((n + 1) * sizeof(int));
    initialize(countarr, n + 1);
    int *queue = malloc(n * sizeof(int));
    initialize(queue, n);
    int ptr = -1, front = 0;
    for (int i = 0; i < n; i++)
    {
        int element, nonrecurring;
        scanf("%lld", &element);
        if (ptr == -1)
        {
            enqueue(queue, n, &ptr, element, countarr);
            nonrecurring = element;
        }
        else if (nonrecurring == -1)
        {
            if (countarr[element] == 0)
            {
                enqueue(queue, n, &ptr, element, countarr);
                nonrecurring = element;
            }
            else
                countarr[element]++;
        }
        else
        {
            if (countarr[element] == 0)
            {
                enqueue(queue, n, &ptr, element, countarr);
            }
            else
            {
                countarr[element]++;
                if (element == nonrecurring)
                {
                    nonrecurring = dequeue(queue, &ptr, n, countarr, &front);
                }
            }
        }
        printf("%lld ", nonrecurring);
    }
    free(countarr);
    free(queue);
    return 0;
}