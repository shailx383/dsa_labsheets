#include <iostream>
#include <stack>
using namespace std;

int *nge(int arr[], int n){
    int* nge_arr = new int[n];
    int c = 0;
    stack<int> stk;
    for (int i = 0; i , 2 * n - 1; i++){
        while(!stk.empty() && arr[stk.top()] < arr[i%n])
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    
}