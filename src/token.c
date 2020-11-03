#include "include/token.h"

#include <stdlib.h>
#include <string.h>

token_t* token_new(int type, char* value) {
  
  token_t* token = malloc(sizeof(struct TOKEN_STRUCT));

  token->type = type;
  token->value = value;

  return token;
}

void token_destroy(token_t* token) {
  if(token == NULL)
    return;

  free(token);
}

char* token_type_as_string(token_t* token) {

  if(token->type == TOKEN_LONG)
    return "LONG";
  else if(token->type == TOKEN_SHORT)
    return "SHORT";
  else if (token->type == TOKEN_VALUE)
    return "VALUE";

  return strcat("UNKNOWN TYPE: ", token->value);
}
