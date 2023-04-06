#include <iostream>
#include <cmath>
using namespace std;

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *l, TreeNode *r): val(x), left(l), right(r) {}
};

int search(int *arr, int start, int end, int elem){
    int i;
    for (int i = start; i <= end; i++){
        if (arr[i] == elem) return i;
    }
    return -1;
}

TreeNode *build_binary_tree(int *inorder, int *preorder, int in_start, int in_end){
    static int pre_index = 0;
    if (in_start > in_end) return NULL;
    TreeNode *node = new TreeNode(preorder[pre_index++]);
    if (in_start == in_end) return node;
    int in_index = search(inorder, in_start, in_end, node->val);
    node->left = build_binary_tree(inorder, preorder, in_start, in_index-1);
    node->right = build_binary_tree(inorder, preorder, in_index + 1, in_end);
    return node;
}

int tree_height(TreeNode *root){
    if (!root) return 0;
    else{
        int left_height = tree_height(root->left);
        int right_height = tree_height(root->right);
        return left_height >= right_height ? left_height + 1 : right_height + 1;
    }
}

void print_current_level(TreeNode *root, int level){
    if (root == nullptr){
        for (int i =0; i < pow(2, level - 1); i++) cout << -1 << " ";
        return;
    }
    if (level == 1) cout << root->val << " ";
    else{
        print_current_level(root->left, level - 1);
        print_current_level(root->right, level - 1);

    }
}

void print_tree(TreeNode *tree){
    int height = tree_height(tree);
    for (int i = 1; i <= height; i++) print_current_level(tree, i);
}

int main(){
    int n;
    cin >> n;
    int *inorder = new int[n];
    int *preorder = new int[n];
    for (int i = 0; i < n; i++) cin >> preorder[i];
    for (int i = 0; i < n; i++) cin >> inorder[i];
    TreeNode *binary_tree = build_binary_tree(inorder, preorder, 0, n-1);
    print_tree(binary_tree);
    return 0;
}