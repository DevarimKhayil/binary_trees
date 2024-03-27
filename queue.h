#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>

/**
 * struct queue_s - Queue data structure
 *
 * @data: Pointer to the data stored in the node
 * @next: Pointer to the next node in the queue
 */
typedef struct queue_s
{
    void *data;
    struct queue_s *next;
} queue_t;

/**
 * queue_push - Pushes an element onto the queue
 * @queue: Pointer to the queue
 * @data: Pointer to the data to be pushed
 */
void queue_push(queue_t **queue, void *data)
{
    queue_t *new_node = malloc(sizeof(queue_t));
    if (new_node == NULL)
        return;

    new_node->data = data;
    new_node->next = NULL;

    if (*queue == NULL)
    {
        *queue = new_node;
    }
    else
    {
        queue_t *temp = *queue;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new_node;
    }
}

/**
 * queue_peek - Retrieves the element at the front of the queue
 * @queue: Pointer to the queue
 * @return: Pointer to the data at the front of the queue
 */
void *queue_peek(const queue_t *queue)
{
    if (queue == NULL)
        return NULL;
    return queue->data;
}

/**
 * queue_pop - Removes the element at the front of the queue
 * @queue: Pointer to the queue
 */
void queue_pop(queue_t **queue)
{
    if (*queue == NULL)
        return;

    queue_t *temp = *queue;
    *queue = temp->next;
    free(temp);
}

/**
 * queue_empty - Checks if the queue is empty
 * @queue: Pointer to the queue
 * @return: 1 if empty, 0 otherwise
 */
int queue_empty(const queue_t *queue)
{
    return queue == NULL;
}

/**
 * queue_free - Frees the memory used by the queue
 * @queue: Pointer to the queue
 */
void queue_free(queue_t *queue)
{
    while (queue != NULL)
    {
        queue_t *temp = queue;
        queue = queue->next;
        free(temp);
    }
}

#endif /* QUEUE_H */
