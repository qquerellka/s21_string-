#include "s21_check_string.h"

// исходная строка
//  char *str = "there is no power as no knowledge";
// строка для поиска символов которых нет в строке
//  char *tk = ",.!?";
START_TEST(test_s21_strcspn_1) {
  char *str = "there is no power as no knowledge";
  char *tk = ",.!?";
  size_t s21_strcspn_result = 0;
  size_t strcspn_result = 0;

  s21_strcspn_result = s21_strcspn(str, tk);
  strcspn_result = strcspn(str, tk);

  ck_assert(s21_strcspn_result == strcspn_result);
}
END_TEST

// исходная строка
//  char *str = "there is no power as no knowledge";
// строка для поиска символов с символом с которого начинается строка
//  char *tk = "t,.!?";
START_TEST(test_s21_strcspn_2) {
  char *str = "there is no power as no knowledge";
  char *tk = "t,.!?";
  size_t s21_strcspn_result = 0;
  size_t strcspn_result = 0;

  s21_strcspn_result = s21_strcspn(str, tk);
  strcspn_result = strcspn(str, tk);

  ck_assert(s21_strcspn_result == strcspn_result);
}
END_TEST

// исходная строка
//  char *str = "there is no power as no knowledge";
// строка для поиска символов с существующим символом внутри строки
//  char *tk = ",.o!?";
START_TEST(test_s21_strcspn_3) {
  char *str = "there is no power as no knowledge";
  char *tk = ",.o!?";
  size_t s21_strcspn_result = 0;
  size_t strcspn_result = 0;

  s21_strcspn_result = s21_strcspn(str, tk);
  strcspn_result = strcspn(str, tk);

  ck_assert(s21_strcspn_result == strcspn_result);
}
END_TEST

// исходная строка
//  char *str = "there is no power as no knowledge";
// строка для поиска символов с существующим символом внутри строки
//  char *tk = ",.t!?o"
START_TEST(test_s21_strcspn_4) {
  char *str = "there is no power as no knowledge";
  char *tk = ",.t!?o";
  size_t s21_strcspn_result = 0;
  size_t strcspn_result = 0;

  s21_strcspn_result = s21_strcspn(str, tk);
  strcspn_result = strcspn(str, tk);

  ck_assert(s21_strcspn_result == strcspn_result);
}
END_TEST

// исходная строка
//  char *str = "there is no power as no knowledge";
// пустая строка символов
//  char *tk = ""
START_TEST(test_s21_strcspn_5) {
  char *str = "there is no power as no knowledge";
  char *tk = "";
  size_t s21_strcspn_result = 0;
  size_t strcspn_result = 0;

  s21_strcspn_result = s21_strcspn(str, tk);
  strcspn_result = strcspn(str, tk);

  ck_assert(s21_strcspn_result == strcspn_result);
}
END_TEST

// пустая исходная строка
//  char *str = "";
// строка для поиска символов с существующим символом внутри строки
//  char *tk = ",.t!?o"
START_TEST(test_s21_strcspn_6) {
  char *str = "";
  char *tk = ",.t!?o";
  size_t s21_strcspn_result = 0;
  size_t strcspn_result = 0;

  s21_strcspn_result = s21_strcspn(str, tk);
  strcspn_result = strcspn(str, tk);

  ck_assert(s21_strcspn_result == strcspn_result);
}
END_TEST

// пустая исходная строка
//  char *str = "";
// пустая строка символов
//  char *tk = ""
START_TEST(test_s21_strcspn_7) {
  char *str = "";
  char *tk = "";
  size_t s21_strcspn_result = 0;
  size_t strcspn_result = 0;

  s21_strcspn_result = s21_strcspn(str, tk);
  strcspn_result = strcspn(str, tk);

  ck_assert(s21_strcspn_result == strcspn_result);
}
END_TEST

// Исходная строка из одного символа, который совпадает с первым символом строки
// поиска
START_TEST(test_s21_strcspn_8) {
  char *str = "a";
  char *tk = "a";
  size_t s21_strcspn_result = 0;
  size_t strcspn_result = 0;

  s21_strcspn_result = s21_strcspn(str, tk);
  strcspn_result = strcspn(str, tk);

  ck_assert(s21_strcspn_result == strcspn_result);
}
END_TEST

// Совпадение на последнем символе строки
START_TEST(test_s21_strcspn_9) {
  char *str = "abcdefghij";
  char *tk = "j";
  size_t s21_strcspn_result = 0;
  size_t strcspn_result = 0;

  s21_strcspn_result = s21_strcspn(str, tk);
  strcspn_result = strcspn(str, tk);

  ck_assert(s21_strcspn_result == strcspn_result);
}
END_TEST

