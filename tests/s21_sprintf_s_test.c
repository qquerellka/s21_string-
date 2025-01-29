#include "s21_check_string.h"

START_TEST(test_s21_sprintf_s_1) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %s Test";
  char *val = "Why am I here?!";

  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_s_2) {
  char str1[100];
  char str2[100];
  char *str3 = "%s Test %s Test %s";
  char *val = "I'm so tired";
  char *val2 = "Who invented this?";
  char *val3 = "This project gave me hemmoroids";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_s_3) {
  char str1[100];
  char str2[100];
  char *str3 = "%s Test %s Test %s";
  char *val = "Don't need this test";
  char *val2 = "Just for the kicks";
  char *val3 = "Lol";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_s_4) {
  char str1[100];
  char str2[100];
  char *str3 = "Test %ls Test2";
  wchar_t *val = L"3wtf80";
  sprintf(str1, str3, val);
  s21_sprintf(str2, str3, val);

  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_s_5) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.0s Test %.23s Test %3.s TEST %.s";
  char *val = "WHere DeToNaToR";
  char *val2 = "i don't care anymore, really";
  char *val3 = "PPAP";
  char *val4 = "I don't feel so good";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_s_6) {
  char str1[200];
  char str2[200];
  char *str3 = "%s Test %3.s Test %5.7s TEST %10s %#s %-s %+s %.s % .s";
  char *val = NULL;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_s_7) {
  char str1[200];
  char str2[200];
  char *str3 = "%*s woop woop woop %-*s Test %*.*s TEST %.*s";
  char *val = "WHAT IS THIS";
  char *val2 = "i'm so tired from sprintf... really";
  char *val3 = "and i dont carwe";
  char *val4 = "I don't feel so good";
  int ast = 2;
  int ast2 = 5;
  int ast3 = 4;
  int ast4 = 10;
  int ast5 = 7;

  ck_assert_int_eq(
      sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4),
      s21_sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5,
                  val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_s_8) {
  char str1[100];
  char str2[100];
  char *str3 = "%s %s %02s %%woops %[percent] %d";
  char *val = "Love is in the air";
  char *val2 = "\0";
  int val3 = 65;
  char *val4 = "s";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val4, val3),
                   s21_sprintf(str2, str3, val, val2, val4, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_s_9) {
  char str1[100];
  char str2[100];
  char *str3 = "%0s %+s %s %% %d";
  char *val = "pop Up";
  char *val2 = "\0";
  int val3 = 65;
  char *val4 = "s";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val4, val3),
                   s21_sprintf(str2, str3, val, val2, val4, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *s21_sprintf_s_suite(void) {
  Suite *suite;
  TCase *tc_s21_sprintf_s;

  suite = suite_create("s21_sprintf_s");

  tc_s21_sprintf_s = tcase_create("S21_sprintf_s");

  tcase_add_test(tc_s21_sprintf_s, test_s21_sprintf_s_1);
  suite_add_tcase(suite, tc_s21_sprintf_s);

  tcase_add_test(tc_s21_sprintf_s, test_s21_sprintf_s_2);
  suite_add_tcase(suite, tc_s21_sprintf_s);

  tcase_add_test(tc_s21_sprintf_s, test_s21_sprintf_s_3);
  suite_add_tcase(suite, tc_s21_sprintf_s);

  tcase_add_test(tc_s21_sprintf_s, test_s21_sprintf_s_4);
  suite_add_tcase(suite, tc_s21_sprintf_s);

  tcase_add_test(tc_s21_sprintf_s, test_s21_sprintf_s_5);
  suite_add_tcase(suite, tc_s21_sprintf_s);

  tcase_add_test(tc_s21_sprintf_s, test_s21_sprintf_s_6);
  suite_add_tcase(suite, tc_s21_sprintf_s);

  tcase_add_test(tc_s21_sprintf_s, test_s21_sprintf_s_7);
  suite_add_tcase(suite, tc_s21_sprintf_s);

  tcase_add_test(tc_s21_sprintf_s, test_s21_sprintf_s_8);
  suite_add_tcase(suite, tc_s21_sprintf_s);

  tcase_add_test(tc_s21_sprintf_s, test_s21_sprintf_s_9);
  suite_add_tcase(suite, tc_s21_sprintf_s);

  return suite;
}