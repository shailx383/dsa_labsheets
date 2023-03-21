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

int binarySearch(int *arr, int l, int r, int x){
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

TreeNode* build_binary_tree(int *prefix, int *infix, int infix_start, int infix_end){
    static int prefix_index;
    if (infix_start < infix_start) return NULL;
    TreeNode* node = new TreeNode(prefix[prefix_index++]);
    if (infix_start == infix_end) return node;
    int pos_in_infix = binarySearch(infix, infix_start, infix_end, node->val);
    node->left = build_binary_tree(prefix, infix, infix_start, pos_in_infix - 1);
    node->right = build_binary_tree(prefix, infix, pos_in_infix + 1, infix_end);
    return node;
}

int main(){
    int n;
    cin >> n;
    int *prefix = new int[n];
    int *infix = new int[n];
    for (int i = 0; i < n; i++) cin >> prefix[i];
    for (int i = 0; i < n; i++) cin >> infix[i];
    TreeNode* bin_tree = build_binary_tree(prefix, infix, 0, n -1);
    // printing?
    return 0;
}