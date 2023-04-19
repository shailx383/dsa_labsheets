#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i =0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    int median  = arr[n/2];
    int i = n - 1;
    int ops = 0;
    for (int i = 0;i < n; i++) cout << arr[i] << " ";
    while(i >= n/2){
        int j = n/2;
        while (j >= 0){
            cout << "current i " << i; 
            cout << "current j " << j; 
            int j = 0;
            if (arr[i] - arr[n/2 - j] >= k){
                ops++;
                j = -1;
            } 
            j++;
        }
        
    } 
    cout << ops << endl;  
    return 0;
}