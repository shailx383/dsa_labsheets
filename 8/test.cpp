#include <iostream>
#include <map>
using namespace std;

string countsort(string s){
    int m = s.length();
    string output(m, ' ');
    int count[26] = {0};
    for (int i = 0; i < m; i++) count[s[i] - 97]++;
    for (int i = 1; i < 26; i++) count[i] += count[i-1];
    for (int i = m - 1; i >= 0; i--) {
        output[count[s[i] - 97] - 1] = s[i];
        count[s[i] - 97]--;
    }
    return output;
}

int main(){
    int n, m;
    cin >> n >> m;

    map <string, int> mp;
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        s = countsort(s);
        mp[s] += 1;
    }
    int sum = 0;
    for (auto m:mp){
        int x = m.second;
        sum += (x*(x-1))/2;
    }
    cout << sum << endl;
    return 0;
}