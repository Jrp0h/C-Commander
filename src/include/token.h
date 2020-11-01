#ifndef TOKEN_H
#define TOKEN_H

typedef struct TOKEN_STRUCT {
  enum {
    TOKEN_LONG = 1,
    TOKEN_SHORT,
    TOKEN_VALUE
  } type;

  char* value;
} token_t;

token_t* token_new(int type, char* value);
void token_destroy(token_t* token);

#endif

