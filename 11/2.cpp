#include <bits/stdc++.h>
using namespace std;

int len_longest_common_subarray(int n, int m, int a[], int b[]){
    int dp[n+1][m+1];
    int maximum = 0;
    for (int i = 0; i <= n; i++){
        for (int j = 0; j<=m; j++) dp[i][j] = 0;
    }
    for (int i = n-1; i >=0; i--){
        for (int j = m-1; j >=0; j--){
            if (a[i] == b[j]) dp[i][j] = 1 + dp[i+1][j+1];
        }
    }
    for (int i = 0;i <=n;i++){
        for (int j = 0; j <=m; j++){
            if (dp[i][j] > maximum) maximum = dp[i][j];
        }
    }
    return maximum;
}

int main(){
    int n, m;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    int b[m];
    for (int i = 0; i < m; i++) cin >> b[i];
    cout << len_longest_common_subarray(n, m, a, b) << endl;
    return 0;
}