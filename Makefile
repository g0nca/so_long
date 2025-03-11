# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggomes-v <ggomes-v@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 13:11:58 by ggomes-v          #+#    #+#              #
#    Updated: 2025/03/11 09:40:36 by ggomes-v         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# A saida padrao e de erro nao sao mostradas | > /dev/null 2>&1
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./libft -I./minilibx-linux -I./get_next_line
LIBFT = ./libft/libft.a
GNL = ./get_next_line/get_next_line.a
MLX = ./minilibx-linux/libmlx.a
NAME = so_long


SRC = so_long.c\
		checks.c\
		utils.c

OBJ = $(SRC:.c=.o)

# Regras
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(GNL) $(MLX)
	$(CC) $(OBJ) $(GNL) $(LIBFT) -L./minilibx-linux -lmlx -lX11 -lXext -lm -o $(NAME)
	@echo "	╔═════════════════════════════════════╗"
	@echo "	║ ✅ |${GREEN}All Files Compiled${RESET}     ║"
	@echo "	╚═════════════════════════════════════╝"  


%.o: %.c
	@echo "${GREEN}${BOLD}✅ | Compiling $<...${RESET}"
	@$(CC) $(CFLAGS) -I./libft -I./get_next_line -I./minilibx-linux -c $< -o $@

$(LIBFT):
	@make -C ./libft > /dev/null 2>&1

$(GNL):
	@make -C ./get_next_line > /dev/null 2>&1

$(MLX):
	@make -C ./minilibx-linux > /dev/null 2>&1

clean:
	@rm -rf $(OBJ)
	@make clean -C ./libft > /dev/null 2>&1
	@make clean -C ./minilibx-linux > /dev/null 2>&1
	@echo "	╔═════════════════════════════════════╗"
	@echo "	║ 🗑️  |${BOLD}Cleaned Successfully!${RESET}   ║"
	@echo "	╚═════════════════════════════════════╝"

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C ./libft > /dev/null 2>&1
	@make fclean -C ./get_next_line > /dev/null 2>&1
	@make clean -C ./minilibx-linux > /dev/null 2>&1
	@echo "	╔═════════════════════════════════════╗"
	@echo "	║ 🗑️  |${CYAN}Full Clean Done!${RESET}    ║"
	@echo "	╚═════════════════════════════════════╝"

re: fclean all
.PHONY: all clean fclean re

RESET = \033[0m      
BOLD = \033[1m  
RED = \033[31m      
GREEN = \033[32m   
YELLOW = \033[33m  
BLUE = \033[34m     
MAGENTA = \033[35m   
CYAN = \033[36m      
WHITE = \033[37m
