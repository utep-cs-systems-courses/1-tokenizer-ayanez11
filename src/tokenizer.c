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
  if (!space_char(c)) return 1;
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
  } while (sindex < len);
  *(scopy+sindex) = '\0'; //adds null terminator to string
  return scopy;
}

char **tokenize(char *str)
{
  int i = count_words(str);
  char **t = malloc((i + 1) * sizeof(char*));
  int tindex = 0;
  while (*str != '\0') {
    str = word_start(str);
    char *sc = str;
    sc = word_terminator(sc);
    int len = sc - str;
    *(t+tindex) = &(*copy_str(str,len));
    str = sc;
    tindex++;
  }
  char *p;
  *p = 'c';
  *(t+tindex) = &(*copy_str(" ",1));// used to track end of array
  return t;
}

void print_tokens(char **tokens)
{
  int i = 0;
  while(**tokens != ' ') {
    printf("t[%d] = %s\n", i, *tokens);
    *tokens++;
    i++;
  }
}

void free_tokens(char **tokens)
{
  char **t;
  t = tokens;
  while(**t != ' ') {
    free(*t);
    *t++;
  }
  free(*t);// removes pointer to ' '
  free(tokens);
}
