#include "s21_string.h"
#include "s21_string_format_handlers.h"

int s21_sprintf(char *str, const char *format, ...) {
  int current_index = 0;
  int applied_formats_count = 0;
  int temporary_index = 0;

  va_list argument;

  va_start(argument, format);

  while (format[current_index] != '\0') {
    if (format[current_index] == '%') {
      Token_t token = {0};

      temporary_index = current_index;

      current_index++;

      current_index =
          s21_parse_format_flags((s21_string_t)format, &token, current_index);

      current_index = s21_parse_format_width_and_accuracy(
          (s21_string_t)format, &token.width, &argument, current_index);

      if (s21_check_format_to_point(&current_index, format[current_index])) {
        current_index = s21_parse_format_width_and_accuracy(
            (s21_string_t)format, &token.accuracy, &argument, current_index);

        if (s21_check_accuracy_to_zero(token.accuracy))
          token.is_accuracy_zero = 1;
      }

      current_index = s21_parse_format_length((s21_string_t)format,
                                              &token.length, current_index);

      current_index = s21_parse_format_type((s21_string_t)format, &token,
                                            argument, current_index);

      for (int k = 0; token.token_buffer[k] != '\0';
           k++, applied_formats_count++)
        str[applied_formats_count] = token.token_buffer[k];

      if (token.token_buffer[0] == '\0' && token.type == 'c') {
        str[applied_formats_count] = '\0';
        applied_formats_count++;
      }

      if (temporary_index == (current_index - 1)) {
        str[applied_formats_count] = format[temporary_index];

        applied_formats_count++;

        temporary_index++;

        current_index = temporary_index;
      }
    } else {
      str[applied_formats_count] = format[current_index];

      current_index++;

      applied_formats_count++;
    }
  }

  str[applied_formats_count] = '\0';

  va_end(argument);

  return applied_formats_count;
}