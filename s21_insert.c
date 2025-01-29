#include <stdlib.h>

#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *new_str = NULL;

  if (src && str && (start_index <= s21_strlen(src))) {
    s21_size_t length_str = s21_strlen(str);
    s21_size_t length_src = s21_strlen(src);

    new_str = (char *)calloc(length_src + length_str + 1, sizeof(char));
    s21_memcpy(new_str, src, start_index);
    s21_memcpy(new_str + start_index, str, length_str);
    s21_memcpy(new_str + start_index + length_str, src + start_index,
               length_src - start_index);
    new_str[length_src + length_str] = '\0';
  }
  return new_str;
}
