#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    map <int, int> losses;
    for (int i =1; i <=k; i++) losses[i] = 0;
    for (int i = 0; i < n; i++){
        int w, l;
        cin >> w >> l;
        losses[l]++;
    }
    for (auto m: losses){
        if (m.second <= 1) cout << m.first << " ";
    }
    cout << endl;
    return 0;
}