// Все символы строки совпадают
START_TEST(test_s21_strcspn_10) {
  char *str = "abcd";
  char *tk = "abcd";
  size_t s21_strcspn_result = 0;
  size_t strcspn_result = 0;

  s21_strcspn_result = s21_strcspn(str, tk);
  strcspn_result = strcspn(str, tk);

  ck_assert(s21_strcspn_result == strcspn_result);
}
END_TEST

// Нет совпадений
START_TEST(test_s21_strcspn_11) {
  char *str = "abcdef";
  char *tk = "123456";
  size_t s21_strcspn_result = 0;
  size_t strcspn_result = 0;

  s21_strcspn_result = s21_strcspn(str, tk);
  strcspn_result = strcspn(str, tk);

  ck_assert(s21_strcspn_result == strcspn_result);
}
END_TEST

// Большая строка с повторяющимися символами, совпадение в середине
START_TEST(test_s21_strcspn_12) {
  char *str = "aaaaaaaaaaaaaaaaaaaaaaaaaabbbbb";
  char *tk = "b";
  size_t s21_strcspn_result = 0;
  size_t strcspn_result = 0;

  s21_strcspn_result = s21_strcspn(str, tk);
  strcspn_result = strcspn(str, tk);

  ck_assert(s21_strcspn_result == strcspn_result);
}
END_TEST

// Пустая строка поиска, строка ввода непустая
START_TEST(test_s21_strcspn_13) {
  char *str = "abc";
  char *tk = "";
  size_t s21_strcspn_result = 0;
  size_t strcspn_result = 0;

  s21_strcspn_result = s21_strcspn(str, tk);
  strcspn_result = strcspn(str, tk);

  ck_assert(s21_strcspn_result == strcspn_result);
}
END_TEST

// Пустая строка ввода, непустая строка поиска
START_TEST(test_s21_strcspn_14) {
  char *str = "";
  char *tk = "abc";
  size_t s21_strcspn_result = 0;
  size_t strcspn_result = 0;

  s21_strcspn_result = s21_strcspn(str, tk);
  strcspn_result = strcspn(str, tk);

  ck_assert(s21_strcspn_result == strcspn_result);
}
END_TEST

// Обе строки пустые
START_TEST(test_s21_strcspn_15) {
  char *str = "";
  char *tk = "";
  size_t s21_strcspn_result = 0;
  size_t strcspn_result = 0;

  s21_strcspn_result = s21_strcspn(str, tk);
  strcspn_result = strcspn(str, tk);

  ck_assert(s21_strcspn_result == strcspn_result);
}
END_TEST

// const string or null ptr => sega
Suite *s21_strcspn_suite(void) {
  Suite *suite;
  TCase *tc_s21_strcspn;

  suite = suite_create("s21_strcspn");

  tc_s21_strcspn = tcase_create("S21_strcspn");

  tcase_add_test(tc_s21_strcspn, test_s21_strcspn_1);
  suite_add_tcase(suite, tc_s21_strcspn);

  tcase_add_test(tc_s21_strcspn, test_s21_strcspn_2);
  suite_add_tcase(suite, tc_s21_strcspn);

  tcase_add_test(tc_s21_strcspn, test_s21_strcspn_3);
  suite_add_tcase(suite, tc_s21_strcspn);

  tcase_add_test(tc_s21_strcspn, test_s21_strcspn_4);
  suite_add_tcase(suite, tc_s21_strcspn);

  tcase_add_test(tc_s21_strcspn, test_s21_strcspn_5);
  suite_add_tcase(suite, tc_s21_strcspn);

  tcase_add_test(tc_s21_strcspn, test_s21_strcspn_6);
  suite_add_tcase(suite, tc_s21_strcspn);

  tcase_add_test(tc_s21_strcspn, test_s21_strcspn_7);
  suite_add_tcase(suite, tc_s21_strcspn);

  tcase_add_test(tc_s21_strcspn, test_s21_strcspn_8);
  suite_add_tcase(suite, tc_s21_strcspn);

  tcase_add_test(tc_s21_strcspn, test_s21_strcspn_9);
  suite_add_tcase(suite, tc_s21_strcspn);

  tcase_add_test(tc_s21_strcspn, test_s21_strcspn_10);
  suite_add_tcase(suite, tc_s21_strcspn);

  tcase_add_test(tc_s21_strcspn, test_s21_strcspn_11);
  suite_add_tcase(suite, tc_s21_strcspn);

  tcase_add_test(tc_s21_strcspn, test_s21_strcspn_12);
  suite_add_tcase(suite, tc_s21_strcspn);

  tcase_add_test(tc_s21_strcspn, test_s21_strcspn_13);
  suite_add_tcase(suite, tc_s21_strcspn);

  tcase_add_test(tc_s21_strcspn, test_s21_strcspn_14);
  suite_add_tcase(suite, tc_s21_strcspn);

  tcase_add_test(tc_s21_strcspn, test_s21_strcspn_15);
  suite_add_tcase(suite, tc_s21_strcspn);

  return suite;
}