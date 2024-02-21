#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

// Function to create a new queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;  // Initialize front index
    queue->rear = -1;   // Initialize rear index
    return queue;
}

// Function to add an element to the queue (enqueue)
void enqueue(struct Queue* queue, int value) {
    if (queue->rear == MAX_SIZE - 1) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->rear++;
    queue->items[queue->rear] = value;
    printf("%d enqueued to the queue.\n", value);
}

// Function to remove an element from the queue (dequeue)
int dequeue(struct Queue* queue) {
    int item;
    if (queue->front == -1) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    item = queue->items[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front++;
    }
    printf("%d dequeued from the queue.\n", item);
    return item;
}

// Function to retrieve the front element of the queue (peak)
int peak(struct Queue* queue) {
    if (queue->front == -1) {
        printf("Queue is empty. Cannot peak.\n");
        return -1;
    }
    return queue->items[queue->front];
}

// Function to display the queue
void display(struct Queue* queue) {
    int i;
    if (queue->front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements are: ");
    for (i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->items[i]);
    }
    printf("\n");
}

int main() {
    struct Queue* queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    display(queue);

    dequeue(queue);
    dequeue(queue);

    display(queue);

    printf("Front element of the queue: %d\n", peak(queue));

    return 0;
}
