#include "queue.h"

#include <stdlib.h>

struct element
{
    Info info;
    Element *next;
};

struct queue
{
    Element *start;
    Element *end;
    int size;
};

Queue *queue_create()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));

    if (queue != NULL)
    {
        queue->start = NULL;
        queue->end = NULL;
        queue->size = 0;
    }

    return queue;
}

void queue_enqueue(Queue *queue, Info info)
{
    if (queue == NULL)
        return;

    Element *element = (Element *)malloc(sizeof(Element));
    if (element == NULL)
        return;

    element->info = info;
    element->next = NULL;

    int queueIsEmpty = queue->end == NULL;
    if (queueIsEmpty)
    {
        queue->start = element;
    }
    else
    {
        queue->end->next = element;
    }

    queue->end = element;
    queue->size++;
}

int queue_dequeue(Queue *queue, Info *info)
{
    if (queue == NULL || queue->size == 0)
        return 0; // false

    Element *element = queue->start;
    queue->start = element->next;
    queue->size--;

    if (info != NULL)
        *info = element->info;

    if (queue->size == 0)
        queue->end = NULL;

    free(element);

    return 1; // true
}
