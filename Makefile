NAME = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror
SRCS = main.c operaciones.c utils.c check_args.c duplicate_operations.c sort.c
OBJ = $(SRCS:.c=.o)
PRINTF_DIR = printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	@echo -n "\033[32mCompilando $(NAME)" && sleep 0.5 && echo -n "." && sleep 0.5 && echo -n "." && sleep 0.5 && echo -n ".\n"
	@make --no-print-directory -C $(PRINTF_DIR)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(PRINTF_LIB)

%.o : %.c 
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo -n "\033[34mLimpiando archivos objeto" && sleep 0.5 && echo -n "." && sleep 0.5 && echo -n "." && sleep 0.5 && echo -n ".\n"
	@make clean --no-print-directory -C $(PRINTF_DIR)
	@rm -rf $(OBJ)

fclean: clean
	@echo -n "\033[34mLimpiando binarios" && sleep 0.5 && echo -n "." && sleep 0.5 && echo -n "." && sleep 0.5 && echo -n ".\n"
	@make fclean --no-print-directory -C $(PRINTF_DIR)
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean re fclean