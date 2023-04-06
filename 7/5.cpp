#include <iostream>
#include <stack>
using namespace std;

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *l, TreeNode *r): val(x), left(l), right(r) {}
};

TreeNode *build_binary_tree(int arr[], int n, int index){
        if (index > n || arr[index - 1] == -1) return nullptr;
        else{
            TreeNode *node = new TreeNode(arr[index - 1], build_binary_tree(arr, n, 2 * index), build_binary_tree(arr, n, 2 * index + 1));
            return node;
        }
}

int kth_largest(TreeNode *tree, int k){
    int count = 0, elem = 0;
    stack <TreeNode*> stk;
    TreeNode *curr = tree;
    while (curr != nullptr || !stk.empty()){
        while (curr != nullptr){
            stk.push(curr);
            curr = curr->right;
        }
        curr = stk.top();
        stk.pop();
        elem = curr->val;
        count++;
        if (count == k) return elem;
        curr = curr->left;
    }
    return -1;
}

int main(){
    int n, k;
    cin >> n;
    int arr[n];
    for (int i =0; i < n; i++) cin >> arr[i];
    cin >> k;
    TreeNode *tree = build_binary_tree(arr, n, 1);
    cout << kth_largest(tree, k) << endl;
    return 0;
}