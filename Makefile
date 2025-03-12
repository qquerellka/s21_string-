# Настройки компиляции
LIBRARY = s21_string.a
CC = gcc
ARR = ar
RL = ranlib
CFLAGS = -g -Wall -Wextra -Werror -std=c11
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
BRANCHES = --rc lcov_branch_coverage=1
GCOV_REPORT_DIR = gcov_report
TESTS_DIR = tests
TEST_PROGRAM = $(TESTS_DIR)/s21_check_string

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S), Darwin)  # macOS
    TEST_FLAGS = -lcheck -lm
	LIB = ./s21_string.a
else  # Linux
    TEST_FLAGS = -lcheck -lm -lsubunit
	LIB = -L. -l:s21_string.a
endif


# TEST_FLAGS = -lcheck -lrt -lm -lsubunit
# LIB = -L. -l:s21_string.a

# Источники и объекты
SOURCE = $(wildcard *.c)
OBJECTS = $(SOURCE:.c=.o)
TESTS = $(wildcard $(TESTS_DIR)/*.c)
TESTS_OBJECTS = $(TESTS:.c=.o)

# Основные цели
.PHONY: all clean format_project scan_project_on_format rebuild gcov_report valgrind_test test

all: $(LIBRARY) test gcov_report

$(LIBRARY): $(OBJECTS)
	$(ARR) r $(LIBRARY) $(OBJECTS)
	$(RL) $(LIBRARY)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Тестирование
test: $(LIBRARY) $(TESTS_OBJECTS)
	$(CC) $(CFLAGS) $(TESTS_OBJECTS) -o $(TEST_PROGRAM) $(LIB) $(TEST_FLAGS)
	$(TEST_PROGRAM)

gcov_report :
	$(CC) $(CFLAGS) $(TESTS) $(SOURCE) -o $(TEST_PROGRAM) $(TEST_FLAGS) $(GCOV_FLAGS)
	$(TEST_PROGRAM)
	mkdir -p $(GCOV_REPORT_DIR)
	lcov -t "Report" -c -d $(TESTS_DIR) -o $(GCOV_REPORT_DIR)/coverage.info $(BRANCHES)
	genhtml -o $(GCOV_REPORT_DIR)/html $(GCOV_REPORT_DIR)/coverage.info $(BRANCHES)


# Проверка на утечки памяти
valgrind_test:
	valgrind --leak-check=full $(TEST_PROGRAM)

# Очистка
clean:
	rm -rf $(OBJECTS) $(LIBRARY) $(TESTS_OBJECTS) $(TEST_PROGRAM) tests/*.gdna tests/*.gcno tests/*.gcda $(GCOV_REPORT_DIR)

# Форматирование кода
format_project:
	clang-format -i *.c *.h $(TESTS_DIR)/*.c $(TESTS_DIR)/*.h

# Проверка форматирования
scan_project_on_format:
	clang-format -n s21_string/*.c s21_string/*.h sprintscan/*.c sprintscan/*.h $(TESTS_DIR)/*.c $(TESTS_DIR)/*.h

# Пересборка
rebuild: clean all