#include <stdio.h>
#include <stdlib.h>

void printarr(int arr[], int n){
   for (int i = 0; i < n; i++) printf("%d ", arr[i]);
   printf("\n");
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    
}