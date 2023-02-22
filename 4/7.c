#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int max(int arr[], int n, int place){
    int m = 0;
    for (int i = 0; i < n; i++){
        if ((arr[i]/place)%10 > (m/place)%10) m = arr[i];
    }
    return m;
}

int maxOfArray(int arr[], int n){
    int m = 0;
    for (int i = 0; i < n; i++){
        if(arr[i]> m) m = arr[i];
    }
    return m;
}

void printarr(int arr[], int n){
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int *copy(int arr[], int n){
    int* res = (int *)malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++){
        res[i] = arr[i];
    }
    return res;
}

int *countsort(int arr[], int n, int place){
    int last = (max(arr, n, place)/place)%10;
    int* sorted = (int*)malloc(sizeof(int)*n);
    int* freq = (int*)malloc((last+1)*sizeof(int));
    for (int i = 0; i < last+1; i++) freq[i] = 0;
    for (int i = 0; i < n; i++) freq[(arr[i]/place)%10]++;
    for (int i = 2; i <= last; i++) freq[i] = freq[i] + freq[i-1];
    for (int i = n-1; i >=0; i--){
        int curr_digit = ((arr[i]/place)%10);
        int index = freq[curr_digit];
        freq[curr_digit] = freq[curr_digit]-1;
        sorted[index-1] = arr[i];
    }
    return sorted;
}

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    int max_place = 1;
    int max_elem = maxOfArray(arr, n);
    for (int i = max_elem/10; i >0; i/=10){
        max_place*=10;
    }
    for(int place = 1; place <= max_place; place*=10){
        int* new = countsort(arr, n, place);
        printarr(new, n);
        int* arr = copy(new, n);
    }
}