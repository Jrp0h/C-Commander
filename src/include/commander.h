#ifndef COMMANDER_H
#define COMMANDER_H

#include <stdbool.h>

#include "lexer.h"
#include "vector.h"

typedef struct COMMANDER_STRUCT {
  int argc;
  char** argv;

  vector_t* tokens;
  vector_t* programs;
  vector_t* arguments;
  vector_t* named_arguments;

} commander_t;

commander_t* commander_new(int argc, char** argv);
void commander_destroy(commander_t* commander);

bool commander_run(commander_t* commander);

#endif
