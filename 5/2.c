#include <stdio.h>
#include <stdlib.h>
#define int long long

int f(int n, int x){
    if (n == 1) return 1;
    else if (!x) return 2 * f(n/2, 1);
    else if (x){
        if (n%2) return 2 * f(n/2, 0);
        else return 2 * f(n/2, 0) - 1;
    }
}

int main(){
    int n;
    scanf("%lld", &n);
    printf("%d", f(n, 0));
    return 0;
}