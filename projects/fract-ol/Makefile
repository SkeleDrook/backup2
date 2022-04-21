# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohulik <ohulik@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/06 17:53:46 by ohulik            #+#    #+#              #
#    Updated: 2022/04/12 20:14:03 by ohulik           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= fractol

#-L <dir> Add directory to library search path
#-I adds a directory to the list of places searched by the compiler for a file named on a #include line, and -L adds a directory to the list of places searched by the linker for a library named with the -l option.
#-O3 is for getting a fast running code (even at the expense of some code bloat)
CC				= gcc
FLAGS			= -Wall -Wextra -Werror -O3
LIBRARIES		= -v -lmlx -lm -lft\
	-L$(LIBFT_DIR) -L$(MINILIBX_DIR)\
	-framework OpenGL -framework AppKit
INCLUDES		= -I$(HEADER_DIR) -I$(LIBFT_HEADER) -I$(MINILIBX_HEADER)

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = ./libft/
LIBFT_HEADER = $(LIBFT_DIR)include/

MINILIBX = $(MINILIBX_DIR)libmlx.a
MINILIBX_DIR = ./mlx/
MINILIBX_HEADER = $(MINILIBX_DIR)

HEADER_LIST = fractol.h define.h
HEADER_DIR = ./includes/
HEADER = $(addprefix $(HEADER_DIR), $(HEADER_LIST))

#Add preffixes $(addprefix src/,foo bar) produces the result ‘src/foo src/bar’.
#Pattern substitution $(patsubst %.c,%.o,x.c.c bar.c) produces the value ‘x.c.o bar.o’.
SOURCES_DIR		= ./src/ 
SOURCES_LIST	= main.c
SOURCES = $(addprefix $(SOURCES_DIR), $(SOURCES_LIST))

OBJECTS_DIR = obj/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIR), $(OBJECTS_LIST))

DEF_COLOR		= \033[0;39m
RED				= \033[0;91m
GREEN			= \033[0;92m
YELLOW			= \033[0;93m
BLUE			= \033[0;94m
MAGENTA			= \033[0;95m
CYAN			= \033[0;96m

# gcc -o <file> Write output to <file>
# gcc -c Compile or assemble the source files, but do not link. The linking stage simply is not done. The ultimate output is in the form of an object file for each source file.
# $@: The filename representing the target. $<: The filename of the first prerequisite.
#-p Create intermediate directories as required.  If this option is not specified, the full path prefix of each operand must already exist.  On the other hand, with this option specified, no error will be reported if a directory given as an operand already exists.
all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJECTS_DIR) $(OBJECTS)
	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) -v -o $(NAME)
	@echo "\n$(NAME): $(GREEN)object files were created$(DEF_COLOR)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(DEF_COLOR)"

# $(OBJECTS_DIR):
# 	@mkdir -p $(OBJECTS_DIR)
# 	@echo "$(NAME): $(GREEN)$(OBJECTS_DIR) was created$(DEF_COLOR)"

$(OBJECTS_DIR)%.o : $(SOURCES_DIR)%.c $(HEADER)
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(GREEN).$(DEF_COLOR)\c"

$(LIBFT):
	@echo "$(NAME): $(GREEN)Creating $(LIBFT)...$(DEF_COLOR)"
	@$(MAKE) -sC $(LIBFT_DIR)

$(MINILIBX):
	@echo "$(NAME): $(GREEN)Creating $(MINILIBX)...$(DEF_COLOR)"
	@$(MAKE) -sC $(MINILIBX_DIR)

clean:
	@$(MAKE) -sC $(LIBFT_DIR) clean
	@$(MAKE) -sC $(MINILIBX_DIR) clean
	@rm -rf $(OBJECTS_DIR)
	@echo "$(NAME): $(RED)$(OBJECTS_DIR) was deleted$(DEF_COLOR)"
	@echo "$(NAME): $(RED)object files were deleted$(DEF_COLOR)"

fclean: clean
	@rm -f $(MINILIBX)
	@echo "$(NAME): $(RED)$(MINILIBX) was deleted$(DEF_COLOR)"
	@rm -f $(LIBFT)
	@echo "$(NAME): $(RED)$(LIBFT) was deleted$(DEF_COLOR)"
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(DEF_COLOR)"

norm:
					@norminette $(SRC) include $(LIBFT) | grep -v Norme -B1 || true
.PHONY:			norm all clean fclean re 