#include <stdlib.h>
#include <stdio.h>
#define int long long

typedef struct Node_t
{
    int data;
    struct Node_t *prev;
    struct Node_t *next;
} Node;

int main()
{
    int n;
    scanf("%lld", &n);
    int *arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
    }
    Node *head = malloc(sizeof(Node));
    head->data = arr[0];
    Node *temp = head;
    head->next = NULL;
    head->prev = NULL;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > head->data)
        {
            Node *a = malloc(sizeof(Node));
            a->data = arr[i];
            a->next = NULL;
            temp->next = a;
            a->prev = temp;
            temp = a;
        }
        else
        {
            Node *p = malloc(sizeof(Node));
            p->data = arr[i];
            p->next = head;
            head->prev = p;
            p->prev= NULL;
            head = p;
        }
    }
    while (head != NULL)
    {
        printf("%lld ", head->data);
        head = head->next;
    }
    return 0;
}