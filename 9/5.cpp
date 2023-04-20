#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

typedef unordered_map<int, unordered_map<int, int>> sparse_matrix;

int main(){
    int m, k, n, p, q;
    cin >> m >> k >> n;
    cin >> p;
    sparse_matrix mat1;
    for (int i = 0; i < p; i++){
        int row, col, val;
        cin >> row >> col >> val;
        mat1[row][col] = val;
    }
    cin >> q;
    sparse_matrix mat2;
    for (int i = 0; i < q; i++){
        int row, col, val;
        cin >> row >> col >> val;
        mat2[row][col] = val;
    }
    sparse_matrix mat3;
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            int sum = 0;
            for (int l = 1; l <= k; l++){
                if (mat1[i][l] && mat2[l][j]) sum += mat1[i][l] * mat2[l][j];
            } 
            if (sum != 0) mat3[i][j] = sum;
        }
    }
    int r = 0;
    for (auto row : mat3) r += row.second.size();
    cout << r << endl;
    vector<pair<pair<int, int>, int>> non_zero;
    for (auto row : mat3){
        for (auto elem : row.second) non_zero.push_back({{row.first, elem.first}, elem.second});
        
    }
    sort(non_zero.begin(), non_zero.end());
    for (auto elem : non_zero) cout << elem.first.first << " " << elem.first.second << " " << elem.second << endl;
    return 0;
}