#include "s21_check_string.h"

START_TEST(test_s21_sprintf_1) {
  char *str = "there is no power a%s no knowle%dge";
  char arr1[1024] = {0};
  char arr2[1024] = {0};
  const char *var1 = "hello";
  int var2 = 4;

  s21_sprintf(arr1, str, var1, var2);
  sprintf(arr2, str, var1, var2);

  ck_assert_str_eq(arr1, arr2);
  ck_assert_pstr_eq(arr1, arr2);
}
END_TEST

// //позже проверить и допилить
// START_TEST(test_s21_sprintf_2) {
//   const char *format = "Our string :%% hello фтв ьк агылщаа%%щщзы";
//   char arr1[1024] = {0};
//   char arr2[1024] = {0};

//   sprintf(arr2, format);
//   s21_sprintf(arr1, format);

//   ck_assert_str_eq(arr1, arr2);
// }
// END_TEST

// START_TEST(test_s21_sprintf_3) {
//   const char *format = "Our% string :%% hello";
//   char arr1[1024] = {0};
//   char arr2[1024] = {0};

//   sprintf(arr2, format);
//   s21_sprintf(arr1, format);

//   ck_assert_str_eq(arr1, arr2);
// }
// END_TEST

START_TEST(test_s21_sprintf_4) {
  const char *format = "Our string :%ld";
  char arr1[1024] = {0};
  char arr2[1024] = {0};

  sprintf(arr2, format, 5);
  s21_sprintf(arr1, format, 5);

  ck_assert_str_eq(arr1, arr2);
}
END_TEST

START_TEST(test_s21_sprintf_5) {
  const char *format = "Our string :%10d";
  char arr1[1024] = {0};
  char arr2[1024] = {0};

  sprintf(arr2, format, 5);
  s21_sprintf(arr1, format, 5);

  ck_assert_str_eq(arr1, arr2);
}
END_TEST

START_TEST(test_s21_sprintf_6) {
  const char *format = "Our string :%10.d";
  const char *format1 = "Our string :%10.d";

  char arr1[1024] = {0};
  char arr2[1024] = {0};

  sprintf(arr2, format, 5);
  s21_sprintf(arr1, format1, 5);

  ck_assert_str_eq(arr1, arr2);
}
END_TEST
//
START_TEST(test_s21_sprintf_7) {
  const char *format = "Our string :%10.5d";
  const char *format1 = "Our string :%10.5d";
  char arr1[1024] = {0};
  char arr2[1024] = {0};

  sprintf(arr2, format, -10);
  s21_sprintf(arr1, format1, -10);

  ck_assert_str_eq(arr1, arr2);
}
END_TEST

START_TEST(test_s21_sprintf_8) {
  int accuracy = -5;
  const char *format = "Our string :%10.*d";
  const char *format1 = "Our string :%10.*d";
  char arr1[1024] = {0};
  char arr2[1024] = {0};

  sprintf(arr2, format, accuracy, -10);
  s21_sprintf(arr1, format1, accuracy, -10);

  ck_assert_str_eq(arr1, arr2);
}
END_TEST

START_TEST(test_s21_sprintf_9) {
  int width = 15;
  const char *format = "Our string :%*.d w%dhello";
  char arr1[1024] = {0};
  char arr2[1024] = {0};

  sprintf(arr2, format, width, -10, 10);
  s21_sprintf(arr1, format, width, -10, 10);

  ck_assert_str_eq(arr1, arr2);
}
END_TEST

Suite *s21_sprintf_suite(void) {
  Suite *suite;
  TCase *tc_s21_sprintf;

  suite = suite_create("s21_sprintf");

  tc_s21_sprintf = tcase_create("S21_sprintf");

  tcase_add_test(tc_s21_sprintf, test_s21_sprintf_1);
  suite_add_tcase(suite, tc_s21_sprintf);

  // tcase_add_test(tc_s21_sprintf, test_s21_sprintf_2);
  // suite_add_tcase(suite, tc_s21_sprintf);

  // tcase_add_test(tc_s21_sprintf, test_s21_sprintf_3);
  // suite_add_tcase(suite, tc_s21_sprintf);

  tcase_add_test(tc_s21_sprintf, test_s21_sprintf_4);
  suite_add_tcase(suite, tc_s21_sprintf);

  tcase_add_test(tc_s21_sprintf, test_s21_sprintf_5);
  suite_add_tcase(suite, tc_s21_sprintf);

  tcase_add_test(tc_s21_sprintf, test_s21_sprintf_6);
  suite_add_tcase(suite, tc_s21_sprintf);

  tcase_add_test(tc_s21_sprintf, test_s21_sprintf_7);
  suite_add_tcase(suite, tc_s21_sprintf);

  tcase_add_test(tc_s21_sprintf, test_s21_sprintf_8);
  suite_add_tcase(suite, tc_s21_sprintf);

  tcase_add_test(tc_s21_sprintf, test_s21_sprintf_9);
  suite_add_tcase(suite, tc_s21_sprintf);

  return suite;
}