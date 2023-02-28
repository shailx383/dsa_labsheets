#include <stdio.h>
#include <stdlib.h>

int avg(int arr[], int k){

}

int main(){
    int n, k, t;
    scanf("%d %d %d", &n, &k, &t);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    int ctr = 0;
    int sum_arr[n];
    sum_arr[0] = arr[0];
    for (int i = 1; i < n; i++) sum_arr[i] = arr[i]+sum_arr[i-1];
    for (int i = 0; i < n-k+1; i++){
        if (i == 0){
            if (sum_arr[i+k-1]/k >= t) ctr++;
        }
        else if (i == n-k){
            if ((sum_arr[n-1]-sum_arr[i-1])/k >= t) ctr++;
        }
        else{
            if ((sum_arr[i+k-1]-sum_arr[i-1])/k >= t) ctr++;
        }
    }
    printf("%d", ctr);
    return 0;
}