#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    int n, x, y;
    cin >> n;
    pair<int, int> coordinates[n];
    for (int i = 0; i < n; i++){
        cin >> x >> y;
        coordinates[i] = {x, y};
    }
    int answer = 0;
    for (int i = 0; i < n; i++){
        map<pair<int, int>, int> mp;
        for (int j = i + 1; j < n; j++){
            int base = coordinates[i].first - coordinates[j].first;
            int height = coordinates[i].second - coordinates[j].second;
            int gcd = __gcd(base, height);
            base /= gcd;
            height /= gcd;
            mp[{base, height}]++;
        }
        int temp = n - (i + 1);
        answer += temp * (temp - 1) / 2;
        for (auto m : mp) answer -= (m.second) * (m.second - 1) / 2; 
    }
    cout << answer;
}