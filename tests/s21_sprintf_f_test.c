#include "s21_check_string.h"

START_TEST(test_s21_sprintf_f_1) {
  char str1[100] = "";
  char str2[100] = "";
  char *str = "Test %f Test%f";
  float var = 1.3;

  ck_assert_int_eq(sprintf(str1, str, var, var),
                   s21_sprintf(str2, str, var, var));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_f_2) {
  char str1[400];
  char str2[400];
  char *str = "%020.10f\n%20.15f\n%-20.5f!";
  double var = -76.756589;

  ck_assert_int_eq(sprintf(str1, str, var, var, var),
                   s21_sprintf(str2, str, var, var, var));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_f_3) {
  char str1[400];
  char str2[400];
  char *str =
      "test: %+- 010.2f!\ntest: %- #025.f\ntest: %+- 18.4f!\n%- 025.f\n";
  double var = -1023.9384905;
  ck_assert_int_eq(sprintf(str1, str, var, var, var, var),
                   s21_sprintf(str2, str, var, var, var, var));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_f_4) {
  char str1[400];
  char str2[400];
  char *str = "test: %+ 50.15Lf!\ntest: % +40.15Lf!";
  long double var = 278.723786;

  ck_assert_int_eq(sprintf(str1, str, var, var),
                   s21_sprintf(str2, str, var, var));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_f_5) {
  char str1[400];
  char str2[400];
  char *str = "test: %.1Lf!\ntest: %.2Lf!\ntest: %.3Lf!";
  long double var = -9999.99999;

  ck_assert_int_eq(sprintf(str1, str, var, var, var),
                   s21_sprintf(str2, str, var, var, var));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *s21_sprintf_f_suite(void) {
  Suite *suite;
  TCase *tc_s21_sprintf_f;

  suite = suite_create("s21_sprintf_f");

  tc_s21_sprintf_f = tcase_create("S21_sprintf_f");

  tcase_add_test(tc_s21_sprintf_f, test_s21_sprintf_f_1);
  suite_add_tcase(suite, tc_s21_sprintf_f);

  tcase_add_test(tc_s21_sprintf_f, test_s21_sprintf_f_2);
  suite_add_tcase(suite, tc_s21_sprintf_f);

  tcase_add_test(tc_s21_sprintf_f, test_s21_sprintf_f_3);
  suite_add_tcase(suite, tc_s21_sprintf_f);

  tcase_add_test(tc_s21_sprintf_f, test_s21_sprintf_f_4);
  suite_add_tcase(suite, tc_s21_sprintf_f);

  tcase_add_test(tc_s21_sprintf_f, test_s21_sprintf_f_5);
  suite_add_tcase(suite, tc_s21_sprintf_f);

  return suite;
}