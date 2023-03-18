#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};
typedef struct Node Node;

Node* build_tree(int infix[], int prefix[], int n){

}

int main(){
    int n;
    cin >> n;
    int prefix[n];
    int infix[n];
    for (int i = 0; i < n; i++) cin >> prefix[i];
    for (int i = 0; i < n; i++) cin >> infix[i];
    return 0;
}