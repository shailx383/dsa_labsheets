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

TreeNode *build_tree(int arr[], int n, int index){
    if (index > n || arr[index-1] == -1) return nullptr;
    else{
        TreeNode *node = new TreeNode(arr[index - 1]);
        node->left = build_tree(arr, n, index * 2);
        node->right = build_tree(arr, n, index * 2 + 1);
        return node;
    }
}

int kth_largest_element(TreeNode *tree, int k){
    TreeNode* current_node = tree;
    while (current_node != nullptr) current_node = current_node->right;
    //if (current_node)
}

int main(){
    int n, k;
    cin >> n;
    int arr[n];
    for (int i =0; i < n; i++) cin >> arr[i];
    cin >> k;
    TreeNode *tree = build_tree(arr, n, 1);
    return 0;
}