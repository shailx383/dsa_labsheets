#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

void dependency_sort(vector<int> &A, vector<int> &B){
    unordered_map<int, int> m;
    for (int i =0; i < B.size();i++) m[B[i]] = i;
    for (int i =0; i < A.size();i++){
        if (m.find(A[i]) == m.end()) m[A[i]] = B.size() + A[i];
    }
    sort(A.begin(), A.end(), [&](int x, int y) {return m[x] < m[y];});
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> A(n);
    vector<int> B(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < m ; i++) cin >> B[i];
    dependency_sort(A, B);
    for (int i =0; i < n; i++) cout << A[i] << " ";
    cout << endl;
    return 0;
}