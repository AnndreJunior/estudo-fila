#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main()
{
    Queue *queue = queue_create();

    if (queue == NULL)
    {
        printf("Erro ao criar fila!\n");
        return 1;
    }

    queue_enqueue(queue, 5);
    queue_enqueue(queue, 6);
    queue_enqueue(queue, 7);

    Info *info = (Info *)malloc(sizeof(Info));
    for (int i = 0; i < 3; i++)
    {
        if (queue_dequeue(queue, info))
        {
            printf("Valor desenfileirado: %d\n", *info);
        }
        else
        {
            printf("Erro ao desenfileirar\n");
        }
    }

    return 0;
}