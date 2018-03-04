# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vferreir <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/20 11:03:01 by vferreir          #+#    #+#              #
#    Updated: 2018/02/20 11:03:02 by vferreir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	./fractol

SRCS	=	./srcs/main.c		\
				./srcs/mlx.c			\
				./srcs/utils.c		\
				./srcs/fractal_mandelbrot.c	\
				./srcs/fractal_julia.c	\
				./srcs/fractal_newton.c	\
				./srcs/key_fonction.c	\
				./srcs/mouse_fonction.c

OBJS	=	$(SRCS:.c=.o)

CC	=	@gcc

CFLAGS	=	-I ./libft/includes -I ./includes -I ./minilibx_macos

LIB_PATH	=	./libft/libft.a ./minilibx_macos/libmlx.a

RM	=	/bin/rm -f

all	:	$(NAME)

$(NAME)	:	$(OBJS)
	@make -C libft/
	@make -C minilibx_macos/
	@$(CC) $(OBJS) $(LIB_PATH) -o $(NAME) -framework OpenGL -framework AppKit
	@echo "\033[32mFRACT_OL COMPILATING DONE\033[0m"
	@$(RM) $(OBJS)

clean	:
	@make clean -C minilibx_macos/
	@make clean -C libft/
	@$(RM) $(OBJS)

fclean	:
	@make clean -C minilibx_macos/
	@make fclean -C libft/
	@$(RM) $(OBJS)
	@$(RM) $(NAME)
	@echo "\033[31mFRACT_OL CLEANING DONE"

re	:	fclean all

.PHONY	:	all clean fclean re
