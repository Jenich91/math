OS := $(shell uname -s)
FLAGS = -Wall -Werror -Wextra
FILES = s21_math.c
OPEN:= open

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
    CC = gcc -std=c11 -D_GNU_SOURCE
	CCFLAGS += -D LINUX
	CHECK_FLAGS = -lcheck -lm -lpthread -lrt -lsubunit
	MEMTEST = valgrind --tool=memcheck --leak-check=full ./test
endif

ifeq ($(UNAME_S),Darwin)
    CC = gcc
	CCFLAGS += -D OSX
	CHECK_FLAGS = -lcheck
	MEMTEST = CK_FORK=no leaks -atExit -- ./test
endif


default: all
gcov_report:
	gcc $(FLAGS) --coverage s21_test.c $(FILES) -o test_gcov $(CHECK_FLAGS)
	./test_gcov
	lcov -t test_gcov -o coverage.info -c -d .
	genhtml -o report coverage.info
	$(OPEN) report/index.html

all: clean s21_math.a test
s21_math.a: s21_math.o
	ar rcs s21_math.a s21_math.o
	ranlib s21_math.a
test: s21_math.a
	gcc  -o test s21_test.c s21_math.a $(CHECK_FLAGS)
	./test

s21_math.o: s21_math.c
	gcc  -c -o s21_math.o s21_math.c

check: test
	cppcheck *.h *.c
	cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extension=c *.c *.h
	cppcheck --enable=all --suppress=missingIncludeSystem *.c
	$(MEMTEST)

clean:
	rm -rf test *.a *.o *.out *.cfg fizz *.gc* *.info report test_gcov
