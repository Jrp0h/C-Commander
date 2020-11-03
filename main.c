#include "include/lexer.h"

#include <stdio.h>

int main(int argc, char** argv) {
   lexer_t* lexer = lexer_new(argc, argv);

   token_t* token = (void*)0;

   while((token = lexer_get_next_token(lexer)) != NULL)
   {
      printf("Token(%s, \"%s\")\n", token_type_as_string(token), token->value);  
   }

   lexer_destroy(lexer);
}

/////////////////////////////////////////////////////
//////////////// EXAMPLE CODE ///////////////////////
/////////////////////////////////////////////////////

/* void crypto_key_set(commander_data_t* data); */
/* void crypto_key_view(commander_data_t* data); */
/* void crypto_key_buy(commander_data_t* data); */

/* int main(int argc, char** argv) */
/* { */
   // Commander
   // argc, argv
   // which takes programs
   // // Program
   // // * key
   // // * Programs, array of nested programs, can be null
   // // * function pointer with ProgramData object
   // // * min values = 0
   // // * max values = 0
   // // | set_offset
   // // which takes arguments
   // // // * name
   // // which takes named arguments
   // // // * name
   // // // * char? = can be null
   // // // * value = true/false
   // // // * default? = can be null


   // crypto
   // // crypto key
   // // // crypto key set <key>
   // // // crypto key view --encode base64
   // // -------------
   // // crypto buy <currency> <amount>

   // (crypto)
   /* commander_t* cmd = commander_new(argc, argv); */

   // crypto (key)
   /* program_t* key = program_new("key", NULL); */

   // crypto key (set)
   /* program_t* set_key = program_new("set", crypto_key_set); */

   // crypto key set (<key>)
   /* program_add_argument(set_key, argument_new("key")); */

   // Register to program
   /* program_add_program(key, set_key); */
   
   // crypto key (view)
   /* program_t* view_key = program_new("view", crypto_key_view); */

   // crypto key --encode base64
   // crypto key -e base64
   /* program_add_named_argument(view_key, named_argument_new("encode", "e", true, NULL)); */

   // Register to program
   /* program_add_program(key, view_key); */

   // Register it
   /* commander_add_program(cmd, key); */

   // crypto (buy)
   /* program_t* buy = program_new("buy", crypto_key_buy); */

   // crypto buy (<currency>)
   /* program_add_argument(buy, argument_new("currency")); */

   // crypto buy <currency> (<amount>)
   /* program_add_argument(buy, argument_new("amount")); */

   // Register it
   /* commander_add_program(buy, key); */


   // Run
   /* commander_run(cmd); */

/* } */

/* void crypto_key_set(commander_data_t* data) { */
   /* // get key value */
   /* // not null, because key is an argument which is non-optional */
   /* char* key = commander_data_get_value(data, "key"); */
/* } */

/* void crypto_key_view(commander_data_t* data) { */
   /* char* encoding = commander_data_get_value(data, "encoding"); */

   /* // no encoding passed */
   /* if(encoding == NULL) */
      /* exit(1); */
/* } */
/* void crypto_key_buy(commander_data_t* data){ */
   /* // not null, because currency is an argument which is non-optional */
   /* char* currency = commander_data_get_value(data, "currency"); */
   /* // not null, because amount is an argument which is non-optional */
   /* char* amount = commander_data_get_value(data, "amount"); */
/* } */
