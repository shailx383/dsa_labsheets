#include <bits/stdc++.h>
using namespace std;

int MatrixChainOrder(int arr[], int n)
{
	int dp[n][n];
	int i, j, k, L, q;
	for (i = 1; i < n; i++) dp[i][i] = 0;
	for (L = 2; L < n; L++){
		for (i = 1; i < n - L + 1; i++){
			j = i + L - 1;
			dp[i][j] = INT_MAX;
			for (k = i; k <= j - 1; k++){
				q = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
				if (q < dp[i][j]) dp[i][j] = q;
			}
		}
	}
	return dp[1][n - 1];
}

int main(){
    int n;
    cin >> n;
	int arr[n+1];
	for (int i = 0; i <= n; i++) cin >> arr[i];
	cout << MatrixChainOrder(arr, n+1) << endl;
	return 0;
}
