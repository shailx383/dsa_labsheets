#include <iostream>
#include <cmath>
using namespace std;

int linsearch(int arr[], int n, int x){
    for (int i = 0; i < n; i++){
        if (arr[i] == x) return i;
    }
    return -1;
}

int *reversearr(int* arr, int n){
    int *rev = new int[n];
    for (int i = 0; i < n; i++) rev[n-1-i] = arr[i];
    return rev;
}

int first_common_ancestor(int tree[], int n, int x, int y){
    int x_index = linsearch(tree, n, x) + 1;
    int y_index = linsearch(tree, n, y) + 1;
    int *x_ancestors = new int[n];
    x_ancestors[0] = tree[x_index - 1];
    int num_x_ancestors = 0;
    int *y_ancestors = new int[n];
    y_ancestors[0] = tree[y_index - 1];
    int num_y_ancestors = 0;
    while (x_index >= 1) {
        x_index = x_index % 2 ? (x_index-1)/2 : x_index/2;
        num_x_ancestors++;
        x_ancestors[num_x_ancestors] = tree[x_index-1];
    }
    while (y_index >= 1) {
        num_y_ancestors++;
        y_index = y_index % 2 ? (y_index-1)/2 : y_index/2;
        y_ancestors[num_y_ancestors] = tree[y_index-1];
    }
    x_ancestors = reversearr(x_ancestors, num_x_ancestors);
    y_ancestors = reversearr(y_ancestors, num_y_ancestors);
    int common;
    for (int i = 0; i < n; i++){
        if (x_ancestors[i] == y_ancestors[i]) common = x_ancestors[i];
        else break;
    }
    return common;
}
 
int main(){
    int  n, x, y;
    cin >> n >> x >> y;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << first_common_ancestor(arr, n, x, y) << endl;
    return 0;
}