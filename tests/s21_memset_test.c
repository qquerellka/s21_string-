#include "s21_check_string.h"

//  char str_s21[] = "Hello world!";
//  char str[] = "Hello world!";
//  int c = 'w';
//  size_t n = 10;
START_TEST(test_s21_memset_1) {
  char str_s21[] = "Hello world!";
  char str[] = "Hello world!";
  int c = 'w';
  size_t n = 10;
  char *s21_memset_result = NULL;
  char *memset_result = NULL;

  s21_memset_result = (char *)s21_memset(str_s21, c, n);
  memset_result = (char *)memset(str, c, n);

  ck_assert_str_eq(s21_memset_result, memset_result);
}
END_TEST

//  char str_s21[] = "there is no power as no knowledge";
//  char str[] = "there is no power as no knowledge";
//  int c = 'w';
//  size_t n = 10;
START_TEST(test_s21_memset_2) {
  char str_s21[] = "there is no power as no knowledge";
  char str[] = "there is no power as no knowledge";
  int c = 'w';
  size_t n = 10;
  char *s21_memset_result = NULL;
  char *memset_result = NULL;

  s21_memset_result = (char *)s21_memset(str_s21, c, n);
  memset_result = (char *)memset(str, c, n);

  ck_assert_str_eq(s21_memset_result, memset_result);
}
END_TEST

//  char str_s21[] = "Hello world!";
//  char str[] = "Hello world!";
//  int c = ']';
//  size_t n = 10;
START_TEST(test_s21_memset_3) {
  char str_s21[] = "Hello world!";
  char str[] = "Hello world!";
  int c = ']';
  size_t n = 10;
  char *s21_memset_result = NULL;
  char *memset_result = NULL;

  s21_memset_result = (char *)s21_memset(str_s21, c, n);
  memset_result = (char *)memset(str, c, n);

  ck_assert_str_eq(s21_memset_result, memset_result);
}
END_TEST

//  char str_s21[] = "there is no power as no knowledge";
//  char str[] = "there is no power as no knowledge";
//  int c = ']';
//  size_t n = 10;
START_TEST(test_s21_memset_4) {
  char str_s21[] = "there is no power as no knowledge";
  char str[] = "there is no power as no knowledge";
  int c = ']';
  size_t n = 10;
  char *s21_memset_result = NULL;
  char *memset_result = NULL;

  s21_memset_result = (char *)s21_memset(str_s21, c, n);
  memset_result = (char *)memset(str, c, n);

  ck_assert_str_eq(s21_memset_result, memset_result);
}
END_TEST

//  char str_s21[] = "Hello world!";
//  char str[] = "Hello world!";
//  int c = '\0';
//  size_t n = 10;
START_TEST(test_s21_memset_5) {
  char str_s21[] = "Hello world!";
  char str[] = "Hello world!";
  int c = '\0';
  size_t n = 10;
  char *s21_memset_result = NULL;
  char *memset_result = NULL;

  s21_memset_result = (char *)s21_memset(str_s21, c, n);
  memset_result = (char *)memset(str, c, n);

  ck_assert_str_eq(s21_memset_result, memset_result);
}
END_TEST

//  char str_s21[] = "there is no power as no knowledge";
//  char str[] = "there is no power as no knowledge";
//  int c = '\0';
//  size_t n = 10;
START_TEST(test_s21_memset_6) {
  char str_s21[] = "there is no power as no knowledge";
  char str[] = "there is no power as no knowledge";
  int c = '\0';
  size_t n = 10;
  char *s21_memset_result = NULL;
  char *memset_result = NULL;

  s21_memset_result = (char *)s21_memset(str_s21, c, n);
  memset_result = (char *)memset(str, c, n);

  ck_assert_str_eq(s21_memset_result, memset_result);
}
END_TEST

//  char str_s21[] = "Hello world!";
//  char str[] = "Hello world!";
//  int c = -7;
//  size_t n = 10;
START_TEST(test_s21_memset_7) {
  char str_s21[] = "Hello world!";
  char str[] = "Hello world!";
  int c = -7;
  size_t n = 10;
  char *s21_memset_result = NULL;
  char *memset_result = NULL;

  s21_memset_result = (char *)s21_memset(str_s21, c, n);
  memset_result = (char *)memset(str, c, n);

  ck_assert_str_eq(s21_memset_result, memset_result);
}
END_TEST

