#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int maximum(int arr[]){
    int m = 0;
    for (int i = 0; i < 10; i++){
        if (arr[i] > m) m = arr[i];
    }
    return m;
}

int* result(int arr[]){
    int* a = (int*)malloc(2 * sizeof(int));
    int m = maximum(arr);
    int index;
    for (int i = 0; i < 10; i++){
        if (arr[i] == m){
            index = i;
        }
    }
    a[0] = index;
    a[1] = m;
    return a;
}

int* count_digits(int digits_arr[], int num){
    while (num > 0){
        int digit = num % 10;
        digits_arr[digit]++;
        num = num/10;
    }
    return digits_arr;
}

bool is_prime(int n){
    int i = 0;
    int flag = 0;
    if (n == 0 || n == 1) flag = 1;
    for (i = 2; i < sqrt(n); i++){
        if (n % i == 0){
            flag = 1;
            break;
        }
    }
    if (flag == 0) return true;
    else return false;
}

int main(){
    int* arr = (int*)malloc(10 * sizeof(int));
    for (int i = 0; i < 10; i++) arr[i] = 0;
    int a, b;
    scanf("%d %d", &a, &b);
    for (int i = a; i <= b; i++){
        if (is_prime(i)) arr = count_digits(arr, i);
    }
    int* answer = result(arr);
    printf("%d %d", answer[0], answer[1]);
    return 0;
}