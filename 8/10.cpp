#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector <int> arr(n);
    for (int i =0; i < n; i++) cin >> arr[i];
    int ctr = 0, count_ones = 0, l = 0, r = 0;
    while (r < n){
        if (arr[r] == 1) count_ones++;
        while (count_ones > k){
            if (arr[l] == 1) count_ones--;
            l++;
        }
        ctr += r  - l + 1;
        r++;
    }   
    cout << ctr << endl;
    return 0;
}
    