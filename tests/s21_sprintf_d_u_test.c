#include "s21_check_string.h"

START_TEST(test_s21_sprintf_d_u_1) {
  char str1[100];
  char str2[100];
  char *str3 = "%u Test %u %Test %lu";
  unsigned int val = 012;
  unsigned int val2 = 017;
  unsigned int val3 = 7464;

  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_d_u_2) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5u Test %-.8u Test %-7u TEST %-.u";
  unsigned int val = 3015;
  unsigned int val2 = 712;
  unsigned int val3 = 99;
  unsigned int val4 = 2939;

  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_d_u_3) {
  char str1[100];
  char str2[100];
  char *str3 = "%lu not %lu  Enough %hu";
  long unsigned int val = 3088675747373646;
  long unsigned val2 = 33030030303;
  unsigned short val3 = 22600;

  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_d_u_4) {
  char str1[200];
  char str2[200];
  char *str3 = "%*u Test %-*u Test %*.*u TEST %.*u";
  unsigned int val = 32;
  unsigned int val2 = 8899;
  unsigned int val3 = 919;
  unsigned int val4 = 32311;
  unsigned int ast = 2;
  unsigned int ast2 = 5;
  unsigned int ast3 = 4;
  unsigned int ast4 = 10;
  unsigned int ast5 = 7;

  ck_assert_int_eq(
      sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4),
      s21_sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5,
                  val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_d_u_5) {
  char str1[200];
  char str2[200];
  char *str3 = "%*lu Test %-*u Test %*.*u TEST %.*u";
  unsigned long int val = 32;
  unsigned int val2 = 8899;
  unsigned int val3 = 919;
  unsigned int val4 = 32311;
  unsigned int ast = 2;
  unsigned int ast2 = 5;
  unsigned int ast3 = 4;
  unsigned int ast4 = 10;
  unsigned int ast5 = 7;

  ck_assert_int_eq(
      sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4),
      s21_sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5,
                  val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_d_u_6) {
  char str1[100];
  char str2[100];
  char *str3 = "%hd Test %u Test %u %0*.*d";
  unsigned short int val = 012;
  unsigned int val2 = 017;
  unsigned int val3 = 07464;
  int val4 = 3456;
  int acc = -3;

  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, acc, acc, val4),
                   s21_sprintf(str2, str3, val, val2, val3, acc, acc, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_d_u_7) {
  char str1[200];
  char str2[200];
  char *str = "%0d Test %06d Test %05.7d TEST %0.7d Oof %0.d % ld, %5.ld";
  int var = -32;
  int var2 = 8899;
  int var3 = -91918;
  int var4 = -32311;
  int var5 = -8894;
  int var6 = 0;
  ck_assert_int_eq(
      sprintf(str1, str, var, var2, var3, var4, var5, var2, var6),
      s21_sprintf(str2, str, var, var2, var3, var4, var5, var2, var6));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_d_u_8) {
  char str1[200];
  char str2[200];
  char *str3 = "%*d Test %-*d Test %*.*d TEST %.*d , %05.0d";
  int val = 32;
  int val2 = 8899;
  int val3 = -919;
  int val4 = 32311;
  int ast = 2;
  int ast2 = 5;
  int ast3 = 4;
  int ast4 = 10;
  int ast5 = 7;
  ck_assert_int_eq(sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3,
                           ast5, val4, ast),
                   s21_sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4,
                               val3, ast5, val4, ast));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_s21_sprintf_d_u_9) {
  char str1[1024] = "";
  char str2[1024] = "";
  char *format = "Hello %+d %023d";
  int val = 75;
  sprintf(str1, format, val, val);
  s21_sprintf(str2, format, val, val);
  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *s21_sprintf_d_u_suite(void) {
  Suite *suite;
  TCase *tc_s21_sprintf_d_u;

  suite = suite_create("s21_sprintf_d_u");

  tc_s21_sprintf_d_u = tcase_create("S21_sprintf_d_u");

  tcase_add_test(tc_s21_sprintf_d_u, test_s21_sprintf_d_u_1);
  suite_add_tcase(suite, tc_s21_sprintf_d_u);

  tcase_add_test(tc_s21_sprintf_d_u, test_s21_sprintf_d_u_2);
  suite_add_tcase(suite, tc_s21_sprintf_d_u);

  tcase_add_test(tc_s21_sprintf_d_u, test_s21_sprintf_d_u_3);
  suite_add_tcase(suite, tc_s21_sprintf_d_u);

  tcase_add_test(tc_s21_sprintf_d_u, test_s21_sprintf_d_u_4);
  suite_add_tcase(suite, tc_s21_sprintf_d_u);

  tcase_add_test(tc_s21_sprintf_d_u, test_s21_sprintf_d_u_5);
  suite_add_tcase(suite, tc_s21_sprintf_d_u);

  tcase_add_test(tc_s21_sprintf_d_u, test_s21_sprintf_d_u_6);
  suite_add_tcase(suite, tc_s21_sprintf_d_u);

  tcase_add_test(tc_s21_sprintf_d_u, test_s21_sprintf_d_u_7);
  suite_add_tcase(suite, tc_s21_sprintf_d_u);

  tcase_add_test(tc_s21_sprintf_d_u, test_s21_sprintf_d_u_8);
  suite_add_tcase(suite, tc_s21_sprintf_d_u);

  tcase_add_test(tc_s21_sprintf_d_u, test_s21_sprintf_d_u_9);
  suite_add_tcase(suite, tc_s21_sprintf_d_u);

  return suite;
}