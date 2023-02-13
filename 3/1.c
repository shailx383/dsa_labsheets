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

int main(){
    Node *playlist = readList();
    Node *currentSong = playlist;
    while(1){
        int i;
        scanf("%d", &i);
        if (i == 1){
            int newSong;
            scanf("%d", &newSong);
            addToList(playlist, newSong);
        }
        else if (i == 2) printf("Current song: %d\n", currentSong->data);
        else if (i == 3) {
            if (currentSong->next != NULL){
                currentSong = currentSong->next;
            }
        }
        else if (i == 4){
            if (currentSong->prev != NULL){
                currentSong = currentSong->prev;
            }
        }
        else break;
    }
   freeList(playlist); 
}
