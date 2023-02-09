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

Node *mergeLists(Node *head1, Node *head2){
    Node *current1 = head1;
    Node *current2 = head2;
    Node *merged = NULL;
    while(1){
        if (current1 == NULL){
            while(current2 != NULL){
                addToList(merged, current2->data);
                current2 = current2->next;
            }
            break;
        }
        else if (current2 == NULL){
            while(current1 != NULL){
                addToList(merged, current1->data);
                current1 = current1->next;
            }
            break;
        }
        if (current1->data < current2->data){
            if (merged == NULL){
                merged = addToList(merged, current1->data);
                current1 = current1->next;
            }
            else{
                addToList(merged, current1->data);
                current1 = current1->next;


            }
        }
        else{
            if (merged == NULL){
                merged = addToList(merged, current2->data);
                current2 = current2->next;
            }
            else{
                addToList(merged, current2->data);
                current2 = current2->next;

            }
        }
    }
    return merged;
}

int main(){
    Node *head1 = readList();
    Node *head2 = readList();
    Node *merged = mergeLists(head1, head2);
    printList(merged);
    freeList(head1);
    freeList(head2);
    freeList(merged);
}