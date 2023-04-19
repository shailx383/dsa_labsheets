#include <iostream>
#include <map>
using namespace std;

typedef map <map <int, int> , int> sparse_matrix;

sparse_matrix multiply_matrices(sparse_matrix mat1, sparse_matrix mat2, int m, int k, int n){
    
}

int main(){
    int m, k, n;
    cin >> m >> k >> n;
    int p;
    cin >> p;
    sparse_matrix mat1;
    sparse_matrix mat2;
    for (int nz =0; nz < p; nz++){
        int x, i, j;
        cin >> i >> j >> x;
        map <int, int> m;
        m[i] = j;
        mat1[m] = x;
    }
    int q;
    cin >> q;
    for (int nz =0; nz < q; nz++){
        int x, i, j;
        cin >> i >> j >> x;
        map <int, int> m;
        m[i] = j;
        mat2[m] = x;
    }
}