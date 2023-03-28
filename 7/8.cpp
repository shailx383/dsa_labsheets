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

TreeNode *beautiful_bst(TreeNode *root, int l, int r)
{
    if (root == nullptr) return nullptr;
    if (root->val < l) return beautiful_bst(root->right, l, r);
    if (root->val > r) return beautiful_bst(root->left, l, r);
    root->left = beautiful_bst(root->left, l, r);
    root->right = beautiful_bst(root->right, l, r);
    return root;
}

void print_post_order(TreeNode *tree){
    if (tree == nullptr) return;
    print_post_order(tree->left);
    print_post_order(tree->right);
    cout << tree->val << " ";
}

int main(){
    int n, l, r;
    cin >> n >> l >> r;
    int arr[n];
    for (int i =0; i < n ; i++) cin >> arr[i];
    TreeNode *bst = build_tree(arr, n, 1);
    TreeNode *beautified_bst = beautiful_bst(bst, l, r);
    print_post_order(beautified_bst);
    cout << endl;
    return 0;
}