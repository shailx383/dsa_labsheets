#include <stdio.h>
#include <stdlib.h>
#define int long long

int f(int arr[], int n, int k){
    int prefix[n];
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++) prefix[i] = prefix[i-1] + arr[i];
    int rem[k];
    for (int i = 0; i < k; i++) rem[i] = 0;
    for (int i = 0; i < n; i++) rem[prefix[i] % k]++;
    int n_safe = rem[0];
    for (int i = 0; i < k; i++){
         if (rem[i]> 1) n_safe+= (rem[i]* (rem[i]-1))/2;
    }
    return n_safe;
}

int main(){ 
    int n, k;
    scanf("%lld %lld", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%lld", &arr[i]);
    printf("%lld", f(arr, n, k));
    return 0;
}