#include "s21_check_string.h"

//  char *str = "Hello world";
//  int c = 'w';
START_TEST(test_s21_strchr_1) {
  char *str = "Hello world";
  int c = 'w';
  char *s21_strchr_result = NULL;
  char *strchr_result = NULL;

  s21_strchr_result = s21_strchr(str, c);
  strchr_result = strchr(str, c);

  ck_assert_ptr_eq(s21_strchr_result, strchr_result);
}
END_TEST

//  char *str = "Hello world";
//  int c = '\0';
START_TEST(test_s21_strchr_2) {
  char *str = "Hello world";
  int c = '\0';
  char *s21_strchr_result = NULL;
  char *strchr_result = NULL;

  s21_strchr_result = s21_strchr(str, c);
  strchr_result = strchr(str, c);

  ck_assert_ptr_eq(s21_strchr_result, strchr_result);
}
END_TEST

//  char *str = "Hello world";
//  int c = '[';
START_TEST(test_s21_strchr_3) {
  char *str = "Hello world";
  int c = '[';
  char *s21_strchr_result = NULL;
  char *strchr_result = NULL;

  s21_strchr_result = s21_strchr(str, c);
  strchr_result = strchr(str, c);

  ck_assert_ptr_eq(s21_strchr_result, strchr_result);
}
END_TEST

//  char *str = "bytecode\0why";
//  int c = '\0';
START_TEST(test_s21_strchr_4) {
  char *str = "bytecode\0why";
  int c = '\0';
  char *s21_strchr_result = NULL;
  char *strchr_result = NULL;

  s21_strchr_result = s21_strchr(str, c);
  strchr_result = strchr(str, c);

  ck_assert_ptr_eq(s21_strchr_result, strchr_result);
}
END_TEST

//  char *str = "there is no power as no knowledge";
//  int c = '[';
START_TEST(test_s21_strchr_5) {
  char *str = "there is no power as no knowledge";
  int c = '[';
  char *s21_strchr_result = NULL;
  char *strchr_result = NULL;

  s21_strchr_result = s21_strchr(str, c);
  strchr_result = strchr(str, c);

  ck_assert_ptr_eq(s21_strchr_result, strchr_result);
}
END_TEST

// Совпадение первого символа строки
START_TEST(test_s21_strchr_6) {
  char *str = "Hello world";
  int c = 'H';
  char *s21_strchr_result = NULL;
  char *strchr_result = NULL;

  s21_strchr_result = s21_strchr(str, c);
  strchr_result = strchr(str, c);

  ck_assert_ptr_eq(s21_strchr_result, strchr_result);
}
END_TEST

// Совпадение последнего символа строки
START_TEST(test_s21_strchr_7) {
  char *str = "Hello world";
  int c = 'd';
  char *s21_strchr_result = NULL;
  char *strchr_result = NULL;

  s21_strchr_result = s21_strchr(str, c);
  strchr_result = strchr(str, c);

  ck_assert_ptr_eq(s21_strchr_result, strchr_result);
}
END_TEST

// Строка содержит только символ для поиска
START_TEST(test_s21_strchr_8) {
  char *str = "a";
  int c = 'a';
  char *s21_strchr_result = NULL;
  char *strchr_result = NULL;

  s21_strchr_result = s21_strchr(str, c);
  strchr_result = strchr(str, c);

  ck_assert_ptr_eq(s21_strchr_result, strchr_result);
}
END_TEST

// Пустая строка как входные данные
START_TEST(test_s21_strchr_9) {
  char *str = "";
  int c = 'a';
  char *s21_strchr_result = NULL;
  char *strchr_result = NULL;

  s21_strchr_result = s21_strchr(str, c);
  strchr_result = strchr(str, c);

  ck_assert_ptr_eq(s21_strchr_result, strchr_result);
}
END_TEST

// Поиск символа, превышающего диапазон char
START_TEST(test_s21_strchr_10) {
  char *str = "Hello world";
  int c = 256;  // Символ за пределами диапазона char
  char *s21_strchr_result = NULL;
  char *strchr_result = NULL;

  s21_strchr_result = s21_strchr(str, c);
  strchr_result = strchr(str, c);

  ck_assert_ptr_eq(s21_strchr_result, strchr_result);
}
END_TEST

// Нулевые указатели
START_TEST(test_s21_strchr_11) {
  char *str = NULL;
  int c = 'a';

  char *s21_strchr_result = NULL;
  char *strchr_result = NULL;

  if (str) {  // Проверка на NULL, чтобы избежать сегментации
    s21_strchr_result = s21_strchr(str, c);
    strchr_result = strchr(str, c);
    ck_assert_ptr_eq(s21_strchr_result, strchr_result);
  }
}
END_TEST

// Повторяющиеся символы
START_TEST(test_s21_strchr_12) {
  char *str = "aaaabaaa";
  int c = 'b';
  char *s21_strchr_result = NULL;
  char *strchr_result = NULL;

  s21_strchr_result = s21_strchr(str, c);
  strchr_result = strchr(str, c);

  ck_assert_ptr_eq(s21_strchr_result, strchr_result);
}
END_TEST

//

// коды вне символов строки дают сегу
Suite *s21_strchr_suite(void) {
  Suite *suite;
  TCase *tc_s21_strchr;

  suite = suite_create("s21_strchr");

  tc_s21_strchr = tcase_create("S21_strchr");

  tcase_add_test(tc_s21_strchr, test_s21_strchr_1);
  suite_add_tcase(suite, tc_s21_strchr);

  tcase_add_test(tc_s21_strchr, test_s21_strchr_2);
  suite_add_tcase(suite, tc_s21_strchr);

  tcase_add_test(tc_s21_strchr, test_s21_strchr_3);
  suite_add_tcase(suite, tc_s21_strchr);

  tcase_add_test(tc_s21_strchr, test_s21_strchr_4);
  suite_add_tcase(suite, tc_s21_strchr);

  tcase_add_test(tc_s21_strchr, test_s21_strchr_5);
  suite_add_tcase(suite, tc_s21_strchr);

  tcase_add_test(tc_s21_strchr, test_s21_strchr_6);
  suite_add_tcase(suite, tc_s21_strchr);

  tcase_add_test(tc_s21_strchr, test_s21_strchr_7);
  suite_add_tcase(suite, tc_s21_strchr);

  tcase_add_test(tc_s21_strchr, test_s21_strchr_8);
  suite_add_tcase(suite, tc_s21_strchr);

  tcase_add_test(tc_s21_strchr, test_s21_strchr_9);
  suite_add_tcase(suite, tc_s21_strchr);

  tcase_add_test(tc_s21_strchr, test_s21_strchr_10);
  suite_add_tcase(suite, tc_s21_strchr);

  tcase_add_test(tc_s21_strchr, test_s21_strchr_11);
  suite_add_tcase(suite, tc_s21_strchr);

  tcase_add_test(tc_s21_strchr, test_s21_strchr_12);
  suite_add_tcase(suite, tc_s21_strchr);

  return suite;
}