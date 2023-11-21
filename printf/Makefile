# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akambou <akambou@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/14 09:56:46 by akambou           #+#    #+#              #
#    Updated: 2023/11/21 23:16:30 by akambou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = ft_printf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -I $(INCL)

INCL = includes/*.h

SRCS = src/*.c

OBJ = $(patsubst src/%.c,obj/%.o,$(SRCS))

all: $(NAME)

$(NAME): $(OBJ)
	@echo "🔨 Building $(NAME)..."
	@ar rcs $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "✅ $(NAME) compiled successfully."

obj/%.o : src/%.c Makefile
	@mkdir -p obj
	@echo "🔨 Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "✅ $< compiled successfully."

clean:
	@echo "🧹 Cleaning object files..."
	@rm -rf obj
	@echo "✅ Object files cleaned successfully."

fclean: clean
	@echo "🧹 Cleaning $(NAME)..."
	@rm -rf $(NAME)
	@echo "✅ $(NAME) cleaned successfully."

re: fclean all

.PHONY: all clean fclean re
