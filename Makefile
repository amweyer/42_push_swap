# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amweyer <amweyer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/29 15:01:22 by amweyer           #+#    #+#              #
#    Updated: 2025/05/29 19:20:10 by amweyer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = $(addsuffix .c, main errors push rotate rev_rotate swap push_swap stack_init)

OBJS := $(SRC:%.c=%.o)

# BONUS_SRC = $(addprefix bonus/, $(addsuffix _bonus.c, ft_lstnew ft_lstadd_back ft_lstadd_front))

# BONUS_OBJS := $(BONUS_SRC:%.c=%.o)

SUPP_SRC = $(addprefix supp/, $(addsuffix .c, ft_putchar ft_putstr ft_putnbr))

SUPP_OBJS := $(SUPP_SRC:%.c=%.o)

CC = cc

CCFLAGS = -Wall -Werror -Wextra

# INC_DIR = .
LIBTF_DIR = ./libft
PRINTF_DIR = ./printf

# CPPFLAGS = -I$(INC_DIR) -I$(LIBTF_DIR) -I$(PRINTF_DIR)
CPPFLAGS = -I$(LIBTF_DIR) -I$(PRINTF_DIR)

OBJS_BASBO = $(OBJS) $(BONUS_OBJS)

OBJS_ALL = $(OBJS_BASBO) $(SUPP_OBJS)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(CCFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CPPFLAGS) $(CCFLAGS) -c $< -o $@


clean:
	$(RM) $(OBJS_ALL)

fclean: clean
	$(RM) $(NAME)


re: fclean all

bonus: $(OBJS_BASBO)
	$(CC) $(CCFLAGS) $? -o $(NAME)

# everything: $(OBJS_ALL)
# 	$(CC) $(CCFLAGS) $? -o $(NAME)

.PHONY: all clean fclean re bonus everything














NAME = push_swap
NAME_BONUS = checker

SRC_DIR = src
BONUS_DIR = bonus

OBJ_DIR = obj
BONUS_OBJ_DIR = obj_bonus
INC_DIR = include
LIBFT_DIR = libft
PRINTF_DIR = printf

SRC_FILES =	main.c \
			parsing.c \
			utils.c \
			error.c \
			utils2.c \
			utils3.c \
			sorting.c \
			data_functions.c \
			push.c \
			swap.c \
			rotate.c \
			quick.c \
			reverse_rotate.c
BONUS_SRC =	checker_bonus.c \
			error_bonus.c \
			parsing_bonus.c \
			push_bonus.c \
			reverse_rotate_bonus.c \
			rotate_bonus.c \
			swap_bonus.c \
			utils_bonus.c
r
OBJ = $(SRC_FILES:%.c=$(OBJ_DIR)/%.o)
OBJ_BONUS = $(BONUS_SRC:%.c=$(BONUS_OBJ_DIR)/%.o)

CFLAGS = -Wall -Wextra -Werror -g3 -I $(INC_DIR) -I $(LIBFT_DIR) -I $(PRINTF_DIR)
# SFLAGS = --fsanitize=address
LIBS = -L $(LIBFT_DIR) -lft -L $(PRINTF_DIR) -lftprintf

DEF_COLOR = \033[0;39m
GREEN = \033[0;92m

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_DIR)
	@make -C $(PRINTF_DIR)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)
	@echo "${GREEN}Compilation of $(NAME) done.${DEF_COLOR}"

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
	@make -C $(LIBFT_DIR)
	@make -C $(PRINTF_DIR)
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBS) -o $(NAME_BONUS)
	@echo "${GREEN}Compilation of $(NAME_BONUS) done.${DEF_COLOR}"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/push_swap.h | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
$(BONUS_OBJ_DIR)/%.o: $(BONUS_DIR)/%.c $(INC_DIR)/push_swap_bonus.h | $(BONUS_OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
$(BONUS_OBJ_DIR):
	@mkdir -p $(BONUS_OBJ_DIR)

clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(PRINTF_DIR) clean
	@rm -rf $(OBJ_DIR) $(BONUS_OBJ_DIR)
	@echo "${GREEN}Files clean up done.{DEF_COLOR}"

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@make -C $(PRINTF_DIR) fclean
	@rm -rf $(NAME) $(NAME_BONUS)
	@echo "${GREEN}Clean up done.{DEF_COLOR}"

re: fclean all

.PHONY: all bonus clean fclean re