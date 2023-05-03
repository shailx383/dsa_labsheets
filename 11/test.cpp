// C++ program for above approach

#include <bits/stdc++.h>
using namespace std;

#define V_SUM_MAX 1000
#define N_MAX 100
#define W_MAX 1000000000

int result(vector<long>& w, vector<long>& val, long n, long c, int val_sum, long max_w)
{
	long dp[V_SUM_MAX + 1][n + 1];
	for (int i = 0; i <= V_SUM_MAX; i++)
		for (int j = 0; j <= n; j++)
			dp[i][j] = W_MAX;

	// Base case initialization
	for (int i = 0; i <= n; i++)
		dp[0][i] = 0;

	// iterate over subproblems ans get
	// the current value from previous computation
	for (int i = 1; i <= V_SUM_MAX; i++)
		for (int j = 1; j <= n; j++)
			dp[i][j] = min(
				dp[i][j - 1],
				(i >= val[j - 1])
					? w[j - 1] + dp[i - val[j - 1]][j - 1]
					: W_MAX);

	// Finding maximum value
	for (int i = V_SUM_MAX; i >= 0; i--)
		if (dp[i][n] <= c)
			return i;

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
// Driver code
int main()
{
	vector<long> w = {1000000000};
	vector<long> val = {10};
	int n = (int)w.size();
	long C = 1000000000;

	cout << result(w, val, n, C, sum(val), maxWeight(w)) << endl;

	return 0;
}