//  char str_s21[] = "there is no power as no knowledge";
//  char str[] = "there is no power as no knowledge";
//  int c = -7;
//  size_t n = 10;
START_TEST(test_s21_memset_8) {
  char str_s21[] = "there is no power as no knowledge";
  char str[] = "there is no power as no knowledge";
  int c = -7;
  size_t n = 10;
  char *s21_memset_result = NULL;
  char *memset_result = NULL;

  s21_memset_result = (char *)s21_memset(str_s21, c, n);
  memset_result = (char *)memset(str, c, n);

  ck_assert_str_eq(s21_memset_result, memset_result);
}
END_TEST

// Установка 0 байт (строка не должна измениться)
START_TEST(test_s21_memset_9) {
  char str_s21[] = "Test string!";
  char str[] = "Test string!";
  int c = 'x';
  size_t n = 0;

  char *s21_memset_result = (char *)s21_memset(str_s21, c, n);
  char *memset_result = (char *)memset(str, c, n);

  ck_assert_str_eq(s21_memset_result, memset_result);
}
END_TEST

// Установка всех байт в короткой строке
START_TEST(test_s21_memset_10) {
  char str_s21[] = "abc";
  char str[] = "abc";
  int c = '*';
  size_t n = 3;

  char *s21_memset_result = (char *)s21_memset(str_s21, c, n);
  char *memset_result = (char *)memset(str, c, n);

  ck_assert_str_eq(s21_memset_result, memset_result);
}
END_TEST

// Очень большой размер (проверка на переполнение буфера)
START_TEST(test_s21_memset_13) {
  char str_s21[128] = "Large size test!";
  char str[128] = "Large size test!";
  int c = '#';
  size_t n = 128;

  char *s21_memset_result = (char *)s21_memset(str_s21, c, n);
  char *memset_result = (char *)memset(str, c, n);

  ck_assert_mem_eq(s21_memset_result, memset_result, n);
}
END_TEST

// Частичное заполнение буфера (n меньше длины строки)
START_TEST(test_s21_memset_14) {
  char str_s21[] = "Partial test";
  char str[] = "Partial test";
  int c = '@';
  size_t n = 7;

  char *s21_memset_result = (char *)s21_memset(str_s21, c, n);
  char *memset_result = (char *)memset(str, c, n);

  ck_assert_str_eq(s21_memset_result, memset_result);
}
END_TEST

Suite *s21_memset_suite(void) {
  Suite *suite;
  TCase *tc_s21_memset;

  suite = suite_create("s21_memset");

  tc_s21_memset = tcase_create("Memset");

  tcase_add_test(tc_s21_memset, test_s21_memset_1);
  suite_add_tcase(suite, tc_s21_memset);

  tcase_add_test(tc_s21_memset, test_s21_memset_2);
  suite_add_tcase(suite, tc_s21_memset);

  tcase_add_test(tc_s21_memset, test_s21_memset_3);
  suite_add_tcase(suite, tc_s21_memset);

  tcase_add_test(tc_s21_memset, test_s21_memset_4);
  suite_add_tcase(suite, tc_s21_memset);

  tcase_add_test(tc_s21_memset, test_s21_memset_5);
  suite_add_tcase(suite, tc_s21_memset);

  tcase_add_test(tc_s21_memset, test_s21_memset_6);
  suite_add_tcase(suite, tc_s21_memset);

  tcase_add_test(tc_s21_memset, test_s21_memset_7);
  suite_add_tcase(suite, tc_s21_memset);

  tcase_add_test(tc_s21_memset, test_s21_memset_8);
  suite_add_tcase(suite, tc_s21_memset);

  tcase_add_test(tc_s21_memset, test_s21_memset_9);
  suite_add_tcase(suite, tc_s21_memset);

  tcase_add_test(tc_s21_memset, test_s21_memset_10);
  suite_add_tcase(suite, tc_s21_memset);

  tcase_add_test(tc_s21_memset, test_s21_memset_13);
  suite_add_tcase(suite, tc_s21_memset);

  tcase_add_test(tc_s21_memset, test_s21_memset_14);
  suite_add_tcase(suite, tc_s21_memset);

  return suite;
}