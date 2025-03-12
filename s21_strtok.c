#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *buffer = S21_NULL;
  static int len = 0;
  if (str != S21_NULL) {
    buffer = str;
    len = s21_strlen(str);
  }
  char *out = S21_NULL;
  int lenOfToken = 0;
  int firstDelimer = 0;
  int secondDelimer = 0;
  out = buffer;
  if (len > 0) {
    for (int i = 0; buffer[i] != '\0'; i++) {
      if (!s21_strchr(delim, buffer[i])) {
        lenOfToken += 1;
      } else {
        buffer[i] = '\0';
        if (lenOfToken != 0) {
          secondDelimer = 1;
          break;
        } else {
          firstDelimer++;
        }
      }
    }
    if (lenOfToken <= 0 || buffer == S21_NULL) {
      out = S21_NULL;
    } else {
      out += firstDelimer;
      buffer += firstDelimer + lenOfToken + secondDelimer;
    }
  } else {
    out = S21_NULL;
  }
  len -= firstDelimer + lenOfToken + secondDelimer;
  return out;
}
