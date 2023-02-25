#include "stdio.h"
#include "malloc.h"
#include "tokenizer.h"

int space_char(char c)
{
  if (c == ' '|| c == '\t') return 1;
  else return 0;
}

int non_space_char(char c)
{
  if (!space_char(c) && c != '\0') return 1;
  else return 0;
}

char *word_start(char *str)
{
  while (*str != '\0') {
    if (non_space_char(*str)) return str;
    str++;
  }
  return str;
}

char *word_terminator(char *word)
{
  while (*word != '\0') {
    if (space_char(*word)) return word;
    word++;
  }
  return word;
}

int count_words(char *str)
{
  int c = 0;
  if (*str == '\n') return c;
  while(*str != '\0') {
    str = word_start(str);
    if (*str) c++;
    str = word_terminator(str);
  }
  return c;
}

char *copy_str(char *inStr, short len)
{
  char *scopy = malloc((len + 1) * sizeof(char)), c;
  int sindex = 0;
  do {
    c = *(scopy+sindex) = *(inStr+sindex);
    sindex++;
  } while (c);
  return scopy;
}

int word_len(char *w)
{
  char *wc = w;
  wc = word_terminator(wc);
  return wc - w;
}

char **tokenize(char *str)
{
  int c = count_words(str);
  char **tokens[c];
  while (*str != '\0') {
    str = word_start(str);
    int tindex = 0;
    if (*str != '\0') {
      char *sc = str;
      sc = word_terminator(sc);
      int len = sc - str;
      **(tokens+tindex) = copy_str(str,len);
      str = sc;
      tindex++;
    }
  }
  return *tokens;
}

void print_tokens(char **tokens)
{
  while(**tokens != '\0') {
    puts(*tokens);
    **tokens++;
  }
}
