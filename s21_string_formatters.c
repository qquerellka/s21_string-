#include "s21_string_format_handlers.h"

int s21_format_integer_token_buffer(Token_t *token, s21_integer_t long_value,
                                    int buffer_string_width,
                                    int buffer_count_limit) {
  int result_token_buffer_index = 0;

  if (token->is_accuracy_zero == 1 && token->width > 0 && long_value == 0) {
    token->token_buffer[result_token_buffer_index] = ' ';
    result_token_buffer_index++;
  }

  if (token->width > 0 && token->minus == 0) {
    for (int i = 0; i < buffer_count_limit; result_token_buffer_index++, i++)
      token->token_buffer[result_token_buffer_index] = ' ';
  }

  if (long_value >= 0 && token->plus == 1 && token->type != 'u') {
    token->token_buffer[result_token_buffer_index] = '+';
    result_token_buffer_index++;
  } else if (long_value >= 0 && token->space == 1 && token->type != 'u') {
    token->token_buffer[result_token_buffer_index] = ' ';
    result_token_buffer_index++;
  }

  if (long_value < 0 && token->type != 'u') {
    token->token_buffer[result_token_buffer_index] = '-';
    result_token_buffer_index++;
  }

  if (buffer_string_width > 0) {
    for (int j = 0; j < buffer_string_width; j++) {
      token->token_buffer[result_token_buffer_index] = '0';
      result_token_buffer_index++;
    }
  }

  return result_token_buffer_index;
}

void s21_real_string_builder(Token_t *token, int sign) {
  char temporary_buffer[BUFFER_SIZE] = {'\0'};
  int token_buffer_size = 0;
  int end = 0;
  int index = 0;

  token_buffer_size = (int)s21_strlen(token->token_buffer);

  s21_strncpy(temporary_buffer, token->token_buffer, token_buffer_size);

  end = token_buffer_size;

  if (sign != 0 || token->plus == 1) end++;

  if (token->width > 0 && token->minus == 0 && token->zero == 0) {
    s21_memset(token->token_buffer + index, ' ', token->width - end);

    index += token->width - end;
  }

  if (token->plus == 1 && sign == 0) {
    token->token_buffer[index] = '+';
    index++;
  }

  if (sign != 0) {
    token->token_buffer[index] = '-';
    index++;
  }

  if (token->token_buffer[0] != ' ' && token->plus == 0 && sign == 0 &&
      token->space > 0) {
    token->token_buffer[index] = ' ';
    index++;
    end++;
  }

  if (token->zero == 1 && token->minus == 0) {
    s21_memset(token->token_buffer + index, '0', token->width - end);

    index += token->width - end;
  }

  token->token_buffer[index] = '\0';

  s21_strncat(token->token_buffer, temporary_buffer, token_buffer_size);

  index += token_buffer_size;

  if (s21_complete_token_buffer(token, index, token->width - end))
    index += token->width - end;

  token->token_buffer[index] = '\0';
}