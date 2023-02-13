#include <stdio.h>

int binSearch(int arr[], int N, int l, int target){
	int result = -1;
	int r = N - 1;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		if (arr[mid] == target) {
			result = mid;
			l = mid + 1;
		}
		else if (arr[mid] > target) r = mid - 1;
		else l = mid + 1;
	}
	return result + 1;
}

int uniqueNum(int arr[], int n){
	int i = 0;
	int count = 0;
	while (i < n)    {
		i = binSearch(arr, n, i, arr[i]);
		count++;
	}
	return count;
}

int main(){
	int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
	printf("%d", uniqueNum(arr, n));
	return 0;
}