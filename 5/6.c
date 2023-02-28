#include <stdio.h>
#include <stdlib.h>

int xor_of_array(int arr[], int n){
    int xor = arr[0];
    for(int i = 1; i < n; i++) xor = xor ^ arr[i];
    return xor;
}

int result(int A[], int n, int B[], int m){
    int xor1 = xor_of_array(A, n);
    int xor2 = xor_of_array(B, m);
    xor1 = m % 2 ? xor1 : 0;
    xor2 = n % 2 ? xor2 : 0;    
    return xor1 ^ xor2;
}

int main(){
    int n, m;
    scanf("%d", &n);
    int A[n];
    for (int i = 0; i < n; i++) scanf("%d", &A[i]);
    scanf("%d", &m);
    int B[m];
    for (int i = 0; i < m; i++) scanf("%d", &B[i]);
    printf("%d", result(A, n, B, m));
}