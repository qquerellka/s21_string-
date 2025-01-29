#include "s21_check_string.h"

START_TEST(test_s21_strtok_1) {
  char string_s21[] = "AAASEGSEGESEGESEGDDDDDSS";
  char string[] = "AAASEGSEGESEGESEGDDDDDSS";
  char *tok = S21_NULL;
  char *tok_s21 = S21_NULL;

  tok_s21 = s21_strtok(string_s21, "S");
  tok = strtok(string, "S");

  ck_assert_str_eq(tok_s21, tok);
  // free(tok_s21);
}
END_TEST

START_TEST(test_s21_strtok_2) {
  char string_s21[] = "AAASEGSEGESEGESEGDDDDDSS";
  char string[] = "AAASEGSEGESEGESEGDDDDDSS";
  char *tok = S21_NULL;
  char *tok_s21 = S21_NULL;

  tok_s21 = s21_strtok(string_s21, "S");
  tok = strtok(string, "S");

  while (tok != S21_NULL && tok_s21 != S21_NULL) {
    if (tok_s21) {
      tok_s21 = s21_strtok(S21_NULL, "S");
    }
    if (tok) {
      tok = strtok(S21_NULL, "S");
    }
  }
  ck_assert((tok == S21_NULL) && (tok_s21 == S21_NULL));
  // free(tok_s21);
}
END_TEST

START_TEST(test_s21_strtok_3) {
  char string_s21[] = "AAASEGSEGESEGESEGDDDDDSS";
  char string[] = "AAASEGSEGESEGESEGDDDDDSS";
  char *tok = S21_NULL;
  char *tok_s21 = S21_NULL;

  tok_s21 = s21_strtok(string_s21, "\0");
  tok = strtok(string, "\0");

  ck_assert_str_eq(tok_s21, tok);
  // free(tok_s21);
}
END_TEST

START_TEST(test_s21_strtok_4) {
  char string_s21[] = "AAASEGSEGESEGESEGDDDDDSS";
  char string[] = "AAASEGSEGESEGESEGDDDDDSS";
  char *tok = S21_NULL;
  char *tok_s21 = S21_NULL;
  int i = 0;

  tok_s21 = s21_strtok(string_s21, "\0");
  tok = strtok(string, "\0");

  while (i != 2) {
    if (tok_s21) {
      tok_s21 = s21_strtok(S21_NULL, "\0");
    }
    if (tok) {
      tok = strtok(S21_NULL, "\0");
    }
    i++;
  }
  ck_assert((tok == S21_NULL) && (tok_s21 == S21_NULL));
  // free(tok_s21);
}
END_TEST

START_TEST(test_s21_strtok_5) {
  char string_s21[] = "AAASEGSEGESEGESEGDDDDDSS";
  char string[] = "AAASEGSEGESEGESEGDDDDDSS";
  char *tok = S21_NULL;
  char *tok_s21 = S21_NULL;

  tok_s21 = s21_strtok(string_s21, "S");
  tok = strtok(string, "S");

  tok_s21 = s21_strtok(S21_NULL, "SEG");
  tok = strtok(S21_NULL, "SEG");

  ck_assert_str_eq(tok_s21, tok);
}
END_TEST

START_TEST(test_s21_strtok_6) {
  char string_s21[] = "Amir dug a hole";
  char string[] = "Amir dug a hole";
  char *tok = S21_NULL;
  char *tok_s21 = S21_NULL;

  tok_s21 = s21_strtok(string_s21, "i");
  tok = strtok(string, "i");

  ck_assert_str_eq(tok_s21, tok);
}
END_TEST

START_TEST(test_s21_strtok_7) {
  char string_s21[] = "Amir dug a hole";
  char string[] = "Amir dug a hole";
  char *tok = S21_NULL;
  char *tok_s21 = S21_NULL;

  tok_s21 = s21_strtok(string_s21, "Amir dug a hole");
  tok = strtok(string, "Amir dug a hole");

  ck_assert((tok == S21_NULL) && (tok_s21 == S21_NULL));
}
END_TEST

START_TEST(test_s21_strtok_8) {
  char string_s21[] = "Amir dug a hole";
  char string[] = "Amir dug a hole";
  char *tok = S21_NULL;
  char *tok_s21 = S21_NULL;

  tok_s21 = s21_strtok(string_s21, "");
  tok = strtok(string, "");

  ck_assert_str_eq(tok_s21, tok);
}
END_TEST

Suite *s21_strtok_suite(void) {
  Suite *suite;
  TCase *tc_s21_strtok;

  suite = suite_create("s21_strtok");

  tc_s21_strtok = tcase_create("S21_strtok");

  tcase_add_test(tc_s21_strtok, test_s21_strtok_1);
  suite_add_tcase(suite, tc_s21_strtok);

  tcase_add_test(tc_s21_strtok, test_s21_strtok_2);
  suite_add_tcase(suite, tc_s21_strtok);

  tcase_add_test(tc_s21_strtok, test_s21_strtok_3);
  suite_add_tcase(suite, tc_s21_strtok);

  tcase_add_test(tc_s21_strtok, test_s21_strtok_4);
  suite_add_tcase(suite, tc_s21_strtok);

  tcase_add_test(tc_s21_strtok, test_s21_strtok_5);
  suite_add_tcase(suite, tc_s21_strtok);

  tcase_add_test(tc_s21_strtok, test_s21_strtok_6);
  suite_add_tcase(suite, tc_s21_strtok);

  tcase_add_test(tc_s21_strtok, test_s21_strtok_7);
  suite_add_tcase(suite, tc_s21_strtok);

  tcase_add_test(tc_s21_strtok, test_s21_strtok_8);
  suite_add_tcase(suite, tc_s21_strtok);

  return suite;
}
