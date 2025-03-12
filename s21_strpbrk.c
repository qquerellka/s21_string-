#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *result = S21_NULL;
  char *string_1 = (char *)str1;

  while (*string_1 && !result) {
    char *string_2 = (char *)str2;
    while (*string_2) {
      if (*string_1 == *string_2) {
        result = (char *)string_1;
        string_2 = "";
      } else {
        string_2++;
      }
    }
    string_1++;
  }

  return result;
}
