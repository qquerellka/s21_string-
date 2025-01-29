#include "s21_check_string.h"

void initialize_string(char *dest, const char *dest_filler, int filler_size) {
  strncpy(dest, dest_filler, filler_size);
}

//  char* dest_filler = "there is no power as no knowledge";
//  int dest_size = 50;
//  char dest_s21[dest_size];
//  char dest[dest_size];
//  char* src = "KHA..An!!11";
//  size_t n = 10;
START_TEST(test_s21_strncat_1) {
  char *dest_filler = "there is no power as no knowledge";
  int dest_size = 50;
  char dest_s21[dest_size];
  char dest[dest_size];
  char *src = "KHA..An!!11";
  size_t n = 10;
  char *s21_strncat_result = NULL;
  char *strncat_result = NULL;
  initialize_string(dest_s21, dest_filler, dest_size);
  initialize_string(dest, dest_filler, dest_size);

  s21_strncat_result = s21_strncat(dest_s21, src, n);
  strncat_result = strncat(dest, src, n);

  ck_assert_str_eq(s21_strncat_result, strncat_result);
}
END_TEST

//  char* dest_filler = "there is no power as no knowledge";
//  int dest_size = 50;
//  char dest_s21[dest_size];
//  char dest[dest_size];
//  char* src = "Hello";
//  size_t n = 0;
START_TEST(test_s21_strncat_2) {
  char *dest_filler = "there is no power as no knowledge";
  int dest_size = 50;
  char dest_s21[dest_size];
  char dest[dest_size];
  char *src = "Hello";
  size_t n = 0;
  char *s21_strncat_result = NULL;
  char *strncat_result = NULL;
  initialize_string(dest_s21, dest_filler, dest_size);
  initialize_string(dest, dest_filler, dest_size);

  s21_strncat_result = s21_strncat(dest_s21, src, n);
  strncat_result = strncat(dest, src, n);

  ck_assert_str_eq(s21_strncat_result, strncat_result);
}
END_TEST

//  char* dest_filler = "there is no power as no knowledge";
//  int dest_size = 50;
//  char dest_s21[dest_size];
//  char dest[dest_size];
//  char* src = "Hello";
//  size_t n = 10;
START_TEST(test_s21_strncat_3) {
  char *dest_filler = "there is no power as no knowledge";
  int dest_size = 50;
  char dest_s21[dest_size];
  char dest[dest_size];
  char *src = "Hello";
  size_t n = 10;
  char *s21_strncat_result = NULL;
  char *strncat_result = NULL;
  initialize_string(dest_s21, dest_filler, dest_size);
  initialize_string(dest, dest_filler, dest_size);

  s21_strncat_result = s21_strncat(dest_s21, src, n);
  strncat_result = strncat(dest, src, n);

  ck_assert_str_eq(s21_strncat_result, strncat_result);
}
END_TEST

//  char* dest_filler = "Hello world!";;
//  int dest_size = 50;
//  char dest_s21[dest_size];
//  char dest[dest_size];
//  char* src = "KHA..An!!11";
//  size_t n = 20;
START_TEST(test_s21_strncat_4) {
  char *dest_filler = "Hello world!";
  ;
  int dest_size = 50;
  char dest_s21[dest_size];
  char dest[dest_size];
  char *src = "KHA..An!!11";
  size_t n = 20;
  char *s21_strncat_result = NULL;
  char *strncat_result = NULL;
  initialize_string(dest_s21, dest_filler, dest_size);
  initialize_string(dest, dest_filler, dest_size);

  s21_strncat_result = s21_strncat(dest_s21, src, n);
  strncat_result = strncat(dest, src, n);

  ck_assert_str_eq(s21_strncat_result, strncat_result);
}
END_TEST

// Пустая строка dest
START_TEST(test_s21_strncat_5) {
  int dest_size = 50;
  char dest_s21[dest_size];
  char dest[dest_size];
  char *src = "Hello, world!";
  size_t n = 5;
  char *s21_strncat_result = NULL;
  char *strncat_result = NULL;

  initialize_string(dest_s21, "", dest_size);
  initialize_string(dest, "", dest_size);

  s21_strncat_result = s21_strncat(dest_s21, src, n);
  strncat_result = strncat(dest, src, n);

  ck_assert_str_eq(s21_strncat_result, strncat_result);
}
END_TEST

