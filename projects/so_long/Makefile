# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohulik <ohulik@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/12 20:18:05 by ohulik            #+#    #+#              #
#    Updated: 2022/04/21 00:55:52 by ohulik           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME = so_long
# SRC =	main.c\
# 		key_handling.c
# FLAGS = -Wall -Wextra -Werror -Lmlx -lmlx -g -Iincludes -framework OpenGL -framework AppKit 

# clean:
# 	@rm -f $(NAME)
# fclean:
# 	@rm -f $(NAME)
# re: fclean all

# .PHONY: all clean fclean re

# clang -help             All options list
# -g                      Generate source-level debug information
# -I <dir>                Add directory to include search path
# -L <dir>                Add directory to library search path
NAME = so_long

SRC =	src/main.c \
		src/key_handling.c \
		src/helper_functions.c \
		src/helper_functions_2.c \
		src/input_validation.c \
		src/map_handling.c \
		src/map_validation.c \
		src/draw_map.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c
		

FLAGS = -Wall -Wextra -Werror -Lmlx -lmlx -g -Iincludes -framework OpenGL -framework AppKit -fsanitize=address -o so_long

all:
	gcc $(SRC) $(FLAGS)
clean:
	$(RM) so_long
	
fclean: clean
	$(MAKE) clean -C mlx/
re: fclean all

.PHONY: all clean fclean re 