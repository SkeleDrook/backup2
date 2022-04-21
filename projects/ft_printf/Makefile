# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohulik <ohulik@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/18 15:19:18 by ohulik            #+#    #+#              #
#    Updated: 2022/04/10 14:30:03 by ohulik           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables
NAME			= libftprintf.a
LIBFT			= libft
SRC_DIR			= src/
OBJ_DIR			= obj/
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -I
RM				= rm -f	
AR				= ar rcs
OBJ_MKDIR		= .cache_exists

#Colours
DEF_COLOR		= \033[0;39m
RED				= \033[0;91m
GREEN			= \033[0;92m
YELLOW			= \033[0;93m
BLUE			= \033[0;94m
MAGENTA			= \033[0;95m
CYAN			= \033[0;96m

#Sources
SRC_FILES		= ft_printf case case2

#Add Suffixes
SRC				= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ				= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

#Commands
all:			$(NAME)

$(NAME):		$(OBJ)
					@make -C $(LIBFT)
					@cp libft/libft.a .
					@mv libft.a $(NAME)
					@$(AR) $(NAME) $(OBJ)
					@echo "$(GREEN)Ft_printf compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c | $(OBJ_MKDIR)
					@echo "$(YELLOW)Compiling: $(MAGENTA)$< $(DEF_COLOR)."
					@$(CC) $(CFLAGS) include -c $< -o $@

$(OBJ_MKDIR):
					@mkdir -p $(OBJ_DIR)

run:
					@make -C $(LIBFT)
					@cp libft/libft.a .
					@mv libft.a $(NAME)
					@$(CC) -g -o a.out $(SRC) $(NAME)
clean:
					@$(RM) -rf $(OBJ_DIR)
					@make clean -C $(LIBFT)
					@echo "$(BLUE)Ft_printf object files cleaned!$(DEF_COLOR)"

fclean:			clean
					@$(RM) -f $(NAME)
					@$(RM) -f $(LIBFT)/libft.a
					@echo "$(CYAN)Ft_printf executable files cleaned!$(DEF_COLOR)"
					@echo "$(CYAN)Libft executable files cleaned!$(DEF_COLOR)"
re:				fclean all
					@echo "$(GREEN)Libft is cleaned and rebuilt!$(DEF_COLOR)"
					@echo "$(GREEN)Ft_printf is cleaned and rebuilt!$(DEF_COLOR)"
norm:
					@norminette $(SRC) include $(LIBFT) | grep -v Norme -B1 || true
.PHONY:			norm all clean fclean re 