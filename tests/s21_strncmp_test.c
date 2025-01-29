#include "s21_check_string.h"

//  char* str1 = "Hello world!";
//  char* str2 = "Hello";
//  s21_size_t n = 10;
START_TEST(test_s21_strncmp_1) {
  char *str1 = "Hello world!";
  char *str2 = "Hello";
  s21_size_t n = 10;
  int s21_strncmp_result = 0;
  int strncmp_result = 0;

  s21_strncmp_result = s21_strncmp(str1, str2, n);
  strncmp_result = strncmp(str1, str2, n);

  ck_assert_int_eq(s21_strncmp_result, strncmp_result);
}
END_TEST

//  char* str1 = "Hello";
//  char* str2 = "Hello world!";
//  s21_size_t n = 10;
START_TEST(test_s21_strncmp_2) {
  char *str1 = "Hello";
  char *str2 = "Hello world!";
  s21_size_t n = 10;
  int s21_strncmp_result = 0;
  int strncmp_result = 0;

  s21_strncmp_result = s21_strncmp(str1, str2, n);
  strncmp_result = strncmp(str1, str2, n);

  ck_assert_int_eq(s21_strncmp_result, strncmp_result);
}
END_TEST

//  char* str1 = "Hello world!";
//  char* str2 = "Hello world!";
//  s21_size_t n = 10;
START_TEST(test_s21_strncmp_3) {
  char *str1 = "Hello world!";
  char *str2 = "Hello world!";
  s21_size_t n = 10;
  int s21_strncmp_result = 0;
  int strncmp_result = 0;

  s21_strncmp_result = s21_strncmp(str1, str2, n);
  strncmp_result = strncmp(str1, str2, n);

  ck_assert_int_eq(s21_strncmp_result, strncmp_result);
}
END_TEST

//  char* str1 = "Hello world!";
//  char* str2 = "KHA..An!!11";
//  s21_size_t n = 10;
START_TEST(test_s21_strncmp_4) {
  char *str1 = "Hello world!";
  char *str2 = "KHA..An!!11";
  s21_size_t n = 10;
  int s21_strncmp_result = 0;
  int strncmp_result = 0;

  s21_strncmp_result = s21_strncmp(str1, str2, n);
  strncmp_result = strncmp(str1, str2, n);

  ck_assert_int_eq(s21_strncmp_result, strncmp_result);
}
END_TEST

//  char* str1 = "Hello world!";
//  char* str2 = "Hello world!";
//  s21_size_t n = 50;
START_TEST(test_s21_strncmp_5) {
  char *str1 = "Hello world!";
  char *str2 = "Hello world!";
  s21_size_t n = 50;
  int s21_strncmp_result = 0;
  int strncmp_result = 0;

  s21_strncmp_result = s21_strncmp(str1, str2, n);
  strncmp_result = strncmp(str1, str2, n);

  ck_assert_int_eq(s21_strncmp_result, strncmp_result);
}
END_TEST

//  char* str1 = "Hello world!";
//  char* str2 = "Hello world!";
//  s21_size_t n = 0;
START_TEST(test_s21_strncmp_6) {
  char *str1 = "Hello world!";
  char *str2 = "Hello world!";
  s21_size_t n = 0;
  int s21_strncmp_result = 0;
  int strncmp_result = 0;

  s21_strncmp_result = s21_strncmp(str1, str2, n);
  strncmp_result = strncmp(str1, str2, n);

  ck_assert_int_eq(s21_strncmp_result, strncmp_result);
}
END_TEST

//  char* str1 = "Hello world!";
//  char* str2 = "KHA..An!!11";
//  s21_size_t n = 50;
START_TEST(test_s21_strncmp_7) {
  char *str1 = "Hello world!";
  char *str2 = "KHA..An!!11";
  s21_size_t n = 50;
  int s21_strncmp_result = 0;
  int strncmp_result = 0;

  s21_strncmp_result = s21_strncmp(str1, str2, n);
  strncmp_result = strncmp(str1, str2, n);

  ck_assert_int_eq(s21_strncmp_result, strncmp_result);
}
END_TEST

//  char* str1 = "";
//  char* str2 = "";
//  s21_size_t n = 10;
START_TEST(test_s21_strncmp_8) {
  char *str1 = "";
  char *str2 = "";
  s21_size_t n = 10;
  int s21_strncmp_result = 0;
  int strncmp_result = 0;

  s21_strncmp_result = s21_strncmp(str1, str2, n);
  strncmp_result = strncmp(str1, str2, n);

  ck_assert_int_eq(s21_strncmp_result, strncmp_result);
}
END_TEST

//  char* str1 = "Hello";
//  char* str2 = "";
//  s21_size_t n = 10;
START_TEST(test_s21_strncmp_9) {
  char *str1 = "Hello";
  char *str2 = "";
  s21_size_t n = 10;
  int s21_strncmp_result = 0;
  int strncmp_result = 0;

  s21_strncmp_result = s21_strncmp(str1, str2, n);
  strncmp_result = strncmp(str1, str2, n);

  ck_assert_int_eq(s21_strncmp_result, strncmp_result);
}
END_TEST

