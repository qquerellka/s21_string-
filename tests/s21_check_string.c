#include "s21_check_string.h"

int main(void) {
  int number_failed = 0;
  SRunner *srunner = NULL;

  srunner = srunner_create(s21_memchr_suite());
  srunner_add_suite(srunner, s21_memcmp_suite());
  srunner_add_suite(srunner, s21_memcpy_suite());
  srunner_add_suite(srunner, s21_memset_suite());
  srunner_add_suite(srunner, s21_strchr_suite());
  srunner_add_suite(srunner, s21_strncat_suite());
  srunner_add_suite(srunner, s21_strlen_suite());
  srunner_add_suite(srunner, s21_strncmp_suite());
  srunner_add_suite(srunner, s21_strncpy_suite());
  srunner_add_suite(srunner, s21_strpbrk_suite());
  srunner_add_suite(srunner, s21_strrchr_suite());
  srunner_add_suite(srunner, s21_strstr_suite());
  srunner_add_suite(srunner, s21_strcspn_suite());
  srunner_add_suite(srunner, s21_strtok_suite());
  srunner_add_suite(srunner, s21_strerror_suite());
  srunner_add_suite(srunner, s21_to_upper_suite());
  srunner_add_suite(srunner, s21_to_lower_suite());
  srunner_add_suite(srunner, s21_insert_suite());

  srunner_add_suite(srunner, s21_sprintf_suite());

  srunner_add_suite(srunner, s21_sprintf_c_suite());
  srunner_add_suite(srunner, s21_sprintf_s_suite());
  srunner_add_suite(srunner, s21_sprintf_d_u_suite());
  srunner_add_suite(srunner, s21_sprintf_f_suite());

  srunner_run_all(srunner, CK_NORMAL);
  number_failed = srunner_ntests_failed(srunner);
  srunner_free(srunner);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}