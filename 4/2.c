#include <stdio.h>
#include <stdlib.h>

int check(int *arr, int n, int score){
    int count = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] >= score){
            count++;
        }
        if (count == score){
            return 1;
        }
    }
    return 0;
}

int find_best_score(int *arr, int start, int end, int n)
{
    int mid = (start + end) / 2;
    if ((start + end) % 2) mid++;
    if (start == end) return mid;
    if (check(arr, n, mid)) return find_best_score(arr, mid, end, n);
    else return find_best_score(arr, start, mid - 1, n);
}

int main()
{
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    int score = find_best_score(arr, 0, n, n);
    printf("%d", score);
    return 0;
}