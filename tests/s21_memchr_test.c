#include "s21_check_string.h"
//  char* str = "Hello world!";
//  char c = 'w';
//  size_t n = 10;
START_TEST(test_s21_memchr_1) {
  char *str = "Hello world!";
  char c = 'w';
  size_t n = 10;
  char *str_ptr = NULL;
  char *s21_str_ptr = NULL;
  str_ptr = memchr(str, c, n);
  s21_str_ptr = s21_memchr(str, c, n);
  ck_assert_ptr_eq(str_ptr, s21_str_ptr);
}
END_TEST

//  char* str = "Hello world!";
//  char c = ']';
//  size_t n = 10;
START_TEST(test_s21_memchr_2) {
  char *str = "Hello world!";
  char c = ']';
  size_t n = 10;
  char *str_ptr = NULL;
  char *s21_str_ptr = NULL;
  str_ptr = memchr(str, c, n);
  s21_str_ptr = s21_memchr(str, c, n);
  ck_assert_ptr_eq(str_ptr, s21_str_ptr);
}
END_TEST

//  char* str = "Hello world!";
//  char c = '\0';
//  size_t n = 10;
START_TEST(test_s21_memchr_3) {
  char *str = "Hello world!";
  char c = '\0';
  size_t n = 10;
  char *str_ptr = NULL;
  char *s21_str_ptr = NULL;
  str_ptr = memchr(str, c, n);
  s21_str_ptr = s21_memchr(str, c, n);
  ck_assert_ptr_eq(str_ptr, s21_str_ptr);
}
END_TEST

//  char* str = "Hello world!";
//  char c = 'w';
//  size_t n = 50;
START_TEST(test_s21_memchr_4) {
  char *str = "Hello world!";
  char c = 'w';
  size_t n = 13;
  char *str_ptr = NULL;
  char *s21_str_ptr = NULL;
  str_ptr = memchr(str, c, n);
  s21_str_ptr = s21_memchr(str, c, n);
  ck_assert_ptr_eq(str_ptr, s21_str_ptr);
}
END_TEST

//  char* str = "Hello world!";
//  char c = ']';
//  size_t n = 50;
START_TEST(test_s21_memchr_5) {
  char *str = "Hello world!";
  char c = ']';
  size_t n = 13;
  char *str_ptr = NULL;
  char *s21_str_ptr = NULL;
  str_ptr = memchr(str, c, n);
  s21_str_ptr = s21_memchr(str, c, n);
  ck_assert_ptr_eq(str_ptr, s21_str_ptr);
}
END_TEST

//  char* str = "Hello world!";
//  char c = '\0';
//  size_t n = 50;
START_TEST(test_s21_memchr_6) {
  char *str = "Hello world!";
  char c = '\0';
  size_t n = 13;
  char *str_ptr = NULL;
  char *s21_str_ptr = NULL;
  str_ptr = memchr(str, c, n);
  s21_str_ptr = s21_memchr(str, c, n);
  ck_assert_ptr_eq(str_ptr, s21_str_ptr);
}
END_TEST

//  char* str = "Hello world!";
//  char c = 'w';
//  size_t n = -5;
START_TEST(test_s21_memchr_7) {
  char *str = "Hello world!";
  char c = 'w';
  size_t n = 13;
  char *str_ptr = NULL;
  char *s21_str_ptr = NULL;
  str_ptr = memchr(str, c, n);
  s21_str_ptr = s21_memchr(str, c, n);
  ck_assert_ptr_eq(str_ptr, s21_str_ptr);
}
END_TEST

//  char* str = "Hello world!";
//  char c = ']';
//  size_t n = -5;
START_TEST(test_s21_memchr_8) {
  char *str = "Hello world!";
  char c = ']';
  size_t n = 13;
  char *str_ptr = NULL;
  char *s21_str_ptr = NULL;
  str_ptr = memchr(str, c, n);
  s21_str_ptr = s21_memchr(str, c, n);
  ck_assert_ptr_eq(str_ptr, s21_str_ptr);
}
END_TEST

//  char* str = "Hello world!";
//  char c = '\0';
//  size_t n = -5;
START_TEST(test_s21_memchr_9) {
  char *str = "Hello world!";
  char c = '\0';
  size_t n = 13;
  char *str_ptr = NULL;
  char *s21_str_ptr = NULL;
  str_ptr = memchr(str, c, n);
  s21_str_ptr = s21_memchr(str, c, n);
  ck_assert_ptr_eq(str_ptr, s21_str_ptr);
}
END_TEST

//  char* str = "Hello world!";
//  char c = 'w';
//  size_t n = 0;
START_TEST(test_s21_memchr_10) {
  char *str = "Hello world!";
  char c = 'w';
  size_t n = 0;
  char *str_ptr = NULL;
  char *s21_str_ptr = NULL;
  str_ptr = memchr(str, c, n);
  s21_str_ptr = s21_memchr(str, c, n);
  ck_assert_ptr_eq(str_ptr, s21_str_ptr);
}
END_TEST


// символ в конце строки
START_TEST(test_s21_memchr_11) {
  char *str = "abcdef";
  char c = 'f';
  size_t n = 6;
  char *str_ptr = NULL;
  char *s21_str_ptr = NULL;
  str_ptr = memchr(str, c, n);
  s21_str_ptr = s21_memchr(str, c, n);
  ck_assert_ptr_eq(str_ptr, s21_str_ptr);
}
END_TEST

