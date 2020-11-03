#include "include/commander.h"

#include <stdlib.h>

commander_t* commander_new(int argc, char** argv){
  commander_t* commander = malloc(sizeof(struct COMMANDER_STRUCT));

  commander->argc = argc;
  commander->argv = argv;

  commander->tokens = vector_new(5);
  commander->programs = vector_new(5);
  commander->arguments = vector_new(5);
  commander->named_arguments = vector_new(5);

  return commander;
}

void commander_destroy(commander_t* commander) {
  vector_destroy(commander->tokens);
  vector_destroy(commander->programs);
  vector_destroy(commander->arguments);
  vector_destroy(commander->named_arguments);

  free(commander);
}


bool commander_run(commander_t* commander) {
  lexer_t* lexer = lexer_new(commander->argc, commander->argv);

  token_t* token = NULL;

  // Add all tokens into a tokens vector
  while((token = lexer_get_next_token(lexer)) != NULL)
  {
    vector_push(commander->tokens, token);
  }

  lexer_destroy(lexer);

  // Compute what

  return true;
}
