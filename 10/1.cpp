#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    int max_so_far = INT_MIN;
    int curr_max = 0;
    for (int i =0; i < n;  i++){
        curr_max += arr[i];
        if (max_so_far < curr_max) max_so_far = curr_max;
        if (curr_max < 0) curr_max = 0;
    } 
    cout << max_so_far << endl;
    return 0;
}