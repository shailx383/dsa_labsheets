#include <stdio.h>

void printarr(int arr[], int n){
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
}

int binSearch(int arr[], int r, int l, int target){
	if (r >= l){
        int mid = l + (r-l)/2;
        if (arr[mid] >= target && arr[mid-1] < target) return mid+1;
        else if (arr[mid] > target) return binSearch(arr, mid-1, l, target);
        else return binSearch(arr, r, mid+1, target);
    }
}

int main(){
    long n;
    scanf("%ld", &n);
    int arr[n-1];
    for (int i = 0; i < n-1; i++) arr[i] = (2*(n-1)-i)*(i+1)/2;
    int half_comp = (n*(n-1))/4; 
    printf("%d", binSearch(arr, n-2, 0, half_comp));
}