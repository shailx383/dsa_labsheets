#include <bits/stdc++.h>
using namespace std;

bool check_win(int ans, int total){
	   return ans >= total-ans;
    }

int max_score(vector<int>&A,int total,int i,int j){
    if(i>j)return 0;
    return total-min(max_score(A,total-A[i],i+1,j),max_score(A,total-A[j],i,j-1));
}

bool winner(vector<int>& nums) {
        int total=0; 
        for(auto x:nums)
            total+=x;
        return check_win(max_score(nums,total,0,nums.size()-1),total);
    }

int main(){
    int n;
    cin >> n;
    vector <int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    if (winner(v)) cout << "Vidyateja" <<endl;
    else cout << "Hom" << endl;
    return 0;
}