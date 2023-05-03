#include <bits/stdc++.h>
using namespace std;

long maxWeight(vector<long>& w, vector<long>& val, long n, long c, int val_sum, long max_w){
	long dp[val_sum + 1][n + 1];
	for (long i = 0; i <= val_sum; i++){
		for (long j = 0; j <= n; j++) dp[i][j] = max_w;
    }
	for (int i = 0; i <= n; i++) dp[0][i] = 0;
	for (int i = 1; i <= val_sum; i++){
		for (int j = 1; j <= n; j++)
			dp[i][j] = min(dp[i][j - 1], (i >= val[j - 1]) ? w[j - 1] + dp[i - val[j - 1]][j - 1] : max_w);
    }
	for (long i = val_sum; i >= 0; i--){
        if (dp[i][n] <= c)
			return i;
    }
	return 0;
}

int sum(vector<long> &v){
    int s = 0;
    for (int i = 0; i < v.size(); i++) s += v[i];
    return s;
}

long maxWeight(vector<long> &w){
    long m = 0;
    for(int i = 0; i < w.size(); i++){
        if (w[i] > m) m = w[i];
    }
    return m;
}

int main()
{
    int n;
    long C;
    cin >> n >> C;
	vector<long> weights(n), values(n);
    for (int i = 0; i < n; i++) cin >> weights[i] >> values[i];
	cout << maxWeight(weights, values, n, C, sum(values), maxWeight(weights)) << endl;
	return 0;
}
