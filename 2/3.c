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

Node *sortList(Node *head){
    int n = lstSize(head);
    for (int i = 0; i < n; i++){
        Node *current = head; Node *prev = NULL;
        while(current->next != NULL){
            if (current->data > current->next->data){
                Node *temp = current->next->next;
                if (prev == NULL){
                    head = current->next;
                    current->next->next = current;
                    current->next = temp;
                    prev = head;
                }
                else{
                    prev->next = current->next;
                    current->next->next = current;
                    current->next = temp;
                    prev = prev->next;
                }
            }
            else{
                prev = current;
                current = current->next;
            }
        }
    }
    return head;
}

int main(){
    Node *head = readList();
    Node *sorted = sortList(head);
    printList(sorted);
    freeList(head);
    freeList(sorted);

}