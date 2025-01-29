#include "s21_string_format_handlers.h"

void s21_integer_to_string(char *string, s21_integer_t long_value) {
  int index = 0;
  s21_integer_t buffer_value = 0;

  buffer_value = long_value;

  if (long_value < 0) buffer_value = -buffer_value;

  string[index] = buffer_value % 10 + '0';

  index++;

  for (; (buffer_value = buffer_value / 10) > 0; index++)
    string[index] = buffer_value % 10 + '0';

  string[index] = '\0';

  s21_reverse_string(string);
}

void s21_reverse_string(s21_string_t string) {
  int i, j;
  char tmp_character;

  for (i = 0, j = s21_strlen(string) - 1; i < j; i++, j--) {
    tmp_character = string[i];

    string[i] = string[j];

    string[j] = tmp_character;
  }
}

s21_integer_t s21_convert_integer_value(Token_t *token,
                                        s21_integer_t long_value) {
  s21_integer_t result_value = 0;

  if (token->type != 'u') switch (token->length) {
      case 'l':
        result_value = (s21_integer_t)(long int)long_value;
        break;
      case 'h':
        result_value = (s21_integer_t)(short int)long_value;
        break;
      default:
        result_value = (s21_integer_t)(int)long_value;
        break;
    }
  else
    switch (token->length) {
      case 'l':
        result_value = (s21_integer_t)(unsigned long int)long_value;
        break;
      case 'h':
        result_value = (s21_integer_t)(unsigned short int)long_value;
        break;
      default:
        result_value = (s21_integer_t)(unsigned int)long_value;
        break;
    }

  return result_value;
}

s21_size_t s21_get_current_integer_length(s21_size_t current_buffer_size,
                                          s21_integer_t long_value,
                                          int zero_accuracy_flag) {
  s21_size_t result_length = 0;

  if (zero_accuracy_flag == 1 && long_value == 0)
    result_length = 0;
  else
    result_length = current_buffer_size;

  return result_length;
}

int s21_is_sign_needed(Token_t *token, s21_integer_t long_value) {
  int result_sign = 0;

  if (token->type != 'u') {
    if ((long_value > 0 && token->plus == 1) || long_value < 0 ||
        (long_value > 0 && token->space == 1))
      result_sign = 1;
  }

  return result_sign;
}

int s21_get_integer_string_width(Token_t *token, s21_size_t buffer_length,
                                 int is_sign_needed) {
  int result_string_width = 0;

  if (token->accuracy > 0 || token->is_accuracy_zero == 1) {
    if (token->accuracy > (int)buffer_length && token->accuracy > 0) {
      result_string_width = token->accuracy - buffer_length;
    } else if (token->accuracy == 0 && token->zero == 1 && token->minus == 0 &&
               token->width > 0 && token->is_accuracy_zero != 1) {
      result_string_width = token->width - buffer_length;
    }
  } else {
    if (token->zero == 1 && token->minus == 0) {
      result_string_width = token->width - buffer_length - is_sign_needed;
    }
  }

  return result_string_width;
}

int s21_get_integer_count_limit(Token_t *token, s21_size_t buffer_length,
                                int is_sign_needed) {
  int result_count_limit = 0;

  // if (token->accuracy > 0 || token->is_accuracy_zero == 1) {

  //     if (token->width > 0 && token->accuracy < (int)buffer_length) {  //
  //     кол-во пробелов
  //       result_count_limit =  token->width - buffer_length - is_sign_needed;
  //     } else if (token->accuracy > 0 && token->accuracy > (int)buffer_length)
  //     {
  //       result_count_limit = parser->minNum - parser->fractionalMinNum -
  //       znak;
  //     }

  //   } else {
  //     if ((parser->minNum > 0 && parser->zero == 0) ||
  //         (parser->minus == 1 && parser->minNum > 0)) {
  //       result_count_limit = parser->minNum - s21_strlen(buff) - znak;
  //     }
  //   }

  // ////
  if (token->accuracy > 0 || token->is_accuracy_zero == 1) {
    if (token->width > 0 && token->accuracy < (int)buffer_length)
      result_count_limit = token->width - buffer_length - is_sign_needed;
    else if (token->accuracy > 0 && token->accuracy > (int)buffer_length)
      result_count_limit = token->width - token->accuracy - is_sign_needed;

  } else if ((token->width > 0 && token->zero == 0) ||
             (token->minus == 1 && token->width > 0))
    result_count_limit = token->width - buffer_length - is_sign_needed;

  return result_count_limit;
}

