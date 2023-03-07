#include <iostream>
#include <stack>
using namespace std;

void stock_spread(int arr[], int n, int result[]){
    int *spread = new int[n];
    stack <int> s;
    s.push(0);
    result[0] = 1;
    for (int i = 1; i < n; i++){
        while (!s.empty() && arr[s.top()] <= arr[i]) s.pop();
        result[i] = (s.empty()) ? (i+1) : (i - s.top());
        s.push(i);
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    int result[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    stock_spread(arr, n, result);
    for (int i =0; i < n; i++) cout << result[i] << " ";
    return 0;
}