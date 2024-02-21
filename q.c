#include<stdio.h>
#include<stdlib.h>
#define max 100

struct queue{
    int items[max];
    int rear;
    int front;
}
struct queue* create()
{
    struct queue* queue=(struct queue*)malloc(sizeof(struct queue));
    queue->front=-1;
    queue->rear=-1;
    return queue;
}
void enqueue(struct queue* queue,int value)
{
    if(queue->rear==max-1)
    {
        printf("queue is full");
        return;
    }
    if(queue->front==-1)
    {
        queue->front=0;
    }
    queue->rear++;
    queue->items[queue->front]=value;

}
int dequeue(struct queue* queue)
{
    int item;
    if(queue->front==-1)
    {
        printf("ded");
        return -1;
    }
    item=queue->item[queue->front];
    if(queue->front==queue->rear)
    {
        queue->front=-1;
        queue->rear=-1;

    }
    else{
        queue->front++;
    }
    return item;
}
int peak(struct queue* queue)
{
    if(queue->front==-1)
    {
        printf("cannot peak");
        return -1;
    }
    return queue->items[queue->front];
}