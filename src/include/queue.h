#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

#include "vector.h"

typedef struct QUEUE_STRUCT {
  void** data;
  vector_t* items;
} queue_t;

queue_t* queue_new(int size);
void queue_destroy(queue_t* queue);

int queue_size(queue_t* queue);

void queue_enqueue(queue_t* queue, void* value);
void* queue_dequeue(queue_t* queue);

bool queue_is_empty(queue_t* queue);

#endif
