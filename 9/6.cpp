#include <bits/stdc++.h>
using namespace std;

bool isValid(int arr[], int n, int mid,int k){
	for (int i = 0; i < mid; i++){

		if (abs(arr[n - mid + i]- arr[i])< k) {
			return false;
		}
	}

	return true;
}

int countPairs(int arr[], int n, int k){
	int ans = 0;

	int left = 0;
    int right = n / 2 + 1;

	while (left < right){

		int mid = (left + right) / 2;

		if (isValid(arr, n, mid, k)){
			ans = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	return ans;
}

int main(){

    int n,k;
    cin >> n >> k;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

	sort(arr, arr + n);

	cout << countPairs(arr, n, k);

	return 0;
}