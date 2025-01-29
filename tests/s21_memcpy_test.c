#include "s21_check_string.h"

//  char dest_s21[] = "Hello world!";
//  char dest[] = "Hello world!";
//  char *src = "KHA..An!!11";
//  size_t n = 10;
START_TEST(test_s21_memcpy_1) {
  char dest_s21[] = "Hello world!";
  char dest[] = "Hello world!";
  char *src = "KHA..An!!11";
  size_t n = 10;
  char *s21_memcpy_result = NULL;
  char *memcpy_result = NULL;

  s21_memcpy_result = (char *)s21_memcpy(dest_s21, src, n);
  memcpy_result = (char *)memcpy(dest, src, n);

  ck_assert_str_eq(s21_memcpy_result, memcpy_result);
}
END_TEST

//  char dest_s21[] = "there is no power as no knowledge";
//  char dest[] = "there is no power as no knowledge";
//  char *src = "Hello";
//  size_t n = 10;
START_TEST(test_s21_memcpy_2) {
  char dest_s21[] = "there is no power as no knowledge";
  char dest[] = "there is no power as no knowledge";
  char *src = "Hello";
  size_t n = 6;
  char *s21_memcpy_result = NULL;
  char *memcpy_result = NULL;

  s21_memcpy_result = (char *)s21_memcpy(dest_s21, src, n);
  memcpy_result = (char *)memcpy(dest, src, n);

  ck_assert_str_eq(s21_memcpy_result, memcpy_result);
}
END_TEST

//  char dest_s21[] = "there is no power as no knowledge";
//  char dest[] = "there is no power as no knowledge";
//  char *src = "bytecode\0why";
//  size_t n = 10;
START_TEST(test_s21_memcpy_3) {
  char dest_s21[] = "there is no power as no knowledge";
  char dest[] = "there is no power as no knowledge";
  char *src = "bytecode\0why";
  size_t n = 10;
  char *s21_memcpy_result = NULL;
  char *memcpy_result = NULL;

  s21_memcpy_result = (char *)s21_memcpy(dest_s21, src, n);
  memcpy_result = (char *)memcpy(dest, src, n);

  ck_assert_str_eq(s21_memcpy_result, memcpy_result);
}
END_TEST

//  char dest_s21[] = "there is no power as no knowledge";
//  char dest[] = "there is no power as no knowledge";
//  char *src = "bytecode\0why";
//  size_t n = 0;
START_TEST(test_s21_memcpy_4) {
  char dest_s21[] = "there is no power as no knowledge";
  char dest[] = "there is no power as no knowledge";
  char *src = "bytecode\0why";
  size_t n = 0;
  char *s21_memcpy_result = NULL;
  char *memcpy_result = NULL;

  s21_memcpy_result = (char *)s21_memcpy(dest_s21, src, n);
  memcpy_result = (char *)memcpy(dest, src, n);

  ck_assert_str_eq(s21_memcpy_result, memcpy_result);
}
END_TEST

START_TEST(test_s21_memcpy_5) {
  char dest_s21[50] = {0};
  char dest[50] = {0};
  char *src = "Test data";
  size_t n = 10;

  char *s21_memcpy_result = (char *)s21_memcpy(dest_s21, src, n);
  char *memcpy_result = (char *)memcpy(dest, src, n);

  ck_assert_str_eq(s21_memcpy_result, memcpy_result);
}
END_TEST

START_TEST(test_s21_memcpy_6) {
  char dest_s21[] = "Some string";
  char dest[] = "Some string";
  char *src = "New data";
  size_t n = 0;

  char *s21_memcpy_result = (char *)s21_memcpy(dest_s21, src, n);
  char *memcpy_result = (char *)memcpy(dest, src, n);

  ck_assert_str_eq(s21_memcpy_result, memcpy_result);
}
END_TEST

START_TEST(test_s21_memcpy_7) {
  char dest_s21[20] = {0};
  char dest[20] = {0};
  char *src = "Hello";
  size_t n = 6;

  char *s21_memcpy_result = (char *)s21_memcpy(dest_s21, src, n);
  char *memcpy_result = (char *)memcpy(dest, src, n);

  ck_assert_str_eq(s21_memcpy_result, memcpy_result);
}
END_TEST

START_TEST(test_s21_memcpy_8) {
  char dest_s21[20] = {0};
  char dest[20] = {0};
  char *src = "Short";
  size_t n = 6;

  char *s21_memcpy_result = (char *)s21_memcpy(dest_s21, src, n);
  char *memcpy_result = (char *)memcpy(dest, src, n);

  ck_assert_str_eq(s21_memcpy_result, memcpy_result);
}
END_TEST

START_TEST(test_s21_memcpy_10) {
  char dest_s21[10001] = {0};  // Инициализация памяти
  char dest[10001] = {0};
  char src[10001] = {0};

  s21_memset(src, 'A', 10000);
  size_t n = 10000;

  char *s21_memcpy_result = (char *)s21_memcpy(dest_s21, src, n);
  char *memcpy_result = (char *)memcpy(dest, src, n);

  ck_assert_mem_eq(s21_memcpy_result, memcpy_result, n);
}
END_TEST

Suite *s21_memcpy_suite(void) {
  Suite *suite;
  TCase *tc_s21_memcpy;

  suite = suite_create("s21_memcpy");

  tc_s21_memcpy = tcase_create("Core");

  tcase_add_test(tc_s21_memcpy, test_s21_memcpy_1);
  suite_add_tcase(suite, tc_s21_memcpy);

  tcase_add_test(tc_s21_memcpy, test_s21_memcpy_2);
  suite_add_tcase(suite, tc_s21_memcpy);

  tcase_add_test(tc_s21_memcpy, test_s21_memcpy_3);
  suite_add_tcase(suite, tc_s21_memcpy);

  tcase_add_test(tc_s21_memcpy, test_s21_memcpy_4);
  suite_add_tcase(suite, tc_s21_memcpy);

  tcase_add_test(tc_s21_memcpy, test_s21_memcpy_5);
  suite_add_tcase(suite, tc_s21_memcpy);

  tcase_add_test(tc_s21_memcpy, test_s21_memcpy_6);
  suite_add_tcase(suite, tc_s21_memcpy);

  tcase_add_test(tc_s21_memcpy, test_s21_memcpy_7);
  suite_add_tcase(suite, tc_s21_memcpy);

  tcase_add_test(tc_s21_memcpy, test_s21_memcpy_8);
  suite_add_tcase(suite, tc_s21_memcpy);

  tcase_add_test(tc_s21_memcpy, test_s21_memcpy_10);
  suite_add_tcase(suite, tc_s21_memcpy);

  return suite;
}
