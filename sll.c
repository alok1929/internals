#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct queue{
    int items[MAX];
    int front;
    int rear;
}
struct queue* create()
{
    struct queue* queue=(struct queue*)malloc(sizeof(struct queue));
    queue->front=-1;
    queue->rear=-1;
    return queue;
}

struct queue* enqueue()
{
    if(queue->rear=MAX-1)
    {
        printf("queue full\n");
        return;
    }
    if(queue->front==-1)
    {
        queue->front=0;
    }
    queue->rear++;
    queue->items[queue->rear]=value;

}
struct queue* dequeue()
{   int item;
    if(queue->front==-1)
    {
        printf("empty queue");
        return;
    }
    if(queue->front==queue->rear)
    {
        queue->front=-1;queue->rear=-1;
    }
    item=queue->items[queue->front];
    queue->front++;
}
struct queue* peak()
{
    int item;
    item=queue->items[queue->front];
    printf("%d",item);

}
struct queue* display(struct queue* queueu)
{
    int i;
    for(i=queue->front;i<=queue->rear;i++)
    {
        printf("%d",queue->items[i]);
    }
    printf("\n");
}

int main()
{
    struct queue* queue=create();
    enqueue(queue,10);
    enqueue(queue,10);
    enqueue(queue,10);
    enqueue(queue,10);
    display(queue)
}