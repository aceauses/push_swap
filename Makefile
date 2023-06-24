# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aceauses <aceauses@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/19 11:33:07 by aceauses          #+#    #+#              #
#    Updated: 2023/06/24 18:06:14 by aceauses         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc 
CFLAGS = -Wall -Werror -Wextra
RM = rm -fr

UTILS_DIR = utils/
UTILS = $(wildcard $(UTILS_DIR)*.c)
UTILS_OBJS = $(patsubst %.c, $(OBJS_DIR)%.o, $(notdir $(UTILS)))
SRC = push_swap.c

OBJS_DIR = OBJS/
OBJS = $(addprefix $(OBJS_DIR), $(notdir $(SRC:.c=.o))) $(UTILS_OBJS)


LIBFT_CLONE = https://github.com/aceauses/42libft
LIBFT_PATH = libft/
LIBFT_LIB = $(LIBFT_PATH)libft.a

PRINTF_CLONE = https://github.com/aceauses/42Printf
PRINTF_PATH = printf/
PRINTF_LIB = $(PRINTF_PATH)libftprintf.a


BOLD    := \033[1m./SRC/
RED     := \033[31;1m
GREEN   := \033[32;1m
YELLOW  := \033[33;1m
BLUE    := \033[34;1m
MAGENTA := \033[35;1m
CYAN    := \033[36;1m
WHITE   := \033[37;1m
RESET	= \x1b[0m

all: $(NAME)

$(OBJS_DIR)%.o: $(UTILS_DIR)%.c
	@echo "$(YELLOW)Compiling:$(RESET) $(BLUE)$<$(RESET)"
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c -o $@ $<

$(OBJS_DIR)%.o: %.c
	@echo "$(YELLOW)Compiling:$(RESET) $(BLUE)$<$(RESET)"
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT_PATH):
	@git clone $(LIBFT_CLONE) libft

$(LIBFT_LIB): $(LIBFT_PATH)
	@make -C $(LIBFT_PATH) all bonus

$(PRINTF_PATH):
	@git clone $(PRINTF_CLONE) printf

$(PRINTF_LIB): $(PRINTF_PATH)
	@make -C $(PRINTF_PATH) all

$(NAME): $(LIBFT_LIB) $(PRINTF_LIB) $(OBJS)
	@echo "$(GREEN)Compiled with $(CYAN)$(CFLAGS)$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT_LIB) $(PRINTF_LIB)

clean:
	@$(RM) $(OBJS_DIR)
	@echo "$(CYAN)[push_swap] $(RED)Objects Cleaned$(RESET)"
	@make -C $(LIBFT_PATH) clean
	@make -C $(PRINTF_PATH) clean

fclean:
	@$(RM) $(NAME) $(OBJS_DIR)
	@echo "$(CYAN)[push_swap] $(RED)Executable, Objects Cleaned$(RESET)"
	@make -C $(LIBFT_PATH) fclean
	@make -C $(PRINTF_PATH) fclean

re: fclean all

.PHONY: all clean fclean re