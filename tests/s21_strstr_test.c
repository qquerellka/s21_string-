#include "s21_check_string.h"

//  char *haystack = "Hello world!";
// подстрока не содержащаяся в первой
//  char *needle = "GEn_5";
START_TEST(test_s21_strstr_1) {
  char *haystack = "Hello world!";
  char *needle = "GEn_5";
  char *s21_strstr_result = NULL;
  char *strstr_result = NULL;

  s21_strstr_result = s21_strstr(haystack, needle);
  strstr_result = strstr(haystack, needle);

  ck_assert_ptr_eq(s21_strstr_result, strstr_result);
}
END_TEST

//  char *haystack = "Hello world!";
// подстрока не содержащаяся в первой
//  char *needle = "GEn_5";
// возвращает NULL
START_TEST(test_s21_strstr_2) {
  char *haystack = "Hello world!";
  char *needle = "GEn_5";
  char *s21_strstr_result = NULL;

  s21_strstr_result = s21_strstr(haystack, needle);

  ck_assert_ptr_null(s21_strstr_result);
}
END_TEST

//  char *haystack = "Hello world!";
// подстрока содержащаяся в первой
//  char *needle =  "world";
START_TEST(test_s21_strstr_3) {
  char *haystack = "Hello world!";
  char *needle = "world";
  char *s21_strstr_result = NULL;
  char *strstr_result = NULL;

  s21_strstr_result = s21_strstr(haystack, needle);
  strstr_result = strstr(haystack, needle);

  ck_assert_ptr_eq(s21_strstr_result, strstr_result);
}
END_TEST

//  char *haystack = "Hello world!";
// подстрока содержащаяся в первой
//  char *needle =  "world";
// сравниваем значеминя строк
START_TEST(test_s21_strstr_4) {
  char *haystack = "Hello world!";
  char *needle = "world";
  char *s21_strstr_result = NULL;
  char *strstr_result = NULL;

  s21_strstr_result = s21_strstr(haystack, needle);
  strstr_result = strstr(haystack, needle);

  ck_assert_str_eq(s21_strstr_result, strstr_result);
}
END_TEST

//  char *haystack = "Hello world!";
// подстрока содержащаяся в первой
//  char *needle =  "";
START_TEST(test_s21_strstr_5) {
  char *haystack = "Hello world!";
  char *needle = "";
  char *s21_strstr_result = NULL;
  char *strstr_result = NULL;

  s21_strstr_result = s21_strstr(haystack, needle);
  strstr_result = strstr(haystack, needle);

  ck_assert_ptr_eq(s21_strstr_result, strstr_result);
}
END_TEST

//  char *haystack = "Hello world!";
// короткая строка не содержащаяся в haystack
//  char *needle =  "TG";
START_TEST(test_s21_strstr_6) {
  char *haystack = "Hello world!";
  char *needle = "TG";
  char *s21_strstr_result = NULL;
  char *strstr_result = NULL;

  s21_strstr_result = s21_strstr(haystack, needle);
  strstr_result = strstr(haystack, needle);

  ck_assert_ptr_eq(s21_strstr_result, strstr_result);
}
END_TEST

//  char *haystack = "Hello world!";
// короткая строка не содержащаяся в haystack, но похожая
//  char *needle =  "llow";
START_TEST(test_s21_strstr_7) {
  char *haystack = "Hello world!";
  char *needle = "llow";
  char *s21_strstr_result = NULL;
  char *strstr_result = NULL;

  s21_strstr_result = s21_strstr(haystack, needle);
  strstr_result = strstr(haystack, needle);

  ck_assert_ptr_eq(s21_strstr_result, strstr_result);
}
END_TEST

//  char* haystack ="thereis no power as no knowledge";
// короткая строка не содержащаяся в haystack, но похожая
//  char* needle= "owed";
START_TEST(test_s21_strstr_8) {
  char *haystack = "thereis no power as no knowledge";
  char *needle = "owed";
  char *s21_strstr_result = NULL;
  char *strstr_result = NULL;

  s21_strstr_result = s21_strstr(haystack, needle);
  strstr_result = strstr(haystack, needle);

  ck_assert_ptr_eq(s21_strstr_result, strstr_result);
}
END_TEST

//  char* haystack = "owed";
//  char* needle= "thereis no power as no knowledge";
START_TEST(test_s21_strstr_9) {
  char *haystack = "owed";
  char *needle = "thereis no power as no knowledge";
  char *s21_strstr_result = NULL;
  char *strstr_result = NULL;

  s21_strstr_result = s21_strstr(haystack, needle);
  strstr_result = strstr(haystack, needle);

  ck_assert_ptr_eq(s21_strstr_result, strstr_result);
}
END_TEST

//  char *haystack = "";
// пустая строка и пустая подстрока
//  char *needle = "";
START_TEST(test_s21_strstr_10) {
  char *haystack = "";
  char *needle = "";
  char *s21_strstr_result = NULL;
  char *strstr_result = NULL;

  s21_strstr_result = s21_strstr(haystack, needle);
  strstr_result = strstr(haystack, needle);

  ck_assert_ptr_eq(s21_strstr_result, strstr_result);
}
END_TEST

