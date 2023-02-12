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
    return new;
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

int existsInList(Node *head, int value){
    Node *current = head;
    while (current!=NULL){
        if (current->data == value){
            return 1;
            break;
        }
        current = current->next;
    }
    return 0;
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
        else if (i == 5) break;
        else if (i == 6){
            int song;
            scanf("%d", &song);
            if (!existsInList(playlist, song)){
                Node *newSong = createNode(song);
                Node *temp = currentSong->next;
                currentSong->next = newSong;
                newSong->next = temp;
                temp->prev = newSong;
                newSong->prev = currentSong;
            }
            else{
                playlist = deleteElement(playlist, song);
                Node *newSong = createNode(song);
                Node *temp = currentSong->next;
                currentSong->next = newSong;
                newSong->next = temp;
                temp->prev = newSong;
                newSong->prev = currentSong;
            }
        }
    }
   freeList(playlist); 
}
