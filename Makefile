LIB=s21_matrix
NAME=$(LIB).a
HEADERS_DIR = includes
HEADERS_FILES=$(LIB).h
SRCS_DIR=src

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
	s21_transpose.c

SRCS=$(addprefix $(SRCS_DIR)/, $(SRCS_FILES))
HEADERS = $(addprefix $(HEADERS_DIR)/, $(HEADERS_FILES))
OBJ=$(SRCS:.c=.o)
INCLUDES=-I./includes

CC=gcc -Wall -Wextra -Werror
THREADS = 8


all:
	$(MAKE) -j$(THREADS) $(NAME)

multi:
	$(MAKE) -j$(THREADS) all

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ) 
	@echo =================================
	@echo $(NAME) HAS BEEN MADE          
	@echo =================================	

%.o:%.c $(HEADERS)
	@$(CC) $(INCLUDES) -c $< -o $@
	@echo $<

		
clean:
	/bin/rm -f $(OBJ)
fclean: clean
	/bin/rm -f $(NAME)
re: fclean all

gcov_report:

test:

.PHONY: lib clean fclean all re multi
#all, clean, test, s21_matrix.a, gcov_report