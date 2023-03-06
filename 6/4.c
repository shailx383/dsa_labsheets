#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    int *next;
};
typedef struct Node Node;

Node *enqueue(Node *q, int val){
    Node *new;
    new->data = val;
    new->next = NULL;
    if (q == NULL) return new;
    else{
        Node *curr = q;
        while (curr->next != NULL) curr = curr->next;
        curr->next = new;
        return q;
    } 
}

Node *dequeue(Node *q){
    if (q->next == NULL) return NULL;
    else{
        Node *temp = q->next;
        free(q);
        return temp;
    }
}

int *first_nonrepeating_integer(int arr[], int n){
    int ans[n];
    int *freq = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) freq[i] = 0;
    Node *Q = NULL;
    for (int i = 0 ; i < n; i++){
        if (freq[arr[i]] == 0){
            freq[arr[i]]++;
            Q = enqueue(Q, arr[i]);
            while(freq[Q->data] == 1){
                freq[Q->data]--;
                Q = dequeue(Q);
            }
        }
        else{
            if (Q->data == arr[i]){
                Q = dequeue(Q);
            }
        }
        if (Q != NULL) ans[i] = Q->data;
        else ans[i] = -1; 
    }

}

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i =0; i < n; i++ ) scanf("%d", &arr[i]);
    int *result = first_nonrepeating_integer(arr, n);
    for (int i = 0; i < n; i++) printf("%d ", result[i]);
    return 0;
}