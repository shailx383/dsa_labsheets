#include <iostream>
using namespace std;

int is_in_list(int arr[], int n, int elem){
    for (int i = 0; i < n; i++){
        if (arr[i] == elem) return 1;
    }
    return 0;
}

int kth_largest_element(int tree[], int n, int k){
    int smallest_index = 1;
    while (smallest_index <= n && tree[smallest_index - 1] != -1){
        smallest_index = smallest_index * 2 + 1;
    }
    smallest_index = smallest_index/2;
    return smallest_index;
    int i = 0;
    int parsed[n];
    int x = 0;
    while (i < k){
        if (tree[smallest_index * 2 - 1] != -1 && tree[smallest_index * 2] == -1){
            parsed[x++] = tree[smallest_index - 1];
            smallest_index *= 2;
            i++;
        }
    }
    return smallest_index;
}

int main(){
    int n, k;
    cin >> n;
    int arr[n];
    for (int i =0; i < n; i++) cin >> arr[i];
    cin >> k;
    cout << kth_largest_element(arr, n, k) << endl;
    return 0;
}