// Пустая строка src
START_TEST(test_s21_strncat_6) {
  char *dest_filler = "Pre-filled string";
  int dest_size = 50;
  char dest_s21[dest_size];
  char dest[dest_size];
  char *src = "";
  size_t n = 5;
  char *s21_strncat_result = NULL;
  char *strncat_result = NULL;

  initialize_string(dest_s21, dest_filler, dest_size);
  initialize_string(dest, dest_filler, dest_size);

  s21_strncat_result = s21_strncat(dest_s21, src, n);
  strncat_result = strncat(dest, src, n);

  ck_assert_str_eq(s21_strncat_result, strncat_result);
}
END_TEST

// n > strlen(src)
START_TEST(test_s21_strncat_7) {
  char *dest_filler = "Initial ";
  int dest_size = 50;
  char dest_s21[dest_size];
  char dest[dest_size];
  char *src = "Data";
  size_t n = 10;
  char *s21_strncat_result = NULL;
  char *strncat_result = NULL;

  initialize_string(dest_s21, dest_filler, dest_size);
  initialize_string(dest, dest_filler, dest_size);

  s21_strncat_result = s21_strncat(dest_s21, src, n);
  strncat_result = strncat(dest, src, n);

  ck_assert_str_eq(s21_strncat_result, strncat_result);
}
END_TEST

// n == 0
START_TEST(test_s21_strncat_8) {
  char *dest_filler = "Buffer data ";
  int dest_size = 50;
  char dest_s21[dest_size];
  char dest[dest_size];
  char *src = "Ignored";
  size_t n = 0;
  char *s21_strncat_result = NULL;
  char *strncat_result = NULL;

  initialize_string(dest_s21, dest_filler, dest_size);
  initialize_string(dest, dest_filler, dest_size);

  s21_strncat_result = s21_strncat(dest_s21, src, n);
  strncat_result = strncat(dest, src, n);

  ck_assert_str_eq(s21_strncat_result, strncat_result);
}
END_TEST

// Длинный dest близко к границе буфера
START_TEST(test_s21_strncat_9) {
  int dest_size = 50;
  char dest_s21[dest_size];
  char dest[dest_size];
  char *src = "Data";
  size_t n = 4;
  char *s21_strncat_result = NULL;
  char *strncat_result = NULL;

  // Инициализируем строку dest данными длиной в 45 символов
  s21_memset(dest_s21, 'A', 45);
  dest_s21[45] = '\0';
  s21_strncpy(dest, dest_s21, dest_size);

  s21_strncat_result = s21_strncat(dest_s21, src, n);
  strncat_result = strncat(dest, src, n);
  int result = strcmp(s21_strncat_result, strncat_result);
  printf("%d", result);
  ck_assert_str_eq(s21_strncat_result, strncat_result);
}
END_TEST

