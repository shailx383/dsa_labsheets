#include <stdio.h>
#include <stdlib.h>

int max(int arr[], int n){
    int m = 0;
    for (int i = 0; i < n; i++){
         if (arr[i]> m) m = arr[i];
    }
    return m;
}

void printarr(int arr[], int n){
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int f(int arr[], int n, int curr_split[], int k, int curr_bucket, int curr_min){
    if (curr_bucket == n){
        if (max(curr_split, k) < curr_min) curr_min = max(curr_split, k);
        return curr_min;
    }
    for (int i = 0; i < k; i++){
        curr_split[i] += arr[curr_bucket];
        curr_min = f(arr, n, curr_split, k, curr_bucket+1, curr_min);
        curr_split[i] -= arr[curr_bucket];
    }
    return curr_min;
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    int split[k];
    for (int i = 0; i < k; i++) split[i] = 0;
    printf("%d", f(arr, n, split, k, 0, 999999));
}