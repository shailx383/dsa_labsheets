#include <stdio.h>

int binSearch(int arr[], int r, int l, int target){
	if (r >= l){
        int mid = l + (r-l)/2;
        if (arr[mid] <= target && arr[mid+1] >= target) return mid;
        else if (arr[mid] > target) return binSearch(arr, mid-1, l, target);
        else return binSearch(arr, r, mid+1, target);
    }
}

int main(){
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);
    int arr[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int x = binSearch(arr, n-1, 0, k);
    printf("%d", arr[x]);
}