//  char *haystack = "";
// пустая строка, needle не пустая
//  char *needle = "a";
START_TEST(test_s21_strstr_11) {
  char *haystack = "";
  char *needle = "a";
  char *s21_strstr_result = NULL;
  char *strstr_result = NULL;

  s21_strstr_result = s21_strstr(haystack, needle);
  strstr_result = strstr(haystack, needle);

  ck_assert_ptr_eq(s21_strstr_result, strstr_result);
}
END_TEST

//  char *haystack = "a";
// строка длиной 1 совпадает с подстрокой
//  char *needle = "a";
START_TEST(test_s21_strstr_12) {
  char *haystack = "a";
  char *needle = "a";
  char *s21_strstr_result = NULL;
  char *strstr_result = NULL;

  s21_strstr_result = s21_strstr(haystack, needle);
  strstr_result = strstr(haystack, needle);

  ck_assert_ptr_eq(s21_strstr_result, strstr_result);
}
END_TEST

//  char *haystack = "abc";
// подстрока длиннее строки
//  char *needle = "abcd";
START_TEST(test_s21_strstr_13) {
  char *haystack = "abc";
  char *needle = "abcd";
  char *s21_strstr_result = NULL;
  char *strstr_result = NULL;

  s21_strstr_result = s21_strstr(haystack, needle);
  strstr_result = strstr(haystack, needle);

  ck_assert_ptr_eq(s21_strstr_result, strstr_result);
}
END_TEST

//  char *haystack = "abcabcabc";
// подстрока встречается несколько раз, возвращается первое вхождение
//  char *needle = "abc";
START_TEST(test_s21_strstr_14) {
  char *haystack = "abcabcabc";
  char *needle = "abc";
  char *s21_strstr_result = NULL;
  char *strstr_result = NULL;

  s21_strstr_result = s21_strstr(haystack, needle);
  strstr_result = strstr(haystack, needle);

  ck_assert_ptr_eq(s21_strstr_result, strstr_result);
}
END_TEST

//  char *haystack = "abcabcabc";
// подстрока является строкой
//  char *needle = "abcabcabc";
START_TEST(test_s21_strstr_15) {
  char *haystack = "abcabcabc";
  char *needle = "abcabcabc";
  char *s21_strstr_result = NULL;
  char *strstr_result = NULL;

  s21_strstr_result = s21_strstr(haystack, needle);
  strstr_result = strstr(haystack, needle);

  ck_assert_ptr_eq(s21_strstr_result, strstr_result);
}
END_TEST

// const string or null ptr => sega
// выход за границы => sega
Suite *s21_strstr_suite(void) {
  Suite *suite;
  TCase *tc_s21_strstr;

  suite = suite_create("s21_strstr");

  tc_s21_strstr = tcase_create("S21_strstr");

  tcase_add_test(tc_s21_strstr, test_s21_strstr_1);
  suite_add_tcase(suite, tc_s21_strstr);

  tcase_add_test(tc_s21_strstr, test_s21_strstr_2);
  suite_add_tcase(suite, tc_s21_strstr);

  tcase_add_test(tc_s21_strstr, test_s21_strstr_3);
  suite_add_tcase(suite, tc_s21_strstr);

  tcase_add_test(tc_s21_strstr, test_s21_strstr_4);
  suite_add_tcase(suite, tc_s21_strstr);

  tcase_add_test(tc_s21_strstr, test_s21_strstr_5);
  suite_add_tcase(suite, tc_s21_strstr);

  tcase_add_test(tc_s21_strstr, test_s21_strstr_6);
  suite_add_tcase(suite, tc_s21_strstr);

  tcase_add_test(tc_s21_strstr, test_s21_strstr_7);
  suite_add_tcase(suite, tc_s21_strstr);

  tcase_add_test(tc_s21_strstr, test_s21_strstr_8);
  suite_add_tcase(suite, tc_s21_strstr);

  tcase_add_test(tc_s21_strstr, test_s21_strstr_9);
  suite_add_tcase(suite, tc_s21_strstr);

  tcase_add_test(tc_s21_strstr, test_s21_strstr_10);
  suite_add_tcase(suite, tc_s21_strstr);

  tcase_add_test(tc_s21_strstr, test_s21_strstr_11);
  suite_add_tcase(suite, tc_s21_strstr);

  tcase_add_test(tc_s21_strstr, test_s21_strstr_12);
  suite_add_tcase(suite, tc_s21_strstr);

  tcase_add_test(tc_s21_strstr, test_s21_strstr_13);
  suite_add_tcase(suite, tc_s21_strstr);

  tcase_add_test(tc_s21_strstr, test_s21_strstr_14);
  suite_add_tcase(suite, tc_s21_strstr);

  tcase_add_test(tc_s21_strstr, test_s21_strstr_15);
  suite_add_tcase(suite, tc_s21_strstr);

  return suite;
}