//  char* str1 = "Hello";
//  char* str2 = "hello";
//  s21_size_t n = 5;
START_TEST(test_s21_strncmp_10) {
  char *str1 = "Hello";
  char *str2 = "hello";
  s21_size_t n = 5;
  int s21_strncmp_result = 0;
  int strncmp_result = 0;

  s21_strncmp_result = s21_strncmp(str1, str2, n);
  strncmp_result = strncmp(str1, str2, n);

  ck_assert_int_eq(s21_strncmp_result, strncmp_result);
}
END_TEST

//  char* str1 = "Hëllo";
//  char* str2 = "Hëllö";
//  s21_size_t n = 5;
START_TEST(test_s21_strncmp_11) {
  char *str1 = "Hëllo";
  char *str2 = "Hëllö";
  s21_size_t n = 5;
  int s21_strncmp_result = 0;
  int strncmp_result = 0;

  s21_strncmp_result = s21_strncmp(str1, str2, n);
  strncmp_result = strncmp(str1, str2, n);

  ck_assert_int_eq(s21_strncmp_result, strncmp_result);
}
END_TEST

//  char* str1 = "Hello@#";
//  char* str2 = "Hello@!";
//  s21_size_t n = 7;
START_TEST(test_s21_strncmp_12) {
  char *str1 = "Hello@#";
  char *str2 = "Hello@!";
  s21_size_t n = 7;
  int s21_strncmp_result = 0;
  int strncmp_result = 0;

  s21_strncmp_result = s21_strncmp(str1, str2, n);
  strncmp_result = strncmp(str1, str2, n);

  ck_assert_int_eq(s21_strncmp_result, strncmp_result);
}
END_TEST

//  char* str1 = "Hello ";
//  char* str2 = "Hello";
//  s21_size_t n = 10;
START_TEST(test_s21_strncmp_13) {
  char *str1 = "Hello ";
  char *str2 = "Hello";
  s21_size_t n = 10;
  int s21_strncmp_result = 0;
  int strncmp_result = 0;

  s21_strncmp_result = s21_strncmp(str1, str2, n);
  strncmp_result = strncmp(str1, str2, n);

  ck_assert_int_eq(s21_strncmp_result, strncmp_result);
}
END_TEST

//  char* str1 = "Hello world";
//  char* str2 = "Hello";
//  s21_size_t n = 11;
START_TEST(test_s21_strncmp_14) {
  char *str1 = "Hello world";
  char *str2 = "Hello";
  s21_size_t n = 11;
  int s21_strncmp_result = 0;
  int strncmp_result = 0;

  s21_strncmp_result = s21_strncmp(str1, str2, n);
  strncmp_result = strncmp(str1, str2, n);

  ck_assert_int_eq(s21_strncmp_result, strncmp_result);
}
END_TEST

// const string or null ptr => sega
Suite *s21_strncmp_suite(void) {
  Suite *suite;
  TCase *tc_s21_strncmp;

  suite = suite_create("s21_strncmp");

  tc_s21_strncmp = tcase_create("S21_strncmp");

  tcase_add_test(tc_s21_strncmp, test_s21_strncmp_1);
  suite_add_tcase(suite, tc_s21_strncmp);

  tcase_add_test(tc_s21_strncmp, test_s21_strncmp_2);
  suite_add_tcase(suite, tc_s21_strncmp);

  tcase_add_test(tc_s21_strncmp, test_s21_strncmp_3);
  suite_add_tcase(suite, tc_s21_strncmp);

  tcase_add_test(tc_s21_strncmp, test_s21_strncmp_4);
  suite_add_tcase(suite, tc_s21_strncmp);

  tcase_add_test(tc_s21_strncmp, test_s21_strncmp_5);
  suite_add_tcase(suite, tc_s21_strncmp);

  tcase_add_test(tc_s21_strncmp, test_s21_strncmp_6);
  suite_add_tcase(suite, tc_s21_strncmp);

  tcase_add_test(tc_s21_strncmp, test_s21_strncmp_7);
  suite_add_tcase(suite, tc_s21_strncmp);

  tcase_add_test(tc_s21_strncmp, test_s21_strncmp_8);
  suite_add_tcase(suite, tc_s21_strncmp);

  tcase_add_test(tc_s21_strncmp, test_s21_strncmp_9);
  suite_add_tcase(suite, tc_s21_strncmp);

  tcase_add_test(tc_s21_strncmp, test_s21_strncmp_10);
  suite_add_tcase(suite, tc_s21_strncmp);

  tcase_add_test(tc_s21_strncmp, test_s21_strncmp_11);
  suite_add_tcase(suite, tc_s21_strncmp);

  tcase_add_test(tc_s21_strncmp, test_s21_strncmp_12);
  suite_add_tcase(suite, tc_s21_strncmp);

  tcase_add_test(tc_s21_strncmp, test_s21_strncmp_13);
  suite_add_tcase(suite, tc_s21_strncmp);

  tcase_add_test(tc_s21_strncmp, test_s21_strncmp_14);
  suite_add_tcase(suite, tc_s21_strncmp);

  return suite;
}