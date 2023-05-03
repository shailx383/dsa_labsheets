#include <bits/stdc++.h>
using namespace std;

int num_palindromes(string& s) {
    vector<vector<int>> dp(s.size(), vector<int>(s.size()));
    int count = 0;
    for(int i = s.size() - 1; i >= 0; --i) {
        for(int j = i; j < s.size(); ++j) {
            if (i == j) {
                dp[i][j] = 1;
            } else if (i + 1 == j) {
                dp[i][j] = s[i] == s[j] ? 1 : 0;
            } else {
                dp[i][j] = s[i] == s[j] ? dp[i+1][j-1] : 0;
            }
            count += dp[i][j];
        }
    }
    return count;
}

int main(){
    string s;
    cin >> s;
    cout << num_palindromes(s) << endl;
    return 0;
}