#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Compare{
    bool operator()(int l, int r){
        return l > r;
    }
};

typedef priority_queue<int, vector<int>, Compare> min_heap;

int main(){
    int n;
    cin >> n;
    int sum = 0, bottles= 0;
    int x;
    min_heap q;
    for (int i =0; i < n;i++){
        cin >> x;
        bottles++;
        sum += x;
        if (x < 0) q.push(x);
        if (sum < 0){
            sum -= q.top();
            q.pop();
            bottles --;
        }
    }
    cout << bottles << endl;
    return 0;
}