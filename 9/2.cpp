#include <iostream>
#include <vector>
using namespace std;

struct query{
    int start, end;
};
typedef struct query query;

int main(){
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    query queries[q];
    for (int i =0; i < q; i++){
        query qu;
        cin >> qu.start >> qu.end;
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
        int start = nextCandle[queries[i].start] > queries[i].end ? 0 : nextCandle[queries[i].start];
        int end = prevCandle[queries[i].end] < queries[i].start ? 0 : prevCandle[queries[i].end];
        ans.push_back(prefixSum[end] - prefixSum[start]);
    }
    for(int i=0; i < ans. size(); i++) cout << ans.at(i) << endl;
    return 0;
}