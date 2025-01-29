#include "s21_string.h"
#include "stdlib.h"

void *s21_to_upper(const char *str) {
  char *new_str = NULL;
  if (str) {
    s21_size_t length = s21_strlen(str);
    new_str = (char *)malloc(length + 1);
    if (new_str) {
      for (s21_size_t i = 0; i < length; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
          new_str[i] = str[i] - 32;
        } else {
          new_str[i] = str[i];
        }
      }
      new_str[length] = '\0';
    }
  }
  return (void *)new_str;
}
