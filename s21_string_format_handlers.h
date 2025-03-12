#include <math.h>
#include <stdarg.h>
#include <stdlib.h>
#include <wchar.h>

#include "s21_string.h"

#define BUFFER_SIZE 2048

typedef long int s21_integer_t;
typedef long double s21_real_t;
typedef char *s21_string_t;

typedef struct token {
  char token_buffer[BUFFER_SIZE];
  int minus;
  int plus;
  int space;
  int sharp;
  int zero;
  int width;
  int accuracy;
  int is_accuracy_zero;
  char length;
  char type;
} Token_t;

int s21_parse_format_flags(const s21_string_t format, Token_t *token,
                           int current_index);
int s21_check_format_to_point(int *current_index,
                              const unsigned char character);
int s21_check_accuracy_to_zero(int accuracy);
int s21_parse_format_width_and_accuracy(const s21_string_t format,
                                        int *token_value, va_list *argument,
                                        int current_index);
int s21_parse_format_length(const s21_string_t format,
                            s21_string_t token_length, int current_index);
int s21_parse_format_type(const s21_string_t format, Token_t *token,
                          va_list argument, int current_index);

void s21_get_wide_string(s21_string_t string, wchar_t *pointer_to_wide_string);
void s21_get_wide_character(wchar_t wide_character, int *character_pointer);

void s21_integer_to_string(s21_string_t string, s21_integer_t long_value);
void s21_reverse_string(s21_string_t string);
//
//
//
s21_integer_t s21_convert_integer_value(Token_t *token,
                                        s21_integer_t long_value);
int s21_is_sign_needed(Token_t *token, s21_integer_t long_value);
s21_size_t s21_get_current_integer_length(s21_size_t current_buffer_size,
                                          s21_integer_t long_value,
                                          int zero_accuracy_flag);
int s21_get_integer_string_width(Token_t *token, s21_size_t buffer_length,
                                 int is_sign_needed);
int s21_get_integer_count_limit(Token_t *token, s21_size_t buffer_length,
                                int is_sign_needed);

int s21_format_integer_token_buffer(Token_t *token, s21_integer_t long_value,
                                    int string_width, int buffer_count_limit);
int s21_copy_value_in_token_buffer(Token_t *current_token,
                                   const s21_string_t current_buffer,
                                   int current_token_buffer_index,
                                   s21_size_t current_buffer_length);
int s21_complete_token_buffer(Token_t *token, int current_token_buffer_index,
                              int current_buffer_count_limit);
//
//
//
//
void s21_handle_integer(Token_t *token, s21_integer_t value);
void s21_handle_string(Token_t *token, s21_string_t string);
void s21_handle_single_character(Token_t *token, int character);

//
int s21_get_current_token_accuracy(Token_t *token);
s21_integer_t s21_get_integer_part_of_real(s21_real_t real_value,
                                           int current_token_accuracy);
void s21_handle_real(Token_t *token, s21_real_t real_value);
int s21_set_integer_part_in_temporary_buffer(
    s21_string_t buffer, s21_integer_t positive_integer_value,
    int should_handle_first_digit);

void s21_convert_real_to_string(Token_t *token, s21_real_t adress);
void s21_real_string_builder(Token_t *token, int sign);