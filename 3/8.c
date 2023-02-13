#include <stdio.h>

int binSearch(int arr[], int r, int l, int target){
	if (r >= l){
        int mid = l + (r-l)/2;
        if (arr[mid]*arr[mid] == target) return mid;
        else if (arr[mid]*arr[mid] > target) return binSearch(arr, mid-1, l, target);
        else return binSearch(arr, r, mid+1, target);
    }
}

int main(){
    long n;
    scanf("%ld", &n);
    int arr[n];
    for (int i = 1; i <= n; i++){
        arr[i] = i;
    }
    printf("%d", binSearch(arr, n-1, 0, n));
}