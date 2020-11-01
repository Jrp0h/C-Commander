#include "include/queue.h"

#include <stdlib.h>
#include <stdio.h>


queue_t* queue_new(int size) {
  queue_t* queue = malloc(sizeof(struct QUEUE_STRUCT));

  if(queue == NULL)
  {
    fprintf(stderr, "Failed to allocate memory for queue\n");
    exit(1);
  }

  queue->items = vector_new(size);

  return queue;
}

void queue_destroy(queue_t* queue) {
  if(queue == NULL)
    return;

  vector_destroy(queue->items);
  free(queue);
}

int queue_size(queue_t* queue)
{
  return queue->items->current_index;
}


void queue_enqueue(queue_t* queue, void* value)
{
  vector_push(queue->items, value);
}

void* queue_dequeue(queue_t* queue)
{
  void* item = vector_at(queue->items, 0);
  vector_remove_at(queue->items, 0);
  return item;
}


bool queue_is_empty(queue_t* queue)
{
  return vector_is_empty(queue->items);
}
