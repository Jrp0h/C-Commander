#include "include/vector.h"

#include <stdlib.h>
#include <stdio.h>

// this is a pretty generic
// vector class
vector_t* vector_new(int size) {
  vector_t* vector = malloc(sizeof(struct VECTOR_STRUCT));

  if(vector == NULL)
  {
    fprintf(stderr, "Failed to allocate memory for vector\n");
    exit(1);
    return NULL;
  }

  vector->capacity = size;
  vector->current_index = 0;

  vector_resize(vector, size);

  return vector;
}

void vector_destroy(vector_t* vector)
{
  if(vector == NULL)
    return;

  free(vector->data);
  free(vector);
}

void vector_resize(vector_t* vector, int new_size)
{
  void** new_block = calloc(new_size, sizeof(void*));

  if(new_block == NULL)
  {
    fprintf(stderr, "Failed to reallocate memory for vector\n");
    exit(1);
    return;
  }
  
  for(int i = 0; i < vector->current_index && i < new_size; i++)
    new_block[i] = vector->data[i];

  free(vector->data);

  vector->capacity = new_size;
  vector->data = new_block;
}


int vector_size(vector_t* vector)
{
  return vector->current_index;
}

int vector_capacity(vector_t* vector)
{
  return vector->capacity;
}


void* vector_at(vector_t* vector, int index)
{
  if(index < 0 || index >= vector->current_index)
    return NULL;

  return vector->data[index];
}

void vector_remove_at(vector_t* vector, int index)
{
  if(index < 0 || index >= vector->current_index)
    return;

  for(int i = index; i < vector->current_index - 1; i++)
  {
    vector->data[i] = vector->data[i + 1];
  }

  vector->current_index--;
}

void vector_push(vector_t* vector, void* value)
{
  if(vector_need_realloc(vector))
    vector_resize(vector, (int)(vector->capacity + vector->capacity / 2));

  vector->data[vector->current_index++] = value;
}


void* vector_pop(vector_t* vector)
{
  if(vector->current_index <= 0)
    return NULL;
  else
    return vector->data[--vector->current_index];
}

void* vector_peek(vector_t* vector)
{
  if(vector->current_index <= 0)
    return NULL;
  else
    return vector->data[vector->current_index - 1];
}


bool vector_need_realloc(vector_t* vector){
  if(vector->current_index >= vector->capacity)
    return true;

  return false;
}

bool vector_is_empty(vector_t* vector)
{
  if(vector->current_index <= 0)
    return true;

  return false;
}
