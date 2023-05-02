#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

-

TreeNode *bst_to_gst(TreeNode *tree){
    
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i =0; i < n; i++) cin >> arr[i];
    TreeNode *tree = build_tree(arr, n, 1);
   

}