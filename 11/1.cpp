#include <bits/stdc++.h>
using namespace std;

long long maximum(long long a, long long b) {
    return a>b ? a: b;
}

long long maxValueSum(long long w, long long weights[], long long values[], long long n){
    long long i, j;
    long long dp[n+1][w+1];
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= w; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (weights[i - 1] <= j)
                dp[i][j] = maximum(dp[i - 1][j], values[i - 1] + dp[i - 1][j - weights[i - 1]]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][w];
}

int main(){
    long long n, w;
    cin >> n>> w;  
    long long weights[n], values[n]; 
    for (int i = 0; i < n; i++) cin >> weights[i] >> values[i];
    cout << maxValueSum(w, weights, values, n) << endl;
    return 0;
}