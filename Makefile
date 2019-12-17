# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: tprzybyl <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/03 11:36:22 by tprzybyl     #+#   ##    ##    #+#        #
#    Updated: 2019/01/21 21:43:30 by tprzybyl    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = fractol

FLAGS = -lpthread -Wall -Wextra -Werror

SRC = main.c ft_error_func.c ft_images.c ft_mandelbrot.c ft_gradient.c \
	ft_julia.c ft_burningship.c ft_printcommands.c ft_tricorn.c \
	ft_triplebrot.c ft_extra.c ft_hooks.c\

OBJ = $(subst .c,.o,$(SRC))

LIGHT_PINK = \033[0;38;5;200m

PINK = \033[0;38;5;198m

DARK_BLUE = \033[0;38;5;110m

GREEN = \033[0;38;5;111m

LIGHT_GREEN = \033[0;38;5;121m

FLASH_GREEN = \033[33;32m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(DARK_BLUE)\nFichiers de "$(NAME)" compilés\n"
	@echo "$(LIGHT_GREEN)Compilation des Librairies : "
	@make -C libft/
	@make -C minilibx/
	@gcc $(FLAGS) -o $(NAME) $(OBJ) -I libft/includes -L libft/ -lft -L minilibx/ -lmlx -framework OpenGL -framework AppKit
	@echo "$(FLASH_GREEN)Programme "$(NAME)" compilé et prêt à l'usage !\n"

%.o: %.c fdf.h
	@gcc $(FLAGS) -I libft/includes -o $@ -c $<
	@echo "$(DARK_BLUE).\c"

clean:
	@rm -rf $(OBJ)
	@make -C libft/ clean
	@echo "$(LIGHT_PINK)Suppression des .o de "$(NAME)"\n"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(PINK)Suppression des .o de Libft \n"
	@make -C libft/ fclean
	@echo "$(PINK)Suppression des .o de Minilibx \n"
	@make -C minilibx/ fclean
	@echo "$(PINK)Suppression de" $(NAME)"\n"

re: fclean all
