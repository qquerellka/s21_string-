#include "s21_string_format_handlers.h"

int s21_parse_format_type(const s21_string_t format, Token_t *token,
                          va_list argument, int current_index) {
  int result_index = 0;
  int wide_character = 0;

  result_index = current_index;
  switch (format[current_index]) {
    case 'c':
      wide_character = 0;
      token->type = 'c';

      if (token->length == 'l')
        s21_get_wide_character(va_arg(argument, wchar_t), &wide_character);
      else
        wide_character = va_arg(argument, int);

      s21_handle_single_character(token, wide_character);

      current_index++;
      break;
    case 'd':
      token->type = 'd';
      if (token->length == 'l')
        s21_handle_integer(token, va_arg(argument, s21_integer_t));
      else
        s21_handle_integer(token, va_arg(argument, int));

      current_index++;
      break;
    case 'f':
      token->type = 'f';
      if (token->length == 'L')
        s21_handle_real(token, va_arg(argument, s21_real_t));
      else
        s21_handle_real(token, (s21_real_t)va_arg(argument, double));

      current_index++;
      break;
    case 's':
      token->type = 's';
      char wide_string[4096] = {0};
      if (token->length == 'l') {
        s21_get_wide_string(wide_string, va_arg(argument, wchar_t *));
        s21_handle_string(token, wide_string);
      } else {
        s21_string_t simple_string = va_arg(argument, s21_string_t);
        if (simple_string)
          s21_handle_string(token, simple_string);
        else {
          char null_string[4096] = "(null)\0";
          s21_handle_string(token, null_string);
        }
      }
      current_index++;
      break;
    case 'u':
      token->type = 'u';

      if (token->length == 'l')
        s21_handle_integer(token,
                           (s21_integer_t)va_arg(argument, unsigned long int));
      else
        s21_handle_integer(token,
                           (s21_integer_t)va_arg(argument, unsigned int));

      current_index++;
      break;
    case '%':
      token->type = '%';
      token->token_buffer[0] = '%';
      current_index++;
      break;
  }
  result_index = current_index;

  return result_index;
}

int s21_parse_format_flags(const s21_string_t format, Token_t *token,
                           int current_index) {
  int result_index = 0;

  while (format[current_index] == '-' || format[current_index] == '+' ||
         format[current_index] == ' ' || format[current_index] == '#' ||
         format[current_index] == '0') {
    switch (format[current_index]) {
      case '-':
        token->minus = 1;
        current_index++;
        break;
      case '+':
        token->plus = 1;
        current_index++;
        break;
      case ' ':
        token->space = 1;
        current_index++;
        break;
      case '#':
        token->sharp = 1;
        current_index++;
        break;
      case '0':
        token->zero = 1;
        current_index++;
        break;
    }
  }

  result_index = current_index;

  return result_index;
}

int s21_parse_format_width_and_accuracy(const s21_string_t format,
                                        int *token_value, va_list *argument,
                                        int current_index) {
  int result_index = 0;
  int is_star = 0;
  int order = 1;
  int value = 0;

  value = *token_value;

  if (format[current_index] == '*') {
    is_star = va_arg(*argument, int);
    if (is_star >= 0) {
      value = is_star;
    }
    current_index++;
  } else {
    while (format[current_index] >= '0' && format[current_index] <= '9') {
      value = value * order;
      value = value + (format[current_index] - '0');
      order = 10;
      current_index++;
    }
  }
  *token_value = value;
  result_index = current_index;

  return result_index;
}

int s21_parse_format_length(const s21_string_t format,
                            s21_string_t token_length, int current_index) {
  int result_index = 0;

  result_index = current_index;

  switch (format[current_index]) {
    case 'h':
      *token_length = 'h';
      current_index++;
      break;
    case 'L':
      *token_length = 'L';
      current_index++;
      break;
    case 'l':
      *token_length = 'l';
      current_index++;
      break;
  }

  result_index = current_index;

  return result_index;
}

int s21_check_format_to_point(int *current_index,
                              const unsigned char character) {
  int result = 0;
  int index = 0;

  index = *current_index;

  if (character == '.') {
    index++;
    *current_index = index;
    result = 1;
  }

  return result;
}

int s21_check_accuracy_to_zero(int accuracy) {
  int result = 0;

  if (accuracy == 0) result = 1;

  if (accuracy == '\0') result = 1;

  return result;
}