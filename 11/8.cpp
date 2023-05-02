#include <bits/stdc++.h>
using namespace std;

int maximum(int a, int b){
    return a > b? a : b;
}

int longest_valid_substring(string s){
    int n = s.length();
    stack <int> stk;
    stk.push(-1);
    int ans = 0;
    for (int i = 0;i < n; i++){
        if (s[i] == '(') stk.push(i);
        else{
            if (!stk.empty()) stk.pop();
            if (!stk.empty()) ans = maximum(ans, i - stk.top());
            else stk.push(i);
        }
    }
    return ans;
}

int main(){
    string s;
    cin >> s;
    cout << longest_valid_substring(s) << endl;
    return 0;
}