#include <iostream>
#include <string>
#include <stack>
using namespace std;

string simplified_path(string path){
    int i = 0;
    stack <string> stk;
    string simp = "";
    while (i < path.length()){
        string curr_dir = "";
        if (path[i] == '/'){
            i++;
        }
        else if (path[i] == '.' && path[i+1] != '.'){
            i += 2;
        }
        else if (path[i] == '.' && path[i+1]== '.'){
            if (stk.empty()){
                cout << "Wrong" << endl;
                return "";
            }
            stk.pop();
            i += 3;
        }
        else{
            while (path[i] != '/' && i != path.length()){
                curr_dir += path[i];
                i++;
            }
            stk.push(curr_dir);
            curr_dir = "";
            i++;
        }
    }
    if (stk.empty()) return "/";
    stack <string> new_stk;
    while (!stk.empty()){
        new_stk.push(stk.top());
        stk.pop();
    }
    while (!new_stk.empty()){
        simp += '/';
        simp += new_stk.top();
        new_stk.pop();
    }
    return simp;
}

int main(){
    string s;
    cin >> s;
    string result = simplified_path(s);
    cout << result;
    return 0;
}