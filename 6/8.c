#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100000
#define int long long

typedef struct
{
    int data[MAX_QUEUE_SIZE];
    int front, rear, size;
} Queue;

void initQueue(Queue *q)
{
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

int isQueueEmpty(Queue *q)
{
    return q->size == 0;
}

int isQueueFull(Queue *q)
{
    return q->size == MAX_QUEUE_SIZE;
}

void enqueue(Queue *q, int value){
    if (isQueueFull(q)){
        printf("Error: queue is full\n");
        exit(0);
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = value;
    q->size++;
}
int dequeue(Queue *q)
{
    if (isQueueEmpty(q))
    {
        printf("Error: queue is empty\n");
        exit(EXIT_FAILURE);
    }
    int value = q->data[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    q->size--;
    return value;
}
int josephus(Queue *q, int n, int k){
    for (int i = 1; i <= n; i++) enqueue(q, i);
    while (q->size > 1){
        for (int i = 0; i < k - 1; i++){
            int value = dequeue(q);
            enqueue(q, value);
        }
        dequeue(q);
    }
    return dequeue(q);
}
int main(){
    int n, k;
    scanf("%lld %lld", &n, &k);
    Queue q;
    initQueue(&q);
    int survivor = josephus(&q, n, k);
    printf("%lld\n", survivor);
    return 0;
}