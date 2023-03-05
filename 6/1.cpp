#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        int curr_min;
};

class MinStack{
    private:
        Node *top;

    public:
        MinStack(){
            top = NULL;
        }
        
        void push(int val){
            Node *temp = new Node();
            temp->data = val;
            temp->next = top;
            if (top) temp->curr_min = min(val, top->curr_min);
            else temp->curr_min = val;
            top = temp;
        }

        void pop(){
            Node *temp;
            if (top == NULL){
                cout << "Underflow" << endl;
            }
            else{
                temp = top;
                top = top->next;
                free(temp);
            }
        }

        int getTop(){
            return top->data;
        }

        int getMin(){
            return top->curr_min;
        }
};

int main(){
    int n;
    cin >> n;
    MinStack stk;

    for (int i = 0; i < n; i++){
        int val;
        cin >> val;
        stk.push(val);
    }

    int m;
    cin >> m;

    for (int i = 0; i < m ; i++){
        int op;
        cin >> op;
        if (op == 1){
            int val;
            cin >> val;
            stk.push(val);
        }
        else if (op == 2){
            stk.pop();
        }
        else if (op == 3){
            cout << "__" << stk.getTop() << "__" << endl;
        }
        else{
            cout << "__" << stk.getMin() << "__" << endl;
        }
    }
    return 0;
}