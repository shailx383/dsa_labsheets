#include <queue>
#include <iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int sum1 = 0, sum2 = 0;
    priority_queue<int> pq1;
    for (int  i =0; i < n; i++){
        int x;
        cin >> x;
        pq1.push(x);
        sum1+= x;
    }
    priority_queue<int> pq2;
    for (int  i =0; i < m; i++){
        int x;
        cin >> x;
        pq2.push(x);
        sum2+= x;
    }
    if (sum1 == sum2){
        cout << "Yes" << endl;
        return 0;
    }
    else{
        priority_queue<int> *larger, *smaller;
        int larger_sum, smaller_sum, ls, ss;
        if (sum1 > sum2){
            larger = &pq1;
            ls = larger_sum = sum1;
            smaller = &pq2;
            ss = smaller_sum = sum2;
        }
        else{
            larger = &pq2;
            ls = larger_sum = sum2;
            smaller = &pq1;
            ss = smaller_sum = sum1;
        }
        while (!larger->empty() && !smaller->empty()){
            if (larger->top() > smaller->top()){
                ss += larger->top() - smaller->top();
                ls -= larger->top() - smaller->top();
                if (ss == ls){
                    cout << "Yes" << endl;
                    return 0;
                }
                else{
                    larger->pop();
                }
            }
            else smaller->pop();
            ls = larger_sum;
            ss = smaller_sum;
        }
    }
    cout << "No" << endl;
    return 0;
}