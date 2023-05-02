#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int l, int m, int r){
    vector<int> temp;
    int x = 0;
    int i = l, j = m + 1;
    while (i <= m && j <= r){
        if (arr[i] > arr[j]) temp.push_back(arr[i++]);
        else temp.push_back(arr[j++]);
    }
    while (i <= m) temp.push_back(arr[i++]);
    while (j <= r) emp.push_back(arr[j++]);
    for (int i = 0; i < temp.size(); i++) arr[i] = temp[i];
}

void mergeSort(vector<int> arr, int l, int r){
    if (l < r){
        int mid  = (l+r)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, m, r);
    }
}

int main(){
    int n, x;
    cin >> n >> x;
    int arr[n];
    for (int i = 0;i < n; i++) cin >> arr[i];
    mergeSort()
    return 0;
}