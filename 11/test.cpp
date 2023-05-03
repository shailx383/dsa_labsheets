#include <bits/stdc++.h>
using namespace std;

int knapsack(int C, int nth_index, int weights[], int values[]){
    if (nth_index < 0 || C == 0) return 0;
    if (weights[nth_index] > C) return knapsack(C, nth_index-1, weights, values);
    int include = values[nth_index] + knapsack(C - weights[nth_index], nth_index-1, weights, values);
    int exclude = knapsack(C, nth_index-1, weights, values);
    return max(include, exclude);     
}

int main(){
    int n, C;
    cin >> n >> C;
    int weights[n], values[n];
    for (int i = 0; i < n; i++) cin >> weights[i] >> values[i];
    cout << knapsack(C, n-1, weights, values) << endl;
    return 0;
}   