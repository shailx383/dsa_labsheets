#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n, m, elem, cost = 0;
    priority_queue<int> q;
    cin >> n >> m;
    for (int i =0; i < n; i++){
        cin >> elem;
        q.push(elem);
    }
    for (int i = 0; i < m; i++){
        int curr_max = q.top();
        q.pop();
        q.push(curr_max/2);
    }
    while (!q.empty()){
        cost += q.top();
        q.pop();
    }
    cout << cost << endl;
    return 0;
}