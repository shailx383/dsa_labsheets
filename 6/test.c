#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100000
#define int long long

struct Queue{
    int data[MAX_SIZE];
    int front, rear, size;
};
typedef struct Queue Q;

void initQueue(Q *q){
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

void enqueue(Q *q, int val){
    if (q->size == MAX_SIZE){
        printf("Error: Queue is full\n");
        exit(EXIT_FAILURE);
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->data[q->rear] = val;
    q->size++;
}

int dequeue(Q *q){
    if (q->size == 0){
        printf("Error: queue is empty\n");
        exit(EXIT_FAILURE);
    }
    int value = q->data[q->front];
    q->front= (q->front + 1) % MAX_SIZE;
    q->size--;
    return value;
}

int josephus(Q *q, int n, int k){
    for (int i = 1; i <=n; i++) enqueue(q, i);
    while (q->size > 1){
        for (int i =0; i < k -1; i++){
            int val = dequeue(q);
            enqueue(q, val);
        }
        dequeue(q);
    }
    return dequeue(q);
}

int main()
{
    int n, k;
    scanf("%lld %lld", &n, &k);
    Q q;
    initQueue(&q);
    printf("%lld", josephus(&q, n, k));
    return 0;
}
