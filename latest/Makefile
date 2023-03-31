# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salmanso <salmanso@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/24 20:19:30 by salmanso          #+#    #+#              #
#    Updated: 2023/04/01 00:58:05 by salmanso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAG		=	-Wall -Werror -Wextra

NAME		=	fractol

HEADER		=	fractol.h

MINILIBX	=	minilibx/liblmx.a

LIBFT		=	libft/libft.a

SRC			=	fractol.c \
				mandelbrot.c \
				julia.c \
				ft_fern.c \
				keys.c \
				ft_helper.c

OBJ			=	$(SRC:.c=.o)

CC			=	cc
RM			=	rm -f

DEF_COLOR	=	\033[0;39m
RED			=	\033[1;31m
GREEN		=	\033[1;32m
YELLOW		=	\033[0;33m
BLUE		=	\033[0;34m
CYAN		=	\033[0;36m
PINK		=	\033[0;35m

all: 		$(NAME)

$(NAME):	$(MINILIBX) $(LIBFT) $(OBJ)
			Make -C minilibx
			Make -C libft
			$(CC) $(CFLAG) $(SRC) -o $(NAME) -I $(HEADER) -L. $(LIBFT) -L ./minilibx -lmlx -framework OpenGL -framework Appkit
			@echo "$(GREEN)fractol successfully compiled!$(DEF_COLOR)"

$(MINILIBX):
			make minilibx

$(LIBFT):
			make libft

clean:
			$(RM) $(OBJ)
			@echo "$(YELLOW)fractol object files successfully cleaned!$(DEF_COLOR)"

fclean:		clean
			$(RM) $(NAME)
			@echo "$(CYAN)fractol executable files successfully cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo "$(PINK)Successfully cleaned and rebuilt everything for fractol!$(DEF_COLOR)" && rm *.o

norm:
			@norminette $(SRC) | grep -v Norme -B1 || true

.PHONY:		all clean fclean re norm
