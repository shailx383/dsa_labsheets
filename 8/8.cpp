#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    string s;
    cin >> s;
    map <string, int> mp;
    for (int i = 0; i < s.length(); i++){
        mp[s.substr(i, 10)]++;
    }
    int ctr = 0;
    for (auto m: mp){
        if (m.second > 1) ctr++;
    }
    cout << ctr << endl;
    for (auto m : mp){
        if (m.second > 1)  cout << m.first << endl;
    }
    return 0;
}