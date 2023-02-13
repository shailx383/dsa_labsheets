#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Node_t{
    int data;
    struct Node_t *next;
    struct Node_t *prev;
};
typedef struct Node_t Node;

Node *createNode(int value){
    Node *new = malloc(sizeof(Node));
    new->data = value;
    new->prev = NULL;
    new->next = NULL;
}

Node *addToList(Node *head, int value){
    Node *new = createNode(value);
    if (head == NULL){
        return new;
    }
    else{
        Node *current = head;
        while (current->next != NULL){
            current = current->next;
        }
        current->next = new;
        new->prev = current;
        return new;
    }
}

Node *readList(){
    int n;
    scanf("%d", &n);
    Node *head = NULL;
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
    Node *current = head;
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

Node *deleteElement(Node *head, int value){
    Node *current = head;
    while (current != NULL){
        if (current->data == value){
            if (current->prev == NULL){
                current->next->prev = NULL;
                return current->next;
            }
            else if (current->next == NULL){
                current->prev->next = NULL;
                return head;
            }
            else{
                Node *temp = current->next;
                current->prev->next = current->next;
                current->next->prev = current->prev;
                return head;
            }
        }
        else{
            current = current->next;
        }
    }
}

Node *rotateRight(Node *head){
    Node *current = head;
    while (current->next != NULL) current = current->next;
    Node *last = current;
    Node *secondLast = current->prev;
    secondLast->next = NULL;
    last->next = head;
    last->prev = NULL;
    return last;
}

int main(){
    int n;
    int k;
    scanf("%d", &n);
    scanf("%d", &k);
    Node *head = NULL;
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
    for (int i = 0; i < k; i++){
        head = rotateRight(head);
    }
    printList(head);
    freeList(head);
}