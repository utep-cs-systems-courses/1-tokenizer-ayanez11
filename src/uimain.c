#include "stdio.h"
#include "tokenizer.h"

int main()
{
  char tokens[20];
  printf("> ");
  fgets(tokens, 20, stdin);
  printf("You entered ");
  char *t;
  t = &(**tokenize(tokens));
  puts(t);
  //print_tokens(t);
 done:
  return 0;
}
