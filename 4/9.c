#include <stdio.h>
#include <stdlib.h>

int *rem(int *arr, int index, int n){
    int *removed = (int *)malloc(sizeof(int)*(n-1));
    int c = 0;
    for (int i = 0; i < n; i++){
        if (i != index){
            removed[c] = arr[i];
            c++;
        } 
    }
    return removed;
}

void printarr(int *arr, int n){
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int gcd(int a, int b){
    if (a==0) return b;
    return gcd(b%a, a);
}

int gcd_arr(int *arr, int n){
  int result = arr[0];
  for (int i = 1; i < n; i++){
    result = gcd(arr[i], result);
    if(result == 1) return 1;
  }
  return result;
}

int main(){
    int n;
    scanf("%d", &n);
    int *arr = (int*)malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    int max_gcd = 0;
    for (int i = 0; i < n; i++){
        int *curr_arr = rem(arr, i, n);
        int curr_gcd = gcd_arr(curr_arr, n-1);
        if (curr_gcd > max_gcd) max_gcd = curr_gcd;
    }
    printf("%d", max_gcd);
    return 0;
}