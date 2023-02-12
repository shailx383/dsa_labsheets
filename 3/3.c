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

int f(Node *head, int sum)
{
    Node *start = head;
    Node *current = head;
    while(current->next != NULL){
        current = current->next;
    }
    Node *end = current;
    while(end->data != start->data){
        int current_sum = end->data + start->data;
        if (sum > current_sum){
            start = start->next;
        }
        else if (sum < current_sum){
            end = end->prev;
        }
        else return 1;
    }
    return 0;
}

int main(){
    int k;
    scanf("%d", &k);
    Node *head = readList();
    printf("%d", f(head, k));
    freeList(head);
}