// символ в начале строки
START_TEST(test_s21_memchr_12) {
  char *str = "abcdef";
  char c = 'a';
  size_t n = 6;
  char *str_ptr = NULL;
  char *s21_str_ptr = NULL;
  str_ptr = memchr(str, c, n);
  s21_str_ptr = s21_memchr(str, c, n);
  ck_assert_ptr_eq(str_ptr, s21_str_ptr);
}
END_TEST

// строка с только \0
START_TEST(test_s21_memchr_13) {
  char str[] = {'\0', '\0', '\0'};
  char c = '\0';
  size_t n = 3;
  char *str_ptr = NULL;
  char *s21_str_ptr = NULL;
  str_ptr = memchr(str, c, n);
  s21_str_ptr = s21_memchr(str, c, n);
  ck_assert_ptr_eq(str_ptr, s21_str_ptr);
}
END_TEST

// символ отсутствует в строке
START_TEST(test_s21_memchr_14) {
  char *str = "abcdef";
  char c = 'z';
  size_t n = 6;
  char *str_ptr = NULL;
  char *s21_str_ptr = NULL;
  str_ptr = memchr(str, c, n);
  s21_str_ptr = s21_memchr(str, c, n);
  ck_assert_ptr_eq(str_ptr, s21_str_ptr);
}
END_TEST

// Test cases
START_TEST(test_s21_memchr_15) {
  char buffer[] = "abcdefgh";
  int c = 'd';
  size_t n = s21_strlen(buffer);
  void *result = s21_memchr(buffer, c, n);
  void *expected = memchr(buffer, c, n);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_memchr_16) {
  char buffer[] = "search";
  int c = 's';
  size_t n = s21_strlen(buffer);
  void *result = s21_memchr(buffer, c, n);
  void *expected = memchr(buffer, c, n);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_memchr_17) {
  char buffer[] = "last";
  int c = 't';
  size_t n = s21_strlen(buffer);
  void *result = s21_memchr(buffer, c, n);
  void *expected = memchr(buffer, c, n);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

START_TEST(test_s21_memchr_18) {
  char buffer[] = "abc\0def";
  int c = '\0';
  size_t n = 7;
  void *result = s21_memchr(buffer, c, n);
  void *expected = memchr(buffer, c, n);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

// Поиск ASCII-кода 97 ('a') в первых 3 символах
START_TEST(test_s21_memchr_19) {
  char test1[] = "abcde123";
  void *result = s21_memchr(test1, 97, 3);
  void *expected = memchr(test1, 97, 3);
  ck_assert_ptr_eq(result, expected);
}
END_TEST

Suite *s21_memchr_suite(void) {
  Suite *suite = suite_create("s21_memchr");
  TCase *tc_s21_memchr = tcase_create("S21_memchr");
  tcase_add_test(tc_s21_memchr, test_s21_memchr_1);
  suite_add_tcase(suite, tc_s21_memchr);
  tcase_add_test(tc_s21_memchr, test_s21_memchr_2);
  suite_add_tcase(suite, tc_s21_memchr);
  tcase_add_test(tc_s21_memchr, test_s21_memchr_3);
  suite_add_tcase(suite, tc_s21_memchr);
  tcase_add_test(tc_s21_memchr, test_s21_memchr_4);
  suite_add_tcase(suite, tc_s21_memchr);
  tcase_add_test(tc_s21_memchr, test_s21_memchr_5);
  suite_add_tcase(suite, tc_s21_memchr);
  tcase_add_test(tc_s21_memchr, test_s21_memchr_6);
  suite_add_tcase(suite, tc_s21_memchr);
  tcase_add_test(tc_s21_memchr, test_s21_memchr_7);
  suite_add_tcase(suite, tc_s21_memchr);
  tcase_add_test(tc_s21_memchr, test_s21_memchr_8);
  suite_add_tcase(suite, tc_s21_memchr);
  tcase_add_test(tc_s21_memchr, test_s21_memchr_9);
  suite_add_tcase(suite, tc_s21_memchr);
  tcase_add_test(tc_s21_memchr, test_s21_memchr_10);
  suite_add_tcase(suite, tc_s21_memchr);
  tcase_add_test(tc_s21_memchr, test_s21_memchr_11);
  suite_add_tcase(suite, tc_s21_memchr);
  tcase_add_test(tc_s21_memchr, test_s21_memchr_12);
  suite_add_tcase(suite, tc_s21_memchr);
  tcase_add_test(tc_s21_memchr, test_s21_memchr_13);
  suite_add_tcase(suite, tc_s21_memchr);
  tcase_add_test(tc_s21_memchr, test_s21_memchr_14);
  suite_add_tcase(suite, tc_s21_memchr);
  tcase_add_test(tc_s21_memchr, test_s21_memchr_15);
  suite_add_tcase(suite, tc_s21_memchr);
  tcase_add_test(tc_s21_memchr, test_s21_memchr_16);
  suite_add_tcase(suite, tc_s21_memchr);
  tcase_add_test(tc_s21_memchr, test_s21_memchr_16);
  suite_add_tcase(suite, tc_s21_memchr);
  tcase_add_test(tc_s21_memchr, test_s21_memchr_17);
  suite_add_tcase(suite, tc_s21_memchr);
  tcase_add_test(tc_s21_memchr, test_s21_memchr_18);
  suite_add_tcase(suite, tc_s21_memchr);
  tcase_add_test(tc_s21_memchr, test_s21_memchr_19);
  suite_add_tcase(suite, tc_s21_memchr);
  return suite;
}