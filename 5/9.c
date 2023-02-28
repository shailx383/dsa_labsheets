#include <stdio.h>
#include <stdlib.h>

int kool_subarray(int arr[], int n, int k){
    int l = 0, n_arr = 0, odd_count = 0, cur_subarray_count = 0;
    for (int r = 0; r < n; r++){
        if (arr[r]%2){
            odd_count++;
            cur_subarray_count = 0;
        }
        while (odd_count == k){
            if (arr[l]%2) odd_count--;
            l++;
            cur_subarray_count++;
        }
        n_arr += cur_subarray_count; 
    }
    return n_arr;
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("%d", kool_subarray(arr, n, k));
}