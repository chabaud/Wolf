# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schabaud <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/15 10:50:06 by schabaud          #+#    #+#              #
#    Updated: 2017/02/18 15:09:40 by schabaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GS	=	-Wall -Werror -Wextra -ansi

HEAD	=	-I./head

LIBFT	=	-I./libft/head -L./libft -lft

MLX		= 	-L/usr/local/lib/ -I/usr/local/include -lmlx -framework	\
						OpenGL -framework AppKit

NAME	=	wolf3d	

SRC		=	src/main.c			\
			src/texture.c		\
			src/mouve.c			\
			src/get_map.c		\
			src/play.c			\
			src/wolf.c			\
			src/line.c			\
			src/event.c

$(NAME): $(OBJ)

all: $(NAME)

$(NAME):
	@make -C ./libft
	@gcc -o $(NAME) $(SRC) $(HEAD) $(MLX) $(LIBFT) $(FLAGS)

clean:
	@rm -rf $(OBJ)
	@make clean -C ./libft

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(OBJ)
	@make fclean -C ./libft

make re: fclean all
