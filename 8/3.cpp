#include <iostream>
#include <map>
using namespace std;

int main(){
    int n, x, y;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> x >> y;
    int arr1[n];
    int arr2[n];
    for (int j = 0; j < n; j++) arr1[j] = arr[j] - (y * j);
    for (int i = 0; i < n; i++) arr2[i] = arr[i] - (x * i);
    int ans = 0;
    map <int, int> m;
    for (auto val: arr1) m[val]++;
    for (int i =0; i < n; i++){
        m[arr1[i]]--;
        ans += m[arr2[i]];
    }
    cout << ans << endl;
    return 0;
}