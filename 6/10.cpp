#include <iostream>
#include <string>
#include <stack>
using namespace std;

int num_ops(string s){
    stack <int> stk;
    int ans = 0;
    for (int i =0; i < s.length(); i++){
        if (s[i]=='(') stk.push(1);
        else if (!stk.empty() && s[i] == ')') stk.pop();
        else ans++;
    }
    ans += stk.size();
    return ans;
}

int main(){
    string s;
    cin >> s;
    cout << num_ops(s);
    return 0;
}
