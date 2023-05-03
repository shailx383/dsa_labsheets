#include <bits/stdc++.h>
using namespace std;

int min_coupons(int arr[], int n, int v){
    int dp[v + 1];
    dp[0] = 0;
    for (int i = 1; i <= v; i++) dp[i] = INT_MAX;
    for (int i = 1; i <= v; i++) {
        for (int j = 0; j < n; j++)
            if (arr[j] <= i) {
                int sub_res = dp[i - arr[j]];
                if (sub_res != INT_MAX && sub_res + 1 < dp[i]) dp[i] = sub_res + 1;
            }
    }
    if (dp[v] == INT_MAX) return -1;
    return dp[v];
}

int main(){
    int n, v;
    cin >> n >> v;
    int arr[n];
    for (int i = 0; i < n;i++) cin >> arr[i];
    cout << min_coupons(arr, n, v) << endl;
    return 0;
}