#include "s21_check_string.h"

//  char *str = "Hello world!";
// символ, содержащийся в строке
//  char c = 'w';
START_TEST(test_s21_strrchr_1) {
  char *str = "Hello world!";
  char c = 'w';
  char *s21_strrchr_result = NULL;
  char *strrchr_result = NULL;

  s21_strrchr_result = s21_strrchr(str, c);
  strrchr_result = strrchr(str, c);

  ck_assert_ptr_eq(s21_strrchr_result, strrchr_result);
}
END_TEST

//  char *str = "Hello world!";
// символ, не содержащийся в строке
//  char c = ']';
START_TEST(test_s21_strrchr_2) {
  char *str = "Hello world!";
  char c = ']';
  char *s21_strrchr_result = NULL;
  char *strrchr_result = NULL;

  s21_strrchr_result = s21_strrchr(str, c);
  strrchr_result = strrchr(str, c);

  ck_assert_ptr_eq(s21_strrchr_result, strrchr_result);
}
END_TEST

//  char *str = "Hello world!";
// нулевой символ
//  char c = '\0';
START_TEST(test_s21_strrchr_3) {
  char *str = "Hello world!";
  char c = '\0';
  char *s21_strrchr_result = NULL;
  char *strrchr_result = NULL;

  s21_strrchr_result = s21_strrchr(str, c);
  strrchr_result = strrchr(str, c);

  ck_assert_ptr_eq(s21_strrchr_result, strrchr_result);
}
END_TEST

//  char *str = "bytecode\0why";
// нулевой символ
//  char c = '\0';
START_TEST(test_s21_strrchr_4) {
  char *str = "bytecode\0why";
  char c = '\0';
  char *s21_strrchr_result = NULL;
  char *strrchr_result = NULL;

  s21_strrchr_result = s21_strrchr(str, c);
  strrchr_result = strrchr(str, c);

  ck_assert_ptr_eq(s21_strrchr_result, strrchr_result);
}
END_TEST

START_TEST(test_s21_strrchr_5) {
  char *str = "abcabcabc";
  char c = 'b';
  char *s21_strrchr_result = NULL;
  char *strrchr_result = NULL;

  s21_strrchr_result = s21_strrchr(str, c);
  strrchr_result = strrchr(str, c);

  ck_assert_ptr_eq(s21_strrchr_result, strrchr_result);
}
END_TEST

//  char *str = "abcabcabc";
// символ, находящийся в начале строки
//  char c = 'a';
START_TEST(test_s21_strrchr_6) {
  char *str = "abcabcabc";
  char c = 'a';
  char *s21_strrchr_result = NULL;
  char *strrchr_result = NULL;

  s21_strrchr_result = s21_strrchr(str, c);
  strrchr_result = strrchr(str, c);

  ck_assert_ptr_eq(s21_strrchr_result, strrchr_result);
}
END_TEST

//  char *str = "abcabcabc";
// символ, находящийся в конце строки
//  char c = 'c';
START_TEST(test_s21_strrchr_7) {
  char *str = "abcabcabc";
  char c = 'c';
  char *s21_strrchr_result = NULL;
  char *strrchr_result = NULL;

  s21_strrchr_result = s21_strrchr(str, c);
  strrchr_result = strrchr(str, c);

  ck_assert_ptr_eq(s21_strrchr_result, strrchr_result);
}
END_TEST

//  char *str = "";
// пустая строка
//  char c = 'a';
START_TEST(test_s21_strrchr_8) {
  char *str = "";
  char c = 'a';
  char *s21_strrchr_result = NULL;
  char *strrchr_result = NULL;

  s21_strrchr_result = s21_strrchr(str, c);
  strrchr_result = strrchr(str, c);

  ck_assert_ptr_eq(s21_strrchr_result, strrchr_result);
}
END_TEST

//  char *str = "a";
// строка длиной 1
//  char c = 'a';
START_TEST(test_s21_strrchr_9) {
  char *str = "a";
  char c = 'a';
  char *s21_strrchr_result = NULL;
  char *strrchr_result = NULL;

  s21_strrchr_result = s21_strrchr(str, c);
  strrchr_result = strrchr(str, c);

  ck_assert_ptr_eq(s21_strrchr_result, strrchr_result);
}
END_TEST

//  char *str = "aaaaaaaaaa";
// строка из одинаковых символов
//  char c = 'a';
START_TEST(test_s21_strrchr_10) {
  char *str = "aaaaaaaaaa";
  char c = 'a';
  char *s21_strrchr_result = NULL;
  char *strrchr_result = NULL;

  s21_strrchr_result = s21_strrchr(str, c);
  strrchr_result = strrchr(str, c);

  ck_assert_ptr_eq(s21_strrchr_result, strrchr_result);
}
END_TEST

// const string or null ptr => sega
// выход за границы => sega
Suite *s21_strrchr_suite(void) {
  Suite *suite;
  TCase *tc_s21_strrchr;

  suite = suite_create("s21_strrchr");

  tc_s21_strrchr = tcase_create("S21_strrchr");

  tcase_add_test(tc_s21_strrchr, test_s21_strrchr_1);
  suite_add_tcase(suite, tc_s21_strrchr);

  tcase_add_test(tc_s21_strrchr, test_s21_strrchr_2);
  suite_add_tcase(suite, tc_s21_strrchr);

  tcase_add_test(tc_s21_strrchr, test_s21_strrchr_3);
  suite_add_tcase(suite, tc_s21_strrchr);

  tcase_add_test(tc_s21_strrchr, test_s21_strrchr_4);
  suite_add_tcase(suite, tc_s21_strrchr);

  tcase_add_test(tc_s21_strrchr, test_s21_strrchr_5);
  suite_add_tcase(suite, tc_s21_strrchr);

  tcase_add_test(tc_s21_strrchr, test_s21_strrchr_6);
  suite_add_tcase(suite, tc_s21_strrchr);

  tcase_add_test(tc_s21_strrchr, test_s21_strrchr_7);
  suite_add_tcase(suite, tc_s21_strrchr);

  tcase_add_test(tc_s21_strrchr, test_s21_strrchr_8);
  suite_add_tcase(suite, tc_s21_strrchr);

  tcase_add_test(tc_s21_strrchr, test_s21_strrchr_9);
  suite_add_tcase(suite, tc_s21_strrchr);

  tcase_add_test(tc_s21_strrchr, test_s21_strrchr_10);
  suite_add_tcase(suite, tc_s21_strrchr);

  return suite;
}