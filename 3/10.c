#include <stdio.h>

int num_planks(int plank_length, int arr[], int n){
    int sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i]/plank_length;
    return sum;
}

int maxInList(int arr[], int n){
    int max = 0;
    for (int i = 0; i < n; i++){
        if (arr[i]>max) max = arr[i];
    }
    return max;
}

int arraySum(int arr[], int n){
    int sum = 0;
    for (int i =0; i < n; i++) sum += arr[i];
    return sum;
}

int binarySearch(int max, int l, int r, int target, int arr[], int n){
    if (arraySum(arr, n) < target) return 0;
    else{
        if (r>=l){
            int mid = l + (r-l)/2;
            if ((num_planks(mid, arr, n) >= target) && (num_planks(mid+1, arr, n) < target)) return mid;
            else if ((num_planks(mid, arr, n) < target)) return binarySearch(max, l, mid-1, target, arr, n);
            else return binarySearch(max, mid+1, r, target, arr, n);
        }
    }
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    int max = maxInList(arr, n);
    printf("%d", binarySearch(max, 0, max-1, k, arr, n));
}