#include <stdio.h>

void merge(int arr[], int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    int a[n1], b[n2];
    for (int i = 0; i < n1; i++) a[i] = arr[l+i];
    for (int j = 0; j < n2; j++) b[j] = arr[m + j + 1];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2){
        if (a[i] < b[j]){
            arr[k] = a[i];
            i++;
        }
        else{
            arr[k] = b[j];
            j++;
        }
        k++;
    }
    while (i < n1){
        arr[k] = a[i];
        i++;
        k++;
    }
    while (j < n2){
        arr[k] = b[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r){
    if (l < r){
        int m = l + (r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}


void printArr(int arr[], int n){
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}
int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    //printf("arr:\n");
    //printArr(arr, n);
    mergeSort(arr, 0, n-1);
    //printf("sorted arr:\n");
    //printArr(arr, n);
    int count = 1;
    for (int i = n-1; i >=0; i--){
        if (count == arr[i]){
            printf("%d", count);
            break;
        }
        else count++;
    }
}