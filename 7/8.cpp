
#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *l, TreeNode *r): val(x), left(l), right(r){}
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

TreeNode *beautiful_bst(TreeNode *tree, int l, int r){
    if (tree == nullptr) return nullptr;
    if (tree->val < l) return beautiful_bst(tree->right, l, r);
    if (tree->val > r) return beautiful_bst(tree->left, l, r);
    tree->left = beautiful_bst(tree->left, l, r); 
    tree->right = beautiful_bst(tree->right, l ,r); 
    return tree;
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
    for (int i =0; i < n; i++) cin >> arr[i];
    TreeNode *tree = build_tree(arr, n, 1);
    TreeNode *b_bst = beautiful_bst(tree, l, r);
    print_post_order(b_bst);
    cout << endl;
    return 0;
}