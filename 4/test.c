#include <stdio.h>
#include <stdlib.h>

struct slot
{
    int start;
    int end;
};
typedef struct slot slot;

slot *merge(slot *arr1, slot *arr2, int n1, int n2)
{
    int i1 = 0;
    int i2 = 0;
    slot *merged = (slot *)malloc(sizeof(n1 + n2) * sizeof(slot));
    int count = 0;
    while (i1 < n1 && i2 < n2)
    {
        // printf("This is i1 start %d and i2 %d\n", arr1[i1].start, arr2[i2].start);
        if (arr1[i1].start < arr2[i2].start)
        {
            merged[count++] = arr1[i1++];
        }
        else if (arr1[i1].start > arr2[i2].start)
        {
            merged[count++] = arr2[i2++];
        }
        else if (arr1[i1].end < arr2[i2].end)
        {
            merged[count++] = arr1[i1++];
        }
        else
        {
            merged[count++] = arr2[i2++];
        }
    }
    while (i1 < n1)
    {
        merged[count++] = arr1[i1++];
    }
    while (i2 < n2)
    {
        merged[count++] = arr2[i2++];
    }
    free(arr1);
    free(arr2);
    return merged;
}

slot *mergeSort(slot *arr, int n)
{
    if (n == 1)
        return arr;
    slot *array1 = mergeSort(arr, n / 2);
    slot *array2 = mergeSort(arr + n / 2, n - n / 2);
    return merge(array1, array2, n / 2, n - n / 2);
}

void printList(slot *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d %d\n", arr[i].start, arr[i].end);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    slot arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &(arr[i].start));
        scanf("%d", &(arr[i].end));
    }
    slot *sorted = mergeSort(arr, n);
    int count = 0;
    slot *merge = (slot *)malloc(sizeof(slot) * (count + 1));
    merge[0] = sorted[0];
    for (int i = 1; i < n; i++)
    {
        if (sorted[i].start == merge[count].start)
        {
            merge[count] = sorted[i];
        }
        else if (merge[count].end >= sorted[i].end)
        {
            continue;
        }
        else if (merge[count].end >= sorted[i].start)
        {
            merge[count].end = sorted[i].end;
        }
        else
        {
            count++;
            merge = (slot *)realloc(merge, sizeof(slot) * (count + 1));
            merge[count] = sorted[i];
        }
    }
    printf("%d\n", count + 1);
    printList(merge, count + 1);
    return 0;
}