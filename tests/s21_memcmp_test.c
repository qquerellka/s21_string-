#include "s21_check_string.h"

//   char* str1 = "Hello world!";
//   char* str2 = "Hello world!";
//   size_t n = 10;
START_TEST(test_s21_memcmp_1) {
  char *str1 = "Hello world!";
  char *str2 = "Hello world!";
  size_t n = 10;
  int s21_memcmp_result = 0;
  int memcmp_result = 0;

  s21_memcmp_result = s21_memcmp(str1, str2, n);
  memcmp_result = memcmp(str1, str2, n);

  ck_assert_msg(s21_memcmp_result == memcmp_result,
                "Значения : %d и %d не совпадают", s21_memcmp_result,
                memcmp_result);
}
END_TEST

//   char* str1 = "Hello world!";
//   char* str2 = "Hello world!";
//   size_t n = 50;
START_TEST(test_s21_memcmp_2) {
  char *str1 = "Hello world!";
  char *str2 = "Hello world!";
  size_t n = 13;
  int s21_memcmp_result = 0;
  int memcmp_result = 0;

  s21_memcmp_result = s21_memcmp(str1, str2, n);
  memcmp_result = memcmp(str1, str2, n);

  ck_assert_msg(s21_memcmp_result == memcmp_result,
                "Значения : %d и %d не совпадают", s21_memcmp_result,
                memcmp_result);
}
END_TEST

//   char* str1 = "Hello world!";
//   char* str2 = "Hello world!";
//   size_t n = 0;
START_TEST(test_s21_memcmp_3) {
  char *str1 = "Hello world!";
  char *str2 = "Hello world!";
  size_t n = 0;
  int s21_memcmp_result = 0;
  int memcmp_result = 0;

  s21_memcmp_result = s21_memcmp(str1, str2, n);
  memcmp_result = memcmp(str1, str2, n);

  ck_assert_msg(s21_memcmp_result == memcmp_result,
                "Значения : %d и %d не совпадают", s21_memcmp_result,
                memcmp_result);
}
END_TEST

//   char* str1 = "Hello world!";
//   char* str2 = "Hello";
//   size_t n = 10;
START_TEST(test_s21_memcmp_4) {
  char *str1 = "Hello world!";
  char *str2 = "Hello";
  size_t n = 6;
  int s21_memcmp_result = 0;
  int memcmp_result = 0;

  s21_memcmp_result = s21_memcmp(str1, str2, n);
  memcmp_result = memcmp(str1, str2, n);

  ck_assert_msg(s21_memcmp_result == memcmp_result,
                "Значения : %d и %d не совпадают", s21_memcmp_result,
                memcmp_result);
}
END_TEST

//   char* str1 = "Hello world!";
//   char* str2 = "Hello";
//   size_t n = 50;
START_TEST(test_s21_memcmp_5) {
  char *str1 = "Hello world!";
  char *str2 = "Hello";
  size_t n = 6;
  int s21_memcmp_result = 0;
  int memcmp_result = 0;

  s21_memcmp_result = s21_memcmp(str1, str2, n);
  memcmp_result = memcmp(str1, str2, n);

  ck_assert_msg(s21_memcmp_result == memcmp_result,
                "Значения : %d и %d не совпадают", s21_memcmp_result,
                memcmp_result);
}
END_TEST

//   char* str1 = "Hello world!";
//   char* str2 = "Hello";
//   size_t n = strlen(str1);
START_TEST(test_s21_memcmp_6) {
  char *str1 = "Hello world!";
  char *str2 = "Hello";
  size_t n = strlen(str1);
  int s21_memcmp_result = 0;
  int memcmp_result = 0;

  s21_memcmp_result = s21_memcmp(str1, str2, n);
  memcmp_result = memcmp(str1, str2, n);

  ck_assert_msg(s21_memcmp_result == memcmp_result,
                "Значения : %d и %d не совпадают", s21_memcmp_result,
                memcmp_result);
}
END_TEST

//   char* str1 = "Hello world!";
//   char* str2 = "Hello world!";
//   size_t n = -5;
START_TEST(test_s21_memcmp_7) {
  char *str1 = "Hello world!";
  char *str2 = "Hello world!";
  size_t n = 13;
  int s21_memcmp_result = 0;
  int memcmp_result = 0;

  s21_memcmp_result = s21_memcmp(str1, str2, n);
  memcmp_result = memcmp(str1, str2, n);

  ck_assert_msg(s21_memcmp_result == memcmp_result,
                "Значения : %d и %d не совпадают", s21_memcmp_result,
                memcmp_result);
}
END_TEST

//   char* str1 = "Hello world!";
//   char* str2 = "Hello_world!";
//   size_t n = -5;
START_TEST(test_s21_memcmp_8) {
  char *str1 = "Hello world!";
  char *str2 = "Hello_world!";
  size_t n = 13;
  int s21_memcmp_result = 0;
  int memcmp_result = 0;

  s21_memcmp_result = s21_memcmp(str1, str2, n);
  memcmp_result = memcmp(str1, str2, n);

  ck_assert_msg(s21_memcmp_result == memcmp_result,
                "Значения : %d и %d не совпадают", s21_memcmp_result,
                memcmp_result);
}
END_TEST

