#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> query;

int main(){
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    query queries[q];
    for (int i =0; i < q; i++){
        query qu;
        cin >> qu.first >> qu.second;
        queries[i] = qu;
    }
    vector<int> nextCandle(n, n), prevCandle(n, -1), prefixSum(n, 0);
    for (int i =0; i < n; i++){
        prevCandle[i]= (s[i] == '*') ? ((i == 0) ? prevCandle[i] : prevCandle[i - 1 ]) : i; 
        nextCandle[n-i-1] = (s[n-i-1] == '*') ? ((i == 0)? nextCandle[n-i-1] : nextCandle[n-i]) : n-i-1;
        prefixSum[i] = (i == 0) ? (s[i] == '*') : prefixSum[i-1] + (s[i] == '*');
    }
    vector <int> ans;
    for (int i =0; i < q; i++){
        int first = nextCandle[queries[i].first] > queries[i].second ? 0 : nextCandle[queries[i].first];
        int second = prevCandle[queries[i].second] < queries[i].first ? 0 : prevCandle[queries[i].second];
        ans.push_back(prefixSum[second] - prefixSum[first]);
    }
    for(int i=0; i < ans.size(); i++) cout << ans.at(i) << endl;
    return 0;
}