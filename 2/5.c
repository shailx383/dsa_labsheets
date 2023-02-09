#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Node_t{
    int data;
    struct Node_t *next;
};
typedef struct Node_t Node;

Node *createNode(int value){
    Node*new = malloc(sizeof(Node));
    assert(new != NULL);
    new->data = value;
    new->next = NULL;
    return new;
}

Node *addToList(Node *head, int value){
    Node *new = createNode(value);
    if (head == NULL){
        return new;
    }
    else{
        Node *current = head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = new;
        return new;
    }
}

Node *readList(){
    int n;
    scanf("%d", &n);
    Node* head = NULL;
    for (int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        if (head == NULL){
            head = addToList(head, x);
        }
        else{
            addToList(head, x);
        }
    }
    return head;
}

void printList(Node *head){
    Node* current = head;
    while (current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
    return;
}

void freeList(Node *head){
    Node *current, *next;
    current = head;
    while(current != NULL){
        next = current->next;
        free(current);
        current = next;
    }
}

int lstSize(Node* head){
    int size = 0;
    Node *current = head;
    while(current != NULL){
        size++;
        current = current->next;
    }
    return size;                
}

int getNodeData(Node *head, int pos){
    int index = 0;
    int val;
    Node *current = head;
    while(current != NULL){
        if (index == pos){
            val = current->data;
            break;
        }
        current = current->next;
        index++;
    }
    return val;
}

int isPalindrome(Node *head){
    int n = lstSize(head);
    Node *current = head;
    int count = 0;
    for (int i = 0; i < n; i++){
        if (head->data == getNodeData(current, n - i - 1)) count++;
        else return 0;
        head = head->next;
    }
    return (count == n);
}

int main(){
    Node *head = readList();
    int palin = isPalindrome(head);
    printf("%d\n", palin);
    freeList(head);

}