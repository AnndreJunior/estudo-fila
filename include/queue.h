#ifndef __queue__h
#define __queue__h

typedef int Info;
typedef struct queue Queue;
typedef struct element Element;

Queue *queue_create();
void queue_enqueue(Queue *queue, Info info);
int queue_dequeue(Queue *queue, Info *info);

#endif