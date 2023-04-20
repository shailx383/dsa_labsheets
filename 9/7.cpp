#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Compare{
    bool operator()(string a, string b){
        return a + b < b + a; 
    }
};

typedef priority_queue<string, vector<string>, Compare> p_queue;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i =0; i < n; i++) cin >> arr[i];
    p_queue pq;
    for (int i =0; i < n; i++) pq.push(to_string(arr[i]));
    while(!pq.empty()){
        cout << pq.top();
        pq.pop();
    }
    cout << endl;
    return 0;;
} 

