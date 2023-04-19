#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct compare{
    bool operator()(int l, int r){
        return l > r;
    }
};

typedef priority_queue<int, vector<int>, compare> min_heap;


int main(){
    int n;
    cin >> n;
    int sum = 0, bottles= 0;
    int x;
    vector <int> v;
    min_heap q;
    for (int i =0; i < n;i++){
        cin >> x;
        v.push_back(x);
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