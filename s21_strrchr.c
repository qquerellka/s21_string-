#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *result = S21_NULL;
  char *string = S21_NULL;
  unsigned char character = (unsigned char)(unsigned int)c;
  int index = 0;

  string = (char *)str;
  index = (int)s21_strlen(string);

  for (; index >= 0 && !result; index--)
    if (string[index] == character) result = &string[index];

  return result;
}
