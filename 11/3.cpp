#include <bits/stdc++.h>
using namespace std;

int minimum_elt(int a, int b, int c){
    return a < b ? (a < c ? a: c) : (b < c ? b : c);
}

int minimum_edit_dist(string s, string t, int n, int m){
    int dp[n+1][m+1];
    for (int i = 0;i <= n; i++){
        for (int j = 0; j <= m; j++){
            if (i ==0 || j == 0) dp[i][j] = i + j;
            else if (s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1 + minimum_elt(dp[i-1][j], dp[i-1][j-1], dp[i][j-1]);
        }
    }
    return dp[n][m];
}

int main(){
    int n, m;
    cin >> n;
    string s;
    cin >> s;
    cin >> m;
    string t;
    cin >> t;
    cout << minimum_edit_dist(s, t, n, m) << endl;
    return 0;
}