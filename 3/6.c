#include <stdio.h>

int nextIndex(int arr[], int N, int l,
			int target)
{
	int result = -1;
	int r = N - 1;
	while (l <= r) {
		int mid = l + (r - l) / 2;
        //printf("mid: %d\n", mid);
		if (arr[mid] == target) {
			result = mid;
			l = mid + 1;
		}
		else if (arr[mid] > target)
			r = mid - 1;
		else
			l = mid + 1;
        //printf("r, l: %d, %d\n", r, l);
	}
	return result + 1;
}

int uniqueNum(int arr[], int n)
{
	int i = 0;
	int count = 0;
	while (i < n) {
		i = nextIndex(arr, n, i, arr[i]);
        //printf("i :%d\n", i);
		count++;
	}
	return count;
}

int main(){
	int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
	int q = uniqueNum(arr, n);
	printf("%d", q);
	return 0;
}
