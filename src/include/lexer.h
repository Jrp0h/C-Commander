#ifndef LEXER_H
#define LEXER_H

#include <stdbool.h>

#include "token.h"
#include "queue.h"

typedef struct LEXER_STRUCT {
  int argc;
  char** argv;

  int a;
  int i;
  char c;

  bool done;
  bool EOL;

  queue_t* queue;

} lexer_t;

lexer_t* lexer_new(int argc, char** argv);
lexer_t* lexer_copy(lexer_t* lexer);
void lexer_destroy(lexer_t* lexer);

void lexer_advance(lexer_t* lexer);
char lexer_peek(lexer_t* lexer);

token_t* lexer_get_next_token(lexer_t* lexer);

token_t* lexer_collect_long(lexer_t* lexer);
token_t* lexer_collect_value(lexer_t* lexer);
token_t* lexer_collect_short(lexer_t* lexer);

char* lexer_get_current_char_as_string(lexer_t* lexer);

#endif
