#include <stdlib.h>

#include "s21_check_string.h"

// Проверка вставки строки в начало
START_TEST(test_s21_insert_at_start) {
  const char *src = "World!";
  const char *str = "Hello ";
  size_t start_index = 0;

  char *result = (char *)s21_insert(src, str, start_index);
  ck_assert_str_eq(result, "Hello World!");
  free(result);
}
END_TEST

// Проверка вставки строки в конец
START_TEST(test_s21_insert_at_end) {
  const char *src = "Hello";
  const char *str = " World!";
  size_t start_index = 5;

  char *result = (char *)s21_insert(src, str, start_index);
  ck_assert_str_eq(result, "Hello World!");
  free(result);
}
END_TEST

// Проверка вставки пустой строки
START_TEST(test_s21_insert_empty_str) {
  const char *src = "Hello";
  const char *str = "";
  size_t start_index = 3;

  char *result = (char *)s21_insert(src, str, start_index);
  ck_assert_str_eq(result, "Hello");
  free(result);
}
END_TEST

// Проверка вставки в пустую строку
START_TEST(test_s21_insert_into_empty_src) {
  const char *src = "";
  const char *str = "Hello";
  size_t start_index = 0;

  char *result = (char *)s21_insert(src, str, start_index);
  ck_assert_str_eq(result, "Hello");
  free(result);
}
END_TEST

// Проверка вставки с индексом вне допустимого диапазона
START_TEST(test_s21_insert_invalid_index) {
  const char *src = "Hello";
  const char *str = " World";
  size_t start_index = 10;  // Неверный индекс

  char *result = (char *)s21_insert(src, str, start_index);
  ck_assert_ptr_eq(result, NULL);
}
END_TEST

// Проверка вставки NULL строки
START_TEST(test_s21_insert_null_str) {
  const char *src = "Hello";
  const char *str = NULL;
  size_t start_index = 3;

  char *result = (char *)s21_insert(src, str, start_index);
  ck_assert_ptr_eq(result, NULL);
}
END_TEST

// Проверка вставки в NULL источник
START_TEST(test_s21_insert_null_src) {
  const char *src = NULL;
  const char *str = "Hello";
  size_t start_index = 0;

  char *result = (char *)s21_insert(src, str, start_index);
  ck_assert_ptr_eq(result, NULL);
}
END_TEST

// Проверка вставки NULL строки в NULL источник
START_TEST(test_s21_insert_null_src_and_str) {
  const char *src = NULL;
  const char *str = NULL;
  size_t start_index = 0;

  char *result = (char *)s21_insert(src, str, start_index);
  ck_assert_ptr_eq(result, NULL);
}
END_TEST

Suite *s21_insert_suite(void) {
  Suite *suite;
  TCase *tc_s21_insert;

  suite = suite_create("s21_insert");
  tc_s21_insert = tcase_create("S21_insert");

  tcase_add_test(tc_s21_insert, test_s21_insert_at_start);
  tcase_add_test(tc_s21_insert, test_s21_insert_at_end);
  tcase_add_test(tc_s21_insert, test_s21_insert_empty_str);
  tcase_add_test(tc_s21_insert, test_s21_insert_into_empty_src);
  tcase_add_test(tc_s21_insert, test_s21_insert_invalid_index);
  tcase_add_test(tc_s21_insert, test_s21_insert_null_str);
  tcase_add_test(tc_s21_insert, test_s21_insert_null_src);
  tcase_add_test(tc_s21_insert, test_s21_insert_null_src_and_str);

  suite_add_tcase(suite, tc_s21_insert);
  return suite;
}
