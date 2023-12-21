LIB=s21_matrix
NAME=$(LIB).a

######## SRC ########

SRCS_DIR=.
SRCS_FILES=s21_calc_complements.c \
	s21_create_matrix.c \
	s21_determinant.c \
	s21_eq_matrix.c \
	s21_get_incorrect_matrix.c \
	s21_inverse_matrix.c \
	s21_mult_matrix.c \
	s21_mult_number.c \
	s21_remove_matrix.c \
	s21_sub_matrix.c \
	s21_sum_matrix.c \
	s21_transpose.c \
	s21_free_matrix.c

SRCS=$(addprefix $(SRCS_DIR)/, $(SRCS_FILES))
OBJ=$(SRCS:.c=.o)

######## HEADERS ########

HEADERS_DIR = includes
HEADERS_FILES=$(LIB).h
HEADERS = $(addprefix $(HEADERS_DIR)/, $(HEADERS_FILES))

######## TEST ########

TEST_DIR=tests
TEST_HEADERS_DIR=$(TEST_DIR)/includes
TEST_HEADERS_FILES=tests.h
TEST_HEADERS=$(addprefix $(TEST_HEADERS_DIR)/, $(TEST_HEADERS_FILES))

TEST_SRCS_DIR = $(TEST_DIR)/src
TEST_NAME=test.bin
TEST_SRCS_FILES=$(notdir $(shell find $(TEST_SRCS_DIR) -name "test_*.c"))
TEST_SRCS=$(addprefix $(TEST_SRCS_DIR)/, $(TEST_SRCS_FILES))
TEST_OBJS=$(TEST_SRCS:%.c=%.o)

######## LINK ########

OS = $(shell uname)
ifeq ($(OS), Darwin)
	TEST_LIBS=-lcheck
else
	TEST_LIBS=-lcheck -lm -lsubunit -lpthread -lrt 
endif

######## COMPILE ########

CC_LIB = gcc -Wall -Wextra -Werror -Wuninitialized -std=c11
CC_LIB_CVR=gcc -Wall -Wextra -Werror -Wuninitialized -std=c11 --coverage -lgcov
CC_TEST = gcc -Wall -Wextra -Werror -Wuninitialized -std=c11
COV_LIBS = --coverage -lgcov
THREADS = 8

######## COMPILE ########

GCOV_INFO_FILE=gcovreport.info
ROOT_FOLDER=.
REPORT_FOLDER=report

all:
	$(MAKE) -j$(THREADS) $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ) 
	@echo =================================
	@echo $(NAME) HAS BEEN MADE          
	@echo =================================	
	$(info    VAR: $(TEST_OBJS))

%.o:%.c $(HEADERS)
	@$(CC_LIB) -I./$(HEADERS_DIR) -c $< -o $@
	@echo $<

$(TEST_NAME): $(NAME) $(TEST_OBJS)
	$(CC_TEST) $(TEST_OBJS) -L./ -l:$(NAME) -o $@ $(TEST_LIBS) $(COV_LIBS)

$(TEST_SRCS_DIR)/%.o:$(TEST_SRCS_DIR)/%.c $(TEST_HEADERS)
	$(CC_TEST) -I./$(TEST_HEADERS_DIR) -I./$(HEADERS_DIR) -c $< -o $@

test: 
	
test: CC_LIB = $(CC_LIB_CVR)
test: clean $(TEST_NAME)
	./$(TEST_NAME)

gcov_report: test
	@lcov -o $(GCOV_INFO_FILE) -c -d $(ROOT_FOLDER)
	@genhtml -o $(REPORT_FOLDER) $(GCOV_INFO_FILE)

clang_fix:
	@cp ../materials/linters/.clang-format .
	@clang-format --style=Google -i */*.c */*.h *.h
	@rm .clang-format

clang_check:
	@cp ../materials/linters/.clang-format .
	@clang-format --style=Google -n */*.c */*.h *.h
	@rm .clang-format

multi:
	$(MAKE) -j$(THREADS) all
		
clean:
	@/bin/rm -f $(OBJ)
	@/bin/rm -f $(TEST_OBJS)
	@find . -name "*.gcda" -type f -delete
	@find . -name "*.gcno" -type f -delete
	@/bin/rm -rf $(REPORT_FOLDER)
	@/bin/rm -f $(GCOV_INFO_FILE)
fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(TEST_NAME)
re: fclean all



.PHONY: lib clean fclean all re multi
#all, clean, test, s21_matrix.a, gcov_report