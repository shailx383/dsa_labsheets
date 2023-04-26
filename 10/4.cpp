#include <iostream>
using namespace std;

void flip(int arr[], int i){
    int temp, start = 0;
    while (start < i){
        temp = arr[start];
        arr[start] = arr[i];
        arr[i] = temp;
        start++;
        i--;
    }
}

int findMax(int arr[], int n){
    int i, max_index = 0;
    for (i = 0;i < n; i++){
        if (arr[i] > arr[max_index]) max_index = i;
    }
    return max_index;
}

void pancakeSort(int arr[], int n){
    for (int curr_size = n; curr_size > 1; --curr_size){
        int max_index = findMax(arr, curr_size);
        if (max_index != curr_size-1){
            flip(arr, max_index);
            flip(arr, curr_size - 1);
        }
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    pancakeSort(arr, n);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}