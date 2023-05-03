#include<bits/stdc++.h>
using namespace std;

int check(deque<int> q){
    if (q.front() < q.back()) return 1;
    return 0;
}

int main(){
    int n;
    cin >> n;
    deque<int> q;
    for(int i = 0; i < n;i++) {
        int x;
        cin >> x;
        q.push_front(x);
    }
    int diff = 0;
    int start_player = n%2;
    while (!q.empty()){
        int player = q.size()%2;
        if (start_player == 0){
            if (check(q)){
                if (player == 0) diff += q.back();
                else diff -= q.back();
                q.pop_back();
            }
            else{
                if (player == 0) diff += q.front();
                else diff -= q.front();
                q.pop_front();
            }
        }
        else{
            if (check(q)){
                if (player == 0) diff -= q.back();
                else diff += q.back();
                q.pop_back();
            }
            else{
                if (player == 0) diff -= q.front();
                else diff += q.front();
                q.pop_front();
            }
        }
    }
    cout << diff << endl;
    return 0;
}
