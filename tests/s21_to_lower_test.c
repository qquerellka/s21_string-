#include <stdlib.h>

#include "s21_check_string.h"

// Проверка преобразования обычной строки
START_TEST(test_s21_to_lower_regular) {
  const char *str = "HELLO WORLD";
  char *result = (char *)s21_to_lower(str);

  ck_assert_str_eq(result, "hello world");

  free(result);
}
END_TEST

// Проверка строки, содержащей уже строчные буквы
START_TEST(test_s21_to_lower_lowercase) {
  const char *str = "hello world";
  char *result = (char *)s21_to_lower(str);

  ck_assert_str_eq(result, "hello world");

  free(result);
}
END_TEST

// Проверка пустой строки
START_TEST(test_s21_to_lower_empty) {
  const char *str = "";
  char *result = (char *)s21_to_lower(str);

  ck_assert_str_eq(result, "");

  free(result);
}
END_TEST

// Проверка строки с числами и специальными символами
START_TEST(test_s21_to_lower_special_chars) {
  const char *str = "12345!@#$%";
  char *result = (char *)s21_to_lower(str);

  ck_assert_str_eq(result, "12345!@#$%");

  free(result);
}
END_TEST

// Проверка строки с сочетанием символов разных регистров
START_TEST(test_s21_to_lower_mixed_case) {
  const char *str = "HeLLo WoRLd";
  char *result = (char *)s21_to_lower(str);

  ck_assert_str_eq(result, "hello world");

  free(result);
}
END_TEST

// Проверка строки, содержащей только заглавные буквы
START_TEST(test_s21_to_lower_uppercase_only) {
  const char *str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char *result = (char *)s21_to_lower(str);

  ck_assert_str_eq(result, "abcdefghijklmnopqrstuvwxyz");

  free(result);
}
END_TEST

//

Suite *s21_to_lower_suite(void) {
  Suite *suite;
  TCase *tc_s21_to_lower;

  suite = suite_create("s21_to_lower");
  tc_s21_to_lower = tcase_create("Core");

  // Добавляем тесты в тестовый случай
  tcase_add_test(tc_s21_to_lower, test_s21_to_lower_regular);
  tcase_add_test(tc_s21_to_lower, test_s21_to_lower_lowercase);
  tcase_add_test(tc_s21_to_lower, test_s21_to_lower_empty);
  tcase_add_test(tc_s21_to_lower, test_s21_to_lower_special_chars);
  tcase_add_test(tc_s21_to_lower, test_s21_to_lower_mixed_case);
  tcase_add_test(tc_s21_to_lower, test_s21_to_lower_uppercase_only);

  suite_add_tcase(suite, tc_s21_to_lower);

  return suite;
}
