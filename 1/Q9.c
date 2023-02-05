// You are given an array A of n positive integers in the range 1 to k (1 and k are inclusive in the range). 
// The values of n and k and the elements of A are given as user inputs. 
// The elements of the array need not be present in sorted order. 
// Note that it is guaranteed that n and k are odd integers. 
// Moreover, it is also guaranteed that the element (1+k)/2 is present in the array. 
// However, it can be present in the array at any position. 
// Let us call this element as mid. 
// Rearrange the elements of A such that mid occupies the middle position (not the central index) of the array,
// all elements lesser than the mid are placed to the left of mid and all elements greater than mid are placed to the
// right of mid (See sample input-output for better clarity). You are not allowed to use any additional array or data
// structure. Note that mid is unique in the array. However, there can be duplicates of other elements of the array.
// In the final output, you should maintain the relative ordering of the elements of the original input array A. 
// It is not necessary that the number of elements lesser than mid and the number of elements greater than mid are
// equal.

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