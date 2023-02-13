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
    assert(new != NULL);
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

int listSize(Node* head){
    int size = 0;
    Node *current = head;
    while(current != NULL){
        size++;
        current = current->next;
    }
    return size;                
}

int main(){
    Node *head = readList();
    int teamA = 0, teamB = 0;
    int A = 0, B = 0;
    Node *last;
    Node *first = head;
    Node *current = head;
    while (current->next != NULL){
        current = current->next;
    }
    last = current;
    teamA += first->data;
    first = first->next;
    A++;
    teamB += last->data;
    last = last->prev;
    B++;
    int strength = teamA + teamB;
    int result = A*10 + B;
    int n = listSize(head);
    for (int i = 0; i < 2 * n; i++){
        if (teamA == teamB){
            if (teamA + teamB > strength){
                strength = teamA + teamB;
                result = A*10 + B;
            }
            else{
                first = first->next;
                last = last->prev;
            }
        }
        else if (teamA > teamB){
            teamB += last->data;
            last = last->prev;
            B++;
        }
        else if (teamB > teamA){
            teamA += first->data;
            first = first->next;
            A++;
        }
        else if (last->data == first->data) break;
    }
    printf("%d %d", result/10, result%10);
}