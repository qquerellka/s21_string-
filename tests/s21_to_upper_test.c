#include "s21_check_string.h"

// Проверка преобразования обычной строки
START_TEST(test_s21_to_upper_regular) {
  const char *str = "hello world";
  char *result = (char *)s21_to_upper(str);

  ck_assert_str_eq(result, "HELLO WORLD");

  free(result);
}
END_TEST

// Проверка строки, содержащей уже прописные буквы
START_TEST(test_s21_to_upper_uppercase) {
  const char *str = "HELLO WORLD";
  char *result = (char *)s21_to_upper(str);

  ck_assert_str_eq(result, "HELLO WORLD");

  free(result);
}
END_TEST

// Проверка пустой строки
START_TEST(test_s21_to_upper_empty) {
  const char *str = "";
  char *result = (char *)s21_to_upper(str);

  ck_assert_str_eq(result, "");

  free(result);
}
END_TEST

// Проверка строки с числами и специальными символами
START_TEST(test_s21_to_upper_special_chars) {
  const char *str = "12345!@#$%";
  char *result = (char *)s21_to_upper(str);

  ck_assert_str_eq(result, "12345!@#$%");

  free(result);
}
END_TEST

// Проверка строки с сочетанием символов разных регистра
START_TEST(test_s21_to_upper_mixed_case) {
  const char *str = "HeLLo WoRLd";
  char *result = (char *)s21_to_upper(str);

  ck_assert_str_eq(result, "HELLO WORLD");

  free(result);
}
END_TEST

// Проверка строки, содержащей только символы нижнего регистра
START_TEST(test_s21_to_upper_lowercase_only) {
  const char *str = "abcdefghijklmnopqrstuvwxyz";
  char *result = (char *)s21_to_upper(str);

  ck_assert_str_eq(result, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");

  free(result);
}
END_TEST

// Проверка строки, содержащей нулевой указатель
START_TEST(test_s21_to_upper_null) {
  const char *str = NULL;
  char *result = (char *)s21_to_upper(str);

  ck_assert_ptr_null(result);
}
END_TEST

// Проверка строки с одним символом в нижнем регистре
START_TEST(test_s21_to_upper_single_lowercase) {
  const char *str = "a";
  char *result = (char *)s21_to_upper(str);

  ck_assert_str_eq(result, "A");

  free(result);
}
END_TEST

// Проверка строки с одним символом в верхнем регистре
START_TEST(test_s21_to_upper_single_uppercase) {
  const char *str = "A";
  char *result = (char *)s21_to_upper(str);

  ck_assert_str_eq(result, "A");

  free(result);
}
END_TEST

// Проверка строки с нулевым символом внутри
START_TEST(test_s21_to_upper_with_null_char) {
  const char *str = "abc\0def";
  char *result = (char *)s21_to_upper(str);

  ck_assert_str_eq(result, "ABC");

  free(result);
}
END_TEST

Suite *s21_to_upper_suite(void) {
  Suite *suite;
  TCase *tc_s21_to_upper;

  suite = suite_create("s21_to_upper");
  tc_s21_to_upper = tcase_create("S21_to_upper");

  tcase_add_test(tc_s21_to_upper, test_s21_to_upper_regular);
  tcase_add_test(tc_s21_to_upper, test_s21_to_upper_uppercase);
  tcase_add_test(tc_s21_to_upper, test_s21_to_upper_empty);
  tcase_add_test(tc_s21_to_upper, test_s21_to_upper_special_chars);
  tcase_add_test(tc_s21_to_upper, test_s21_to_upper_mixed_case);
  tcase_add_test(tc_s21_to_upper, test_s21_to_upper_lowercase_only);
  tcase_add_test(tc_s21_to_upper, test_s21_to_upper_null);
  tcase_add_test(tc_s21_to_upper, test_s21_to_upper_single_lowercase);
  tcase_add_test(tc_s21_to_upper, test_s21_to_upper_single_uppercase);
  tcase_add_test(tc_s21_to_upper, test_s21_to_upper_with_null_char);

  suite_add_tcase(suite, tc_s21_to_upper);
  return suite;
}
