# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akambou <akambou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 14:45:18 by akambou           #+#    #+#              #
#    Updated: 2023/11/24 01:08:31 by akambou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fract-ol

CC		= gcc
CFLAGS	= -Werror -Wextra -Wall
RM		= rm -rf

MLX_PATH	= minilibx-linux/
#MLX_PATH	= minilibx-macos/

MLX_NAME	= libmlx.a
MLX			= $(MLX_PATH)$(MLX_NAME)

LIBFT_PATH	= libft/
LIBFT_NAME	= libft.a
LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

INC			=	-I ./includes/\
				-I ./libft/\
				-I ./printf/\
				-I ./minilibx-linux/

SRC_PATH	=	src/
SRC			=	fractol.c \
				init.c \
				keys.c \
				render.c \
				sets.c \

OBJ_PATH	= obj/
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

all: $(MLX) $(LIBFT) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJS): $(OBJ_PATH)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

$(MLX):
	@make -sC $(MLX_PATH)
	@echo -e "\033[0;32mMinilibx created 📚\033[0m"

$(LIBFT):
	@make -sC $(LIBFT_PATH)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBFT) $(INC) -lXext -lX11 -lm

#	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) L$(MLX) \
	-lmlx -framework OpenGL -framework AppKit $(LIBFT) $(INC)

	-lmlx -framework OpenGL -framework AppKit
	@echo -e "\033[0;32mFractol created 📚\033[0m"

clean:
	@rm -rf $(OBJ_PATH)
	@make clean -sC $(MLX_PATH)
	@make clean -sC $(LIBFT_PATH)
	@echo -e "\033[0;31mCleaned Minilibx 🧹\033[0m"
	@echo -e "\033[0;31mCleaned Libft 🧹\033[0m"



fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT_PATH)$(LIBFT_NAME)
	@echo -e "\033[0;31mCleaned Fract-ol 🧹\033[0m"

re: fclean all

.PHONY: all re clean fclean
