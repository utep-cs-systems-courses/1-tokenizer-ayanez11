#include "stdio.h"
#include "tokenizer.h"

int main()
{
  char tokens[30];
  printf("> ");
  fgets(tokens, 30, stdin);
  printf("You entered \n");
  char *s = tokens;
  char **t = tokenize(s);
  print_tokens(t);
  
 done:
  return 0;
}
