OS := $(shell uname -s)
FLAGS = -Wall -Werror -Wextra
FILES = sfleta_math.c
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
	gcc $(FLAGS) --coverage sfleta_test.c $(FILES) -o test_gcov $(CHECK_FLAGS)
	./test_gcov
	lcov -t test_gcov -o coverage.info -c -d .
	genhtml -o report coverage.info
	$(OPEN) report/index.html

all: clean sfleta_math.a test
sfleta_math.a: sfleta_math.o
	ar rcs sfleta_math.a sfleta_math.o
	ranlib sfleta_math.a
test: sfleta_math.a
	gcc  -o test sfleta_test.c sfleta_math.a $(CHECK_FLAGS)
	./test

sfleta_math.o: sfleta_math.c
	gcc  -c -o sfleta_math.o sfleta_math.c

check: test
	cppcheck *.h *.c
	cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extension=c *.c *.h
	cppcheck --enable=all --suppress=missingIncludeSystem *.c
	$(MEMTEST)

clean:
	rm -rf test *.a *.o *.out *.cfg fizz *.gc* *.info report test_gcov
