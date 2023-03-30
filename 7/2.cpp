#include <iostream>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int search(int *arr, int strt, int end, char value)
{
	int i;
	for (i = strt; i <= end; i++){
		if (arr[i] == value) return i;
	}
    return -1;
}

TreeNode* buildTree(int *in, int *pre, int inStrt, int inEnd){
	static int preIndex = 0;
	if (inStrt > inEnd) return NULL;
	TreeNode* tNode = new TreeNode(pre[preIndex++]);
	if (inStrt == inEnd) return tNode;
	int inIndex = search(in, inStrt, inEnd, tNode->val);
	tNode->left = buildTree(in, pre, inStrt, inIndex - 1);
	tNode->right = buildTree(in, pre, inIndex + 1, inEnd);
	return tNode;
}

int tree_height(TreeNode* root) {
    if (!root) return 0;
    else {
        int left_height = tree_height(root->left);
        int right_height = tree_height(root->right);
        if (left_height >= right_height) return left_height + 1;
        else return right_height + 1;
    }
}

void print_current_level(TreeNode *root, int level){
    if (root == nullptr){
        for (int i = 0; i < pow(2, level - 1); i++) cout << "-1 ";
        return;
    }
    if (level == 1) cout << root->val << " ";
    else{
        print_current_level(root->left, level - 1);
        print_current_level(root->right, level - 1);
    }
}

void printTree(TreeNode *root){
    int height = tree_height(root);
    for (int i = 1; i <= height; i++) print_current_level(root, i);
}

int main()
{
	int n;
    cin >> n;
    int *prefix = new int[n];
    int *infix = new int[n];
    for (int i = 0; i < n; i++) cin >> prefix[i];
    for (int i = 0; i < n; i++) cin >> infix[i];
	TreeNode* root = buildTree(infix, prefix, 0, n - 1);
    int height = tree_height(root);
    cout << height << endl;
    int *arr = new int[int(pow(2, height)) - 1];
    arr[0] = root->val;
    printTree(root);
    cout << endl;
    return 0;
}
