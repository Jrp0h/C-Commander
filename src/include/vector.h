#ifndef VECTOR_H
#define VECTOR_H

#include <stdbool.h>

typedef struct VECTOR_STRUCT {
  void** data;
  int capacity;
  int current_index;
} vector_t;


vector_t* vector_new(int size);
void vector_destroy(vector_t* vector);

void vector_resize(vector_t* vector, int new_size);

int vector_size(vector_t* vector);
int vector_capacity(vector_t* vector);

void* vector_at(vector_t* vector, int index);
void vector_remove_at(vector_t* vector, int index);

void vector_push(vector_t* vector, void* value);

void* vector_pop(vector_t* vector);
void* vector_peek(vector_t* vector);

bool vector_need_realloc(vector_t* vector);
bool vector_is_empty(vector_t* vector);

#endif