//   char* str1 = "Hello";
//   char* str2 = "Hello world!";
//   size_t n = 10;
START_TEST(test_s21_memcmp_9) {
  char *str1 = "Hello";
  char *str2 = "Hello world!";
  size_t n = 6;
  int s21_memcmp_result = 0;
  int memcmp_result = 0;

  s21_memcmp_result = s21_memcmp(str1, str2, n);
  memcmp_result = memcmp(str1, str2, n);

  ck_assert_msg(s21_memcmp_result == memcmp_result,
                "Значения : %d и %d не совпадают", s21_memcmp_result,
                memcmp_result);
}
END_TEST

//   char* str1 = "";
//   char* str2 = "";
//   size_t n = 0;
START_TEST(test_s21_memcmp_10) {
  char *str1 = "";
  char *str2 = "";
  size_t n = 0;

  int s21_memcmp_result = s21_memcmp(str1, str2, n);
  int memcmp_result = memcmp(str1, str2, n);

  ck_assert_msg(s21_memcmp_result == memcmp_result,
                "Значения : %d и %d не совпадают", s21_memcmp_result,
                memcmp_result);
}
END_TEST

//   char* str1 = "A";
//   char* str2 = "B";
//   size_t n = 1;
START_TEST(test_s21_memcmp_11) {
  char *str1 = "A";
  char *str2 = "B";
  size_t n = 1;

  int s21_memcmp_result = s21_memcmp(str1, str2, n);
  int memcmp_result = memcmp(str1, str2, n);

  ck_assert_msg(s21_memcmp_result == memcmp_result,
                "Значения : %d и %d не совпадают", s21_memcmp_result,
                memcmp_result);
}
END_TEST

//   char* str1 = "abc\0def";
//   char* str2 = "abc\0xyz";
//   size_t n = 7;
START_TEST(test_s21_memcmp_12) {
  char *str1 = "abc\0def";
  char *str2 = "abc\0xyz";
  size_t n = 7;

  int s21_memcmp_result = s21_memcmp(str1, str2, n);
  int memcmp_result = memcmp(str1, str2, n);

  ck_assert_msg(s21_memcmp_result == memcmp_result,
                "Значения : %d и %d не совпадают", s21_memcmp_result,
                memcmp_result);
}
END_TEST

//   char* str1 = "12345";
//   char* str2 = "12345";
//   size_t n = 100;
START_TEST(test_s21_memcmp_13) {
  char *str1 = "12345";
  char *str2 = "12345";
  size_t n = 6;

  int s21_memcmp_result = s21_memcmp(str1, str2, n);
  int memcmp_result = memcmp(str1, str2, n);

  ck_assert_msg(s21_memcmp_result == memcmp_result,
                "Значения : %d и %d не совпадают", s21_memcmp_result,
                memcmp_result);
}
END_TEST

//   char* str1 = "\xff\xfe\xfd";
//   char* str2 = "\xff\xfe\xfc";
//   size_t n = 3;
START_TEST(test_s21_memcmp_14) {
  char str1[] = {0xFF, 0xFE, 0xFD};
  char str2[] = {0xFF, 0xFE, 0xFC};
  size_t n = 3;

  int s21_memcmp_result = s21_memcmp(str1, str2, n);
  int memcmp_result = memcmp(str1, str2, n);

  ck_assert_msg(s21_memcmp_result == memcmp_result,
                "Значения : %d и %d не совпадают", s21_memcmp_result,
                memcmp_result);
}
END_TEST
//

Suite *s21_memcmp_suite(void) {
  Suite *suite;
  TCase *tc_s21_memcmp;

  suite = suite_create("s21_memcmp");

  tc_s21_memcmp = tcase_create("S21_memcmp");

  tcase_add_test(tc_s21_memcmp, test_s21_memcmp_1);
  suite_add_tcase(suite, tc_s21_memcmp);

  tcase_add_test(tc_s21_memcmp, test_s21_memcmp_2);
  suite_add_tcase(suite, tc_s21_memcmp);

  tcase_add_test(tc_s21_memcmp, test_s21_memcmp_3);
  suite_add_tcase(suite, tc_s21_memcmp);

  tcase_add_test(tc_s21_memcmp, test_s21_memcmp_4);
  suite_add_tcase(suite, tc_s21_memcmp);

  tcase_add_test(tc_s21_memcmp, test_s21_memcmp_5);
  suite_add_tcase(suite, tc_s21_memcmp);

  tcase_add_test(tc_s21_memcmp, test_s21_memcmp_6);
  suite_add_tcase(suite, tc_s21_memcmp);

  tcase_add_test(tc_s21_memcmp, test_s21_memcmp_7);
  suite_add_tcase(suite, tc_s21_memcmp);

  tcase_add_test(tc_s21_memcmp, test_s21_memcmp_8);
  suite_add_tcase(suite, tc_s21_memcmp);

  tcase_add_test(tc_s21_memcmp, test_s21_memcmp_9);
  suite_add_tcase(suite, tc_s21_memcmp);

  tcase_add_test(tc_s21_memcmp, test_s21_memcmp_10);
  suite_add_tcase(suite, tc_s21_memcmp);

  tcase_add_test(tc_s21_memcmp, test_s21_memcmp_11);
  suite_add_tcase(suite, tc_s21_memcmp);

  tcase_add_test(tc_s21_memcmp, test_s21_memcmp_12);
  suite_add_tcase(suite, tc_s21_memcmp);

  tcase_add_test(tc_s21_memcmp, test_s21_memcmp_13);
  suite_add_tcase(suite, tc_s21_memcmp);

  tcase_add_test(tc_s21_memcmp, test_s21_memcmp_14);
  suite_add_tcase(suite, tc_s21_memcmp);

  return suite;
}