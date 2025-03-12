#include "s21_check_string.h"

//  char dest_s21[] = "Hello world!";
//  char dest[] = "Hello world!";
//  char* src = "KHA..An!!11";
//  size_t n = 12;
START_TEST(test_s21_strncpy_1) {
  char dest_s21[] = "Hello world!";
  char dest[] = "Hello world!";
  char *src = "KHA..An!!11";
  size_t n = 12;
  char *s21_strncpy_result = NULL;
  char *strncpy_result = NULL;
  s21_strncpy_result = s21_strncpy(dest_s21, src, n);
  strncpy_result = strncpy(dest, src, n);
  ck_assert_str_eq(s21_strncpy_result, strncpy_result);
}
END_TEST

//  char dest_s21[] = "there is no power as no knowledge";
//  char dest[] = "there is no power as no knowledge";
//  char* src = "Hello";
//  size_t n = 10;
START_TEST(test_s21_strncpy_2) {
  char dest_s21[] = "there is no power as no knowledge";
  char dest[] = "there is no power as no knowledge";
  char *src = "Hello";
  size_t n = 10;
  char *s21_strncpy_result = NULL;
  char *strncpy_result = NULL;
  s21_strncpy_result = s21_strncpy(dest_s21, src, n);
  strncpy_result = strncpy(dest, src, n);
  ck_assert_str_eq(s21_strncpy_result, strncpy_result);
}
END_TEST

//  char dest_s21[] = "there is no power as no knowledge";
//  char dest[] = "there is no power as no knowledge";
//  char* src = "Hello";
//  size_t n = 0;
START_TEST(test_s21_strncpy_3) {
  char dest_s21[] = "there is no power as no knowledge";
  char dest[] = "there is no power as no knowledge";
  char *src = "Hello";
  size_t n = 0;
  char *s21_strncpy_result = NULL;
  char *strncpy_result = NULL;
  s21_strncpy_result = s21_strncpy(dest_s21, src, n);
  strncpy_result = strncpy(dest, src, n);
  ck_assert_str_eq(s21_strncpy_result, strncpy_result);
}
END_TEST

//  char dest_s21[] = "there is no power as no knowledge";
//  char dest[] = "there is no power as no knowledge";
//  char* src = "";
//  size_t n = 10;
START_TEST(test_s21_strncpy_4) {
  char dest_s21[] = "there is no power as no knowledge";
  char dest[] = "there is no power as no knowledge";
  char *src = "";
  size_t n = 10;
  char *s21_strncpy_result = NULL;
  char *strncpy_result = NULL;
  s21_strncpy_result = s21_strncpy(dest_s21, src, n);
  strncpy_result = strncpy(dest, src, n);
  ck_assert_str_eq(s21_strncpy_result, strncpy_result);
}
END_TEST

// n = длина исходной строки
START_TEST(test_s21_strncpy_5) {
  char dest_s21[20] = {0};
  char dest[20] = {0};
  char *src = "ExactLength";
  size_t n = strlen(src);
  char *s21_strncpy_result = s21_strncpy(dest_s21, src, n);
  char *strncpy_result = strncpy(dest, src, n);
  ck_assert_str_eq(s21_strncpy_result, strncpy_result);
  ck_assert_str_eq(dest_s21, dest);
}
END_TEST

// n превышает длину строки
START_TEST(test_s21_strncpy_6) {
  char dest_s21[30] = {0};
  char dest[30] = {0};
  char *src = "Short";
  size_t n = 20;
  char *s21_strncpy_result = s21_strncpy(dest_s21, src, n);
  char *strncpy_result = strncpy(dest, src, n);
  ck_assert_str_eq(s21_strncpy_result, strncpy_result);
  ck_assert_str_eq(dest_s21, dest);
}
END_TEST

// n = 0
START_TEST(test_s21_strncpy_7) {
  char dest_s21[] = "InitialString";
  char dest[] = "InitialString";
  char *src = "NewString";
  size_t n = 0;
  char *s21_strncpy_result = s21_strncpy(dest_s21, src, n);
  char *strncpy_result = strncpy(dest, src, n);
  ck_assert_str_eq(s21_strncpy_result, strncpy_result);
  ck_assert_str_eq(dest_s21, dest);
}
END_TEST

// src пустая строка
START_TEST(test_s21_strncpy_8) {
  char dest_s21[30] = {0};
  char dest[30] = {0};
  char *src = "";
  size_t n = 10;
  char *s21_strncpy_result = s21_strncpy(dest_s21, src, n);
  char *strncpy_result = strncpy(dest, src, n);
  ck_assert_str_eq(s21_strncpy_result, strncpy_result);
  ck_assert_str_eq(dest_s21, dest);
}
END_TEST

// n меньше длины строки
START_TEST(test_s21_strncpy_9) {
  char dest_s21[30] = "OldContent";
  char dest[30] = "OldContent";
  char *src = "NewString";
  size_t n = 3;
  char *s21_strncpy_result = s21_strncpy(dest_s21, src, n);
  char *strncpy_result = strncpy(dest, src, n);
  ck_assert_str_eq(s21_strncpy_result, strncpy_result);
  ck_assert_str_eq(dest_s21, dest);
}
END_TEST

Suite *s21_strncpy_suite(void) {
  Suite *suite;
  TCase *tc_s21_strncpy;

  suite = suite_create("s21_strncpy");

  tc_s21_strncpy = tcase_create("S21_strncpy");

  tcase_add_test(tc_s21_strncpy, test_s21_strncpy_1);
  suite_add_tcase(suite, tc_s21_strncpy);

  tcase_add_test(tc_s21_strncpy, test_s21_strncpy_2);
  suite_add_tcase(suite, tc_s21_strncpy);

  tcase_add_test(tc_s21_strncpy, test_s21_strncpy_3);
  suite_add_tcase(suite, tc_s21_strncpy);

  tcase_add_test(tc_s21_strncpy, test_s21_strncpy_4);
  suite_add_tcase(suite, tc_s21_strncpy);

  tcase_add_test(tc_s21_strncpy, test_s21_strncpy_6);
  suite_add_tcase(suite, tc_s21_strncpy);

  tcase_add_test(tc_s21_strncpy, test_s21_strncpy_5);
  suite_add_tcase(suite, tc_s21_strncpy);

  tcase_add_test(tc_s21_strncpy, test_s21_strncpy_7);
  suite_add_tcase(suite, tc_s21_strncpy);

  tcase_add_test(tc_s21_strncpy, test_s21_strncpy_8);
  suite_add_tcase(suite, tc_s21_strncpy);

  tcase_add_test(tc_s21_strncpy, test_s21_strncpy_9);
  suite_add_tcase(suite, tc_s21_strncpy);

  return suite;
}