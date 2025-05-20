NAME = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror
SRCS = prueba.c
OBJ = $(SRCS:.c=.o)
PRINTF_DIR = printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(PRINTF_DIR)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(PRINTF_LIB)

%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(PRINTF_DIR)
	rm -rf $(OBJ)

fclean: clean
	make fclean -C $(PRINTF_DIR)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean re fclean