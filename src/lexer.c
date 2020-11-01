#include "include/lexer.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


lexer_t* lexer_new(int argc, char** argv)
{
  lexer_t* lexer = malloc(sizeof(struct LEXER_STRUCT));

  if(lexer == NULL)
  {
    fprintf(stderr, "Failed to allocate memory for lexer\n");
    exit(1);
  }

  if(argc <= 1) {
    lexer->done = true;
    lexer->EOL = true;
  }
  else {
    lexer->i = 0;
    lexer->a = 1;
    lexer->argc = argc;
    lexer->argv = argv;

    lexer->c = argv[lexer->a][lexer->i];
    
    lexer->done = false;
    lexer->EOL = false;
  }

  lexer->queue = queue_new(5);

  return lexer;
}

lexer_t* lexer_copy(lexer_t* lexer) {
  lexer_t* newlexer = malloc(sizeof(struct LEXER_STRUCT));

  newlexer->i = lexer->i;
  newlexer->a = lexer->a;
  newlexer->argc = lexer->argc;
  newlexer->argv = lexer->argv;
  newlexer->c = lexer->c;
  newlexer->done = lexer->done;
  newlexer->EOL = lexer->EOL;

  return newlexer;
}

void lexer_destroy(lexer_t* lexer){
  if(lexer == NULL)
    return;
  queue_destroy(lexer->queue);
  free(lexer);
}

void lexer_advance(lexer_t* lexer) {
  lexer->EOL = false;

  if(lexer->done)
    return;

  // End of current argument
  if(lexer->i + 1 >= strlen(lexer->argv[lexer->a]) || lexer->c == '\0') {
    lexer->EOL = true;
    
    // End of arguments list
    if(lexer->a + 1 >= lexer->argc) {
      lexer->done = true;
      return;
    }

    lexer->a += 1;
    lexer->i = -1;
  }

  lexer->i += 1;
  lexer->c = lexer->argv[lexer->a][lexer->i];
}

char lexer_peek(lexer_t* lexer) {

  lexer_t* copy = lexer_copy(lexer);
  lexer_advance(copy);
  char c = copy->c;
  lexer_destroy(copy);

  return c;
}

token_t* lexer_get_next_token(lexer_t* lexer){
  
  if(!queue_is_empty(lexer->queue))
  {
    return queue_dequeue(lexer->queue);
  }

  while(!lexer->done) {
    if(lexer->c == '-') {

      if(lexer_peek(lexer) == '-')
        return lexer_collect_long(lexer);

      else 
        return lexer_collect_short(lexer);

    }
    else 
      return lexer_collect_value(lexer);
  }
  return NULL;
}

token_t* lexer_collect_long(lexer_t* lexer) {

  // Skip dashes(--)
  lexer_advance(lexer);
  lexer_advance(lexer);
  
  char* value = malloc(sizeof(char));

  while(!lexer->EOL && !lexer->done)
  {
    char* s = lexer_get_current_char_as_string(lexer);
    value = realloc(value, (strlen(value) + strlen(s) + 1) * sizeof(char));
    strcat(value, s);
    lexer_advance(lexer);
  }

  lexer->EOL = false;

  return token_new(TOKEN_LONG, value);
}

token_t* lexer_collect_value(lexer_t* lexer) {

  char* value = malloc(sizeof(char));
  value[0] = '\0';

  while(!lexer->EOL && !lexer->done)
  {
    char* s = lexer_get_current_char_as_string(lexer);
    value = realloc(value, (strlen(value) + strlen(s) + 1) * sizeof(char));
    strcat(value, s);

    lexer_advance(lexer);
  }

  lexer->EOL = false;

  return token_new(TOKEN_VALUE, value);
}

token_t* lexer_collect_short(lexer_t* lexer) {

  // Skip dash(-)
  lexer_advance(lexer);

  while(!lexer->EOL && !lexer->done)
  {
    /* tokens = realloc(tokens, (++size) * sizeof(struct TOKEN_STRUCT)); */
    token_t* token = token_new(TOKEN_SHORT, lexer_get_current_char_as_string(lexer));
    queue_enqueue(lexer->queue, token);
    lexer_advance(lexer);
  }

  lexer->EOL = false;

  return queue_dequeue(lexer->queue);
}

char* lexer_get_current_char_as_string(lexer_t* lexer) {
  char* str = malloc(sizeof(char) * 2);

  str[0] = lexer->c;
  str[1] = '\0';

  return str;
}
