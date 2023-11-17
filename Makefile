# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akambou <akambou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 14:45:18 by akambou           #+#    #+#              #
#    Updated: 2023/11/17 14:45:22 by akambou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I includes
RM = rm -rf

SRCS = src/fractol.c src/utils.c
OBJS = ${SRCS:.c=.o}
NAME = fract-ol
HEADER = includes/fractol.h


all: $(NAME)

$(NAME): $(OBJS) $(HEADER) Makefile
	@make -C libft
	@make -C minilibx-linux
	@echo "🔨 Building $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)
	@echo "✅ Done building $(NAME)!"

fclean: clean
	@echo "🧹 Cleaning up executables..."
	@$(RM) $(NAME) $(BONUS_NAME)
	@make fclean -C libft
	@make fclean -C minilibx-linux
	@echo "✅ Done cleaning up executables!"

clean:
	@echo "🧹 Cleaning up..."
	@$(RM) $(OBJS) $(OBJSBONUS)
	@make clean -C libft
	@make clean -C minilibx-linux
	@echo "✅ Done cleaning up!"

re: fclean all

.PHONY: all clean fclean re bonus rebonus
