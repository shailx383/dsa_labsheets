#include <bits/stdc++.h>
using namespace std;

float findMedian(int arr1[], int arr2[], int n, int m){
    int count, i = 0, j = 0, m1 = -1, m2 = -1;
    for (count = 0; count <= (m+n)/2; count++){
        m2 = m1;
        if (i != n && j != m) m1 = (arr1[i] > arr2[j]) ? arr2[j++] : arr1[i++];
        else if (i < n) m1 = arr1[i++];
        else m1 = arr2[j++];
    } 
    if ((m+n) % 2 == 1) return m1;
    else return  (m1 + m2) / 2.0;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int m;
    cin >> m;
    int b[m];
    for (int i = 0; i < m; i++) cin >> b[i];
    cout << findMedian(a, b, n, m) << endl;
    return 0;
}