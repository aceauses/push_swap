# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aceauses <aceauses@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/19 11:33:07 by aceauses          #+#    #+#              #
#    Updated: 2023/06/19 15:35:03 by aceauses         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc 
CFLAGS = -Wall -Werror -Wextra
RM = rm -fr

SRC = push_swap.c

OBJS_DIR = OBJS/
OBJS = $(addprefix $(OBJS_DIR), $(notdir $(SRC:.c=.o)))

LIBFT_CLONE = https://github.com/aceauses/42libft
LIBFT_PATH = libft/
LIBFT_LIB = $(LIBFT_PATH)libft.a

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

$(OBJS_DIR)%.o: $(SRC)
	@echo "$(YELLOW)Compiling:$(RESET) $(BLUE)$<$(RESET)"
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT_PATH):
	@git clone $(LIBFT_CLONE) libft

$(LIBFT_LIB): $(LIBFT_PATH)
	@make -C $(LIBFT_PATH) all bonus

$(NAME): $(LIBFT_LIB) $(OBJS)
	@echo "$(GREEN)Compiled with $(CYAN)$(CFLAGS)$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_LIB)

clean:
	@$(RM) $(OBJS_DIR)
	@echo "$(CYAN)[push_swap] $(RED)Objects Cleaned$(RESET)"
	@make -C $(LIBFT_PATH) clean

fclean:
	@$(RM) $(NAME) $(OBJS_DIR)
	@echo "$(CYAN)[push_swap] $(RED)Executable, Objects Cleaned$(RESET)"
	@make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re