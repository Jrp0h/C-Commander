#include "include/token.h"

#include <stdlib.h>

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