// Тест на добавление строки
START_TEST(test_s21_strncat_10) {
  char dest1[50] = "Hello";
  char dest2[50] = "Hello";
  const char *src = "World";
  size_t n = 3;
  strncat(dest1, src, n);
  s21_strncat(dest2, src, n);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

// Тест с n больше длины src
START_TEST(test_s21_strncat_11) {
  char dest1[50] = "Hello";
  char dest2[50] = "Hello";
  const char *src = "World";
  size_t n = 10;
  strncat(dest1, src, n);
  s21_strncat(dest2, src, n);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

// Тест на добавление одной строки в конец другой
START_TEST(test_s21_strncat_12) {
  char dest1[50] = "Hello ";
  char dest2[50] = "Hello ";
  const char *src = "World!";
  size_t n = 6;
  strncat(dest1, src, n);
  s21_strncat(dest2, src, n);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_s21_strncat_13) {
  char dest1[30] = "Hello, world!";
  char dest2[30] = "Hello, world!";
  char src[] = "Hello, world!";
  s21_size_t n = 1;
  strncat(dest1, src, n);
  s21_strncat(dest2, src, n);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_s21_strncat_14) {
  char dest1[30] = "Hello, world!";
  char dest2[30] = "Hello, world!";
  char src[] = "\0";
  s21_size_t n = 1;
  strncat(dest1, src, n);
  s21_strncat(dest2, src, n);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_s21_strncat_15) {
  char dest1[30] = "Hello, world!";
  char dest2[30] = "Hello, world!";
  char src[] = "\n\0\\d\f\\g\7";
  s21_size_t n = 3;
  strncat(dest1, src, n);
  s21_strncat(dest2, src, n);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_s21_strncat_16) {
  char dest1[100] = "Hello, world!";
  char dest2[100] = "Hello, world!";
  char src[] =
      "My name is Polina. I hate this, maybe I'm not supposed for this.";
  s21_size_t n = 6;
  strncat(dest1, src, n);
  s21_strncat(dest2, src, n);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_s21_strncat_17) {
  char dest1[30] = "";
  char dest2[30] = "";
  char src[] = "Hello, world!";
  s21_size_t n = 3;
  strncat(dest1, src, n);
  s21_strncat(dest2, src, n);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_s21_strncat_18) {
  char dest1[100] = "Hello, world!";
  char dest2[100] = "Hello, world!";
  char src[] = "My name is Polina.";
  s21_size_t n = 2;
  strncat(dest1, src, n);
  s21_strncat(dest2, src, n);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_s21_strncat_19) {
  char dest1[100] = "";
  char dest2[100] = "";
  char src[] = "";
  s21_size_t n = 10;
  strncat(dest1, src, n);
  s21_strncat(dest2, src, n);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_s21_strncat_20) {
  char dest1[100] = "Hello\0, world!";
  char dest2[100] = "Hello\0, world!";
  char src[] = "My name is\0 Polina.";
  s21_size_t n = 15;
  strncat(dest1, src, n);
  s21_strncat(dest2, src, n);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_s21_strncat_21) {
  char dest1[100] = "Hello, world!";
  char dest2[100] = "Hello, world!";
  char src[] = "";
  s21_size_t n = 2;
  strncat(dest1, src, n);
  s21_strncat(dest2, src, n);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

Suite *s21_strncat_suite(void) {
  Suite *suite;
  TCase *tc_s21_strncat;
  suite = suite_create("s21_strncat");
  tc_s21_strncat = tcase_create("S21_strncat");
  tcase_add_test(tc_s21_strncat, test_s21_strncat_1);
  suite_add_tcase(suite, tc_s21_strncat);
  tcase_add_test(tc_s21_strncat, test_s21_strncat_2);
  suite_add_tcase(suite, tc_s21_strncat);
  tcase_add_test(tc_s21_strncat, test_s21_strncat_3);
  suite_add_tcase(suite, tc_s21_strncat);
  tcase_add_test(tc_s21_strncat, test_s21_strncat_4);
  suite_add_tcase(suite, tc_s21_strncat);
  tcase_add_test(tc_s21_strncat, test_s21_strncat_5);
  suite_add_tcase(suite, tc_s21_strncat);
  tcase_add_test(tc_s21_strncat, test_s21_strncat_6);
  suite_add_tcase(suite, tc_s21_strncat);
  tcase_add_test(tc_s21_strncat, test_s21_strncat_7);
  suite_add_tcase(suite, tc_s21_strncat);
  tcase_add_test(tc_s21_strncat, test_s21_strncat_8);
  suite_add_tcase(suite, tc_s21_strncat);
  tcase_add_test(tc_s21_strncat, test_s21_strncat_9);
  suite_add_tcase(suite, tc_s21_strncat);
  tcase_add_test(tc_s21_strncat, test_s21_strncat_10);
  suite_add_tcase(suite, tc_s21_strncat);
  tcase_add_test(tc_s21_strncat, test_s21_strncat_11);
  suite_add_tcase(suite, tc_s21_strncat);
  tcase_add_test(tc_s21_strncat, test_s21_strncat_12);
  suite_add_tcase(suite, tc_s21_strncat);
  tcase_add_test(tc_s21_strncat, test_s21_strncat_13);
  suite_add_tcase(suite, tc_s21_strncat);
  tcase_add_test(tc_s21_strncat, test_s21_strncat_14);
  suite_add_tcase(suite, tc_s21_strncat);
  tcase_add_test(tc_s21_strncat, test_s21_strncat_15);
  suite_add_tcase(suite, tc_s21_strncat);
  tcase_add_test(tc_s21_strncat, test_s21_strncat_16);
  suite_add_tcase(suite, tc_s21_strncat);
  tcase_add_test(tc_s21_strncat, test_s21_strncat_17);
  suite_add_tcase(suite, tc_s21_strncat);
  tcase_add_test(tc_s21_strncat, test_s21_strncat_18);
  suite_add_tcase(suite, tc_s21_strncat);
  tcase_add_test(tc_s21_strncat, test_s21_strncat_19);
  suite_add_tcase(suite, tc_s21_strncat);
  tcase_add_test(tc_s21_strncat, test_s21_strncat_20);
  suite_add_tcase(suite, tc_s21_strncat);
  tcase_add_test(tc_s21_strncat, test_s21_strncat_21);
  suite_add_tcase(suite, tc_s21_strncat);
  return suite;
}