#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool f(int arr[], int len, int sum){
    static int flag = 0;
    if (sum == 0){
        flag = 1;
        return true;
    } 
    if (flag == 1){
        return true;
    }
    if (sum !=0 && len == 0){
        return false;
    }
    else{
        bool a = f(arr, len - 1, sum-arr[len-1]);
        bool b = f(arr, len - 1, sum);
        if (a){
            printf("%d ", len-1);
        }
        return a||b;
    }
    
}


int main(){
    int n;
    scanf("%d", &n);
    int *arr = (int*)malloc(n*sizeof(int));
    for (int i = 0; i<n;i++){
        scanf("%d", &arr[i]);
    }
    int sum;
    scanf("%d", &sum);
    if (f(arr, n, sum)) printf(" ");
    else printf("NOT POSSIBLE");
}