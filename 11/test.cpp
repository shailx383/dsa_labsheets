#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums, bool turn ,int i, int j ){
    if(i>j) return 0;
    if(turn) return max(nums[i]+solve(nums,false,i+1,j),nums[j]+solve(nums,false,i,j-1));    
    else return min(solve(nums,true,i+1,j),solve(nums,true,i,j-1));
}

int x_minus_y(vector<int>& nums) {
    int totalSum=0;
    for(int i=0;i<nums.size();i++)totalSum+=nums[i];
    int sum1 = solve(nums,true,0,nums.size()-1);
    int sum2 = totalSum-sum1;
    return sum1 - sum2;
}

int main(){
    int n;
    cin >> n;
    vector <int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    cout << x_minus_y(v) << endl;
    return 0;
}