#include <stdio.h>
#include <stdlib.h>

int arraySum(long long arr[], long long n){
    int sum = 0;
    for (int i =0; i < n; i++) sum += arr[i];
    return sum;
}

int main(){
    long long n;
    scanf("%d", &n);
    long long arr[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int sum = arraySum(arr, n);
    int num_chocs = sum/n;
    int ops = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] != num_chocs) ops += abs(arr[i] - num_chocs);
    }
    printf("%d", ops);
}