#include <stdio.h>
#include <stdlib.h>

int trailing_zeros(int n){
    int count = 0;
    for (int i = 5; n/i >=1; i*=5) count+= n/i;
    return count;
}

int main(){
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    int max = 0;
    for (int i = 0; i < n; i++){
        int z = trailing_zeros(arr[i]);
        if (z > max) max = z;
    }
    int *freq = (int*)malloc(sizeof(int)*(max+1));
    for (int i = 0; i <= max; i++) freq[i] = 0;
    for (int i = 0; i < n; i++) freq[trailing_zeros(arr[i])]++;
    int result = 0;
    for (int i = 0; i <= max; i++) result += (freq[i] *(freq[i] - 1))/2;
    printf("%d", result);
}