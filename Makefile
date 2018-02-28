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

SRCS	=	./main.c		\
				./mlx.c			\
				./fractal_mandelbrot.c	\
				./fractal_julie.c	\
				./fractal_newton.c	\
				./key_fonction.c	\
				./mouse_fonction.c

OBJS	=	$(SRCS:.c=.o)

CC	=	@gcc

CFLAGS	=	-I ./libft/includes -I ./minilibx_macos

LIB_PATH	=	./libft/libft.a

RM	=	/bin/rm -f

all	:	$(NAME)

$(NAME)	:	$(OBJS)
	@$(CC) $(OBJS) $(LIB_PATH) -o $(NAME) -lmlx -framework OpenGL -framework AppKit
	@echo "\033[32mFRACT_OL COMPILATING DONE\033[0m"

clean	:
	$(RM) $(OBJS)

fclean	:
	@$(RM) $(OBJS)
	@$(RM) $(NAME)
	@echo "\033[31mFRACT_OL CLEANING DONE"

re	:	fclean all

.PHONY	:	all clean fclean re
