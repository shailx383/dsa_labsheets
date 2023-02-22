#include <stdio.h>
#define int long long
 
int gcd(int a, int b){
    if (a==0) return b;
    return gcd(b%a, a);
}
 
int main(){
    int a, b;
    scanf("%lld %lld", &a, &b);
    int max = 0;
    for (int i = 1; i*i <= a; i++){
        if (a % i == 0){
            if (gcd(i,b == 1)){
                if (i > max) max = i;
            }
            if (gcd(a/i, b) == 1){
                if (a/i > max) max = a/i;
            }
        }
    }
    printf("%lld", max);
}