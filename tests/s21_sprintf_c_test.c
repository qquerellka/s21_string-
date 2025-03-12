#include "s21_check_string.h"

START_TEST(test_s21_sprintf_c_1) {
  char *str = "there is no power %-0c as no knowledge";
  char ch = 'g';
  char str1[1024] = {0};
  char str2[1024] = {0};

  s21_sprintf(str1, str, ch);
  sprintf(str2, str, ch);

  ck_assert_str_eq(str1, str2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_c_2) {
  char *str = "there is no power %c as %%no %c knowledge";
  char ch = 'g';
  char str1[1024] = {0};
  char str2[1024] = {0};

  s21_sprintf(str1, str, ch, ch);
  sprintf(str2, str, ch, ch);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_c_3) {
  char *str = "there is no power %.5c as %%no %c knowledge";
  char ch = 'g';
  char arr1[1024] = {0};
  char arr2[1024] = {0};

  s21_sprintf(arr1, str, ch, ch);
  sprintf(arr2, str, ch, ch);

  ck_assert_str_eq(arr1, arr2);
}
END_TEST

START_TEST(test_s21_sprintf_c_4) {
  char str1[100];
  char str2[100];

  char *str3 = "%-010c Test % -10c Test %-lc";
  int a = 74;
  unsigned long int b = 74;

  ck_assert_int_eq(sprintf(str1, str3, a, a, b),
                   s21_sprintf(str2, str3, a, a, b));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_c_5) {
  char str1[100];
  char str2[100];
  char *str3 = "%6.4c Test %-6.4c Test %4.10lc Test %-4.10lc Test %-0lc";
  int a = 10;
  unsigned long int b = 10;
  unsigned long int c = 10;
  ck_assert_int_eq(sprintf(str1, str3, a, a, b, c, c),
                   s21_sprintf(str2, str3, a, a, b, c, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_c_6) {
  char str1[100];
  char str2[100];
  char *str3 = "%#c Test %#c Test %#c Test %#c Test %#c";
  ck_assert_int_eq(sprintf(str1, str3, ' ', 'n', '5', '%', '\\'),
                   s21_sprintf(str2, str3, ' ', 'n', '5', '%', '\\'));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_c_7) {
  char str1[400];
  char str2[400];
  char *str3 = "%.9c Test % -.7c Test %- 050c Test %- 54c Test %-0188c";
  int a = 45;
  ck_assert_int_eq(sprintf(str1, str3, a, a, a, a, a),
                   s21_sprintf(str2, str3, a, a, a, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_c_8) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %lc Test %hc";
  int a = 3;
  unsigned long int b = 103;
  unsigned short e = 255;
  ck_assert_int_eq(sprintf(str1, str3, a, b, e),
                   s21_sprintf(str2, str3, a, b, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_c_9) {
  char str1[100];
  char str2[100];
  char *str3 = "%.c Test %lc Test %hc";
  int a = 3;
  unsigned long int b = 103;
  unsigned short e = 255;
  ck_assert_int_eq(sprintf(str1, str3, a, b, e),
                   s21_sprintf(str2, str3, a, b, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *s21_sprintf_c_suite(void) {
  Suite *suite;
  TCase *tc_s21_sprintf_c;

  suite = suite_create("s21_sprintf_c");

  tc_s21_sprintf_c = tcase_create("S21_sprintf_c");

  tcase_add_test(tc_s21_sprintf_c, test_s21_sprintf_c_1);
  suite_add_tcase(suite, tc_s21_sprintf_c);

  tcase_add_test(tc_s21_sprintf_c, test_s21_sprintf_c_2);
  suite_add_tcase(suite, tc_s21_sprintf_c);

  tcase_add_test(tc_s21_sprintf_c, test_s21_sprintf_c_3);
  suite_add_tcase(suite, tc_s21_sprintf_c);

  tcase_add_test(tc_s21_sprintf_c, test_s21_sprintf_c_4);
  suite_add_tcase(suite, tc_s21_sprintf_c);

  tcase_add_test(tc_s21_sprintf_c, test_s21_sprintf_c_5);
  suite_add_tcase(suite, tc_s21_sprintf_c);

  tcase_add_test(tc_s21_sprintf_c, test_s21_sprintf_c_6);
  suite_add_tcase(suite, tc_s21_sprintf_c);

  tcase_add_test(tc_s21_sprintf_c, test_s21_sprintf_c_7);
  suite_add_tcase(suite, tc_s21_sprintf_c);

  tcase_add_test(tc_s21_sprintf_c, test_s21_sprintf_c_8);
  suite_add_tcase(suite, tc_s21_sprintf_c);

  tcase_add_test(tc_s21_sprintf_c, test_s21_sprintf_c_9);
  suite_add_tcase(suite, tc_s21_sprintf_c);

  return suite;
}