int s21_copy_value_in_token_buffer(Token_t *current_token,
                                   const s21_string_t current_buffer,
                                   int current_token_buffer_index,
                                   s21_size_t current_buffer_length) {
  s21_string_t token_buffer = S21_NULL;
  int result_token_buffer_index = 0;
  int length = 0;

  length = (int)current_buffer_length;

  token_buffer = current_token->token_buffer;

  for (int i = 0; i < length; i++) {
    token_buffer[current_token_buffer_index] = current_buffer[i];
    current_token_buffer_index++;
  }

  result_token_buffer_index = current_token_buffer_index;

  return result_token_buffer_index;
}

int s21_complete_token_buffer(Token_t *token, int current_token_buffer_index,
                              int current_buffer_count_limit) {
  int result = 0;

  if (token->width > 0 && token->minus == 1) {
    s21_memset(token->token_buffer + current_token_buffer_index, ' ',
               current_buffer_count_limit);
    result = 1;
  }

  return result;
}

void s21_convert_real_to_string(Token_t *token, s21_real_t real_value) {
  char converted_value_buffer[BUFFER_SIZE] = {'\0'};
  char current_converted_buffer[BUFFER_SIZE] = {'\0'};
  s21_integer_t integer_part_of_real = 0;
  s21_real_t fractional_part_of_real = 0;
  int round_flag = 0;
  int frac_elements_count = 0;
  int current_token_accuracy = 0;
  int temporary_buffer_elements_count = 0;

  current_token_accuracy = s21_get_current_token_accuracy(token);

  integer_part_of_real =
      s21_get_integer_part_of_real(real_value, current_token_accuracy);

  fractional_part_of_real = real_value - integer_part_of_real;

  if (fractional_part_of_real < 0)
    fractional_part_of_real = -fractional_part_of_real;

  round_flag = roundl(fractional_part_of_real * 10) == 10;

  if (round_flag) integer_part_of_real += 1;

  temporary_buffer_elements_count = s21_set_integer_part_in_temporary_buffer(
      converted_value_buffer, integer_part_of_real, 0);

  s21_reverse_string(converted_value_buffer);

  if (current_token_accuracy == 0) {
    if (token->sharp)
      converted_value_buffer[temporary_buffer_elements_count++] = '.';
  } else {
    fractional_part_of_real *= pow(10, current_token_accuracy);

    integer_part_of_real =
        s21_get_integer_part_of_real(fractional_part_of_real, 0);

    converted_value_buffer[temporary_buffer_elements_count++] = '.';

    frac_elements_count = s21_set_integer_part_in_temporary_buffer(
        current_converted_buffer, integer_part_of_real, round_flag);

    s21_reverse_string(current_converted_buffer);

    s21_strncat(converted_value_buffer, current_converted_buffer,
                frac_elements_count);

    temporary_buffer_elements_count += frac_elements_count;
  }

  s21_strncpy(token->token_buffer, converted_value_buffer,
              temporary_buffer_elements_count);
}

int s21_get_current_token_accuracy(Token_t *token) {
  int result_accuracy = 0;

  if (!token->accuracy && !token->is_accuracy_zero)
    result_accuracy = 6;
  else
    result_accuracy = token->accuracy;

  return result_accuracy;
}

s21_integer_t s21_get_integer_part_of_real(s21_real_t real_value,
                                           int current_token_accuracy) {
  s21_integer_t result_value = 0;

  if (current_token_accuracy)
    result_value = (s21_integer_t)real_value;
  else
    result_value = roundl(real_value);

  return result_value;
}

int s21_set_integer_part_in_temporary_buffer(
    s21_string_t buffer, s21_integer_t positive_integer_value,
    int should_handle_first_digit) {
  int result_index = 0;
  int should_continue_key = 1;

  while (should_continue_key) {
    buffer[result_index] = positive_integer_value % 10 + '0';

    positive_integer_value /= 10;

    result_index++;

    if (should_handle_first_digit)
      should_continue_key = (positive_integer_value > 9) ? 1 : 0;
    else
      should_continue_key = (positive_integer_value) ? 1 : 0;
  }

  return result_index;
}

void s21_get_wide_string(s21_string_t string, wchar_t *pointer_to_wide_string) {
  wcstombs(string, pointer_to_wide_string, BUFFER_SIZE);
}

void s21_get_wide_character(wchar_t wide_character, int *character_pointer) {
  char string[BUFFER_SIZE] = {'\0'};
  wctomb(string, wide_character);
  *character_pointer = string[0];
}