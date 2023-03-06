#include <iostream>
#include <deque>
using namespace std;

int *max_of_sliding_window(int arr[], int n, int k){
    deque <int> q(k);
    int i;
    int* ans = new int[n-k];
    int c = 0;
    for (i = 0; i < k; ++i){
        while (!q.empty() && arr[i] >= arr[q.back()]) q.pop_back();
        q.push_back(i);
    }
    for (; i < n; ++i){
        ans[c] = arr[q.front()];
        c++;
        while (!q.empty() && q.front() <= i - k) q.pop_front();
        while (!q.empty() && arr[i] >= arr[q.back()]) q.pop_back();
        q.push_back(i); 
    }
    ans[c] = arr[q.front()];
    return ans;
}

int main(){
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n-k+1; i++) cout << max_of_sliding_window(arr, n, k)[i] << " ";
    return 0;
}