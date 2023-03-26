#include <iostream>
using namespace std;

int linsearch(int arr[], int n, int x){
    for (int i = 0; i < n; i++){
        if (arr[i] == x) return i;
    }
    return -1;
}

int first_common_ancestor(int tree[], int n, int x, int y){
    int x_index = linsearch(tree, n, x) + 1;
    int y_index = linsearch(tree, n, y) + 1;
    
}
 
int main(){
    int  n, x, y;
    cin >> n >> x >> y;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

}