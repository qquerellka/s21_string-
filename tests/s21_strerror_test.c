#include "s21_check_string.h"

START_TEST(test_s21_strerror_other_boundary) {
  // Тестирование ошибок за пределами допустимых значений
  int err_codes[] = {-1, 134};  // Ошибка ниже 0 и ошибка больше максимальной
  for (int i = 0; i < 2; i++) {
    char *s21_error_message = s21_strerror(err_codes[i]);
    char *expected_message = strerror(err_codes[i]);
    ck_assert_str_eq(s21_error_message, expected_message);
    free(s21_error_message);
  }
}
END_TEST

START_TEST(test_s21_strerror_other_edge_cases) {
  // Проверка корректности вывода для минимального и максимального значения
  // ошибок
  int err_codes[] = {0, 133};  // Минимальная и максимальная ошибка
  for (int i = 0; i < 2; i++) {
    char *s21_error_message = s21_strerror(err_codes[i]);
    char *expected_message = strerror(err_codes[i]);
    ck_assert_str_eq(s21_error_message, expected_message);
  }
}
END_TEST

// Тесты на корректность работы функции
START_TEST(test_s21_strerror_non_existent_error) {
  // Ошибка, которой нет в списке
  int err_code = 999;
  char *s21_error_message = s21_strerror(err_code);
  char *expected_message = strerror(err_code);
  ck_assert_str_eq(s21_error_message, expected_message);
  free(s21_error_message);
}
END_TEST

START_TEST(test_s21_strerror_memory_leak) {
  // Проверка на утечку памяти
  int err_code = 5;  // Ошибка "Input/output error"
  char *s21_error_message = s21_strerror(err_code);
  ck_assert_ptr_nonnull(s21_error_message);  // Проверяем, что сообщение не NULL
  free(s21_error_message);  // Проверяем, что память освобождается
}
END_TEST

START_TEST(test_s21_strerror_unsupported_error) {
  // Тестирование ошибок, которые выходят за допустимые диапазоны
  int err_code = -100;  // Недопустимая ошибка
  char *s21_error_message = s21_strerror(err_code);
  char *expected_message =
      "Unknown error -100";  // Формат для неизвестных ошибок
  ck_assert_str_eq(s21_error_message, expected_message);
  free(s21_error_message);
}
END_TEST

START_TEST(test_s21_strerror_other) {
  int err_codes[134];
  for (int i = 0; i < 134; i++) {
    err_codes[i] = i;
  }
  for (int i = 0; i < 134; i++) {
    char *s21_error_message = s21_strerror(err_codes[i]);
    char *expected_message = strerror(err_codes[i]);
    ck_assert_str_eq(s21_error_message, expected_message);
  }
}
END_TEST

Suite *s21_strerror_suite(void) {
  Suite *suite;
  TCase *tc_s21_strerror;

  suite = suite_create("s21_strerror");
  tc_s21_strerror = tcase_create("S21_strerror");

  tcase_add_test(tc_s21_strerror, test_s21_strerror_other);
  tcase_add_test(tc_s21_strerror, test_s21_strerror_other_boundary);
  tcase_add_test(tc_s21_strerror, test_s21_strerror_other_edge_cases);

  tcase_add_test(tc_s21_strerror, test_s21_strerror_non_existent_error);
  tcase_add_test(tc_s21_strerror, test_s21_strerror_memory_leak);
  tcase_add_test(tc_s21_strerror, test_s21_strerror_unsupported_error);

  suite_add_tcase(suite, tc_s21_strerror);
  return suite;
}