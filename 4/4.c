#include <stdio.h>
#include <stdlib.h>
#define int long long
int *sieve(int n){
    int *primes = (int *)malloc((n + 1) * sizeof(int));
    primes[0] = 0;
    primes[1] = 0;
    int i, j;
    for (i = 2; i <= n; i++) primes[i] = i;
    i = 2;
    while ((i * i) <= n) {
        if (primes[i] != 0) {
            for (j = 2; j < n; j++) {
                if (primes[i] * j > n) break;
                else primes[primes[i] * j] = 0;
            }
        }
        i++;
    }
    return primes;
}

int* result(int* primes, int n){
    for (int i = 0; i < n+1;i++){
        if (primes[i]>0) primes[i] = 1;
    }
    for (int i = 1; i <= n+1; i++) primes[i] = primes[i] + primes[i-1];
    return primes;
}

void printarr(int *arr, int n){
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int n,q;
    scanf("%lld %lld", &n, &q);
    int *arr = (int*)malloc(sizeof(int)*q);
    for (int i = 0; i < q; i++) scanf("%d", &arr[i]);
    int *new = sieve(n);
    int *ans = result(new, n);
    for (int i = 0; i < q; i++) printf("%lld ", ans[arr[i]]);
}