#include "s21_string_format_handlers.h"

void s21_handle_single_character(Token_t *token, int character) {
  int current_index = 0;
  int current_filling_width = 0;
  int current_filler_character = 0;
  int current_token_character = 0;
  s21_string_t current_filling_part_of_buffer = S21_NULL;

  current_token_character = character;

  if (token->width) {
    current_filling_part_of_buffer = token->token_buffer;

    if (token->minus) {
      current_filling_width = token->width;
      current_filler_character = ' ';
    } else {
      current_filling_width = token->width - 1;

      if (token->zero)
        current_filler_character = '0';
      else
        current_filler_character = ' ';
    }
  }

  if (current_filling_width > 2) {
    current_index += current_filling_width;
    s21_memset(current_filling_part_of_buffer, current_filler_character,
               current_filling_width);
  }

  if (token->minus)
    token->token_buffer[0] = current_token_character;
  else
    token->token_buffer[current_index] = current_token_character;

  current_index++;
  token->token_buffer[current_index] = '\0';
}

void s21_handle_string(Token_t *token, s21_string_t string) {
  int string_width = 0;
  int count_limit = 0;
  int index = 0;

  if (token->accuracy < (int)s21_strlen(string) && token->accuracy > 0) {
    string_width = token->accuracy;
  } else if (token->accuracy < 0 || token->is_accuracy_zero == 1) {
    string_width = 0;
  } else {
    string_width = s21_strlen(string);
  }

  if (token->width < string_width && token->width > 0) {
    count_limit = 0;
  } else {
    count_limit = token->width - string_width;
  }

  if (token->width > 0 && token->minus == 0 && token->zero == 0)
    for (int i = 0; i < count_limit; index++, i++)
      token->token_buffer[index] = ' ';

  if (token->zero == 1 && token->minus == 0)
    for (int i = 0; i < count_limit; index++, i++)
      // token->token_buffer[index] = '0';
      token->token_buffer[index] = ' ';

  for (int i = 0; i < string_width; index++, i++)
    token->token_buffer[index] = string[i];

  if (s21_complete_token_buffer(token, index, count_limit))
    index += count_limit;

  token->token_buffer[index] = '\0';
}

void s21_handle_integer(Token_t *token, s21_integer_t value) {
  char buffer[4096] = {'\0'};
  s21_size_t buffer_size = 0;
  s21_size_t length = 0;
  int token_buffer_index = 0;

  int string_width = 0;
  int count_limit = 0;

  int is_sign_needed = 0;

  value = s21_convert_integer_value(token, value);

  is_sign_needed = s21_is_sign_needed(token, value);

  s21_integer_to_string(buffer, value);

  buffer_size = s21_strlen(buffer);

  string_width =
      s21_get_integer_string_width(token, buffer_size, is_sign_needed);

  count_limit = s21_get_integer_count_limit(token, buffer_size, is_sign_needed);

  length = s21_get_current_integer_length(buffer_size, value,
                                          token->is_accuracy_zero);

  token_buffer_index =
      s21_format_integer_token_buffer(token, value, string_width, count_limit);

  token_buffer_index =
      s21_copy_value_in_token_buffer(token, buffer, token_buffer_index, length);

  if (s21_complete_token_buffer(token, token_buffer_index, count_limit))
    token_buffer_index += count_limit;

  token->token_buffer[token_buffer_index] = '\0';
}

void s21_handle_real(Token_t *token, s21_real_t real_value) {
  int sign = 0;

  if (real_value < 0) {
    sign++;
    real_value = -real_value;
  }

  s21_convert_real_to_string(token, real_value);

  s21_real_string_builder(token, sign);
}