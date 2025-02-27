# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggomes-v <ggomes-v@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 13:11:58 by ggomes-v          #+#    #+#              #
#    Updated: 2025/02/27 16:35:48 by ggomes-v         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# A saida padrao e de erro nao sao mostradas | > /dev/null 2>&1
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a
MLX = ./minilibx-linux/libmlx.a
NAME = so_long


SRC = so_long.c checks.c # Adicione os arquivos de fonte do seu projeto aqui
OBJ = $(SRC:.c=.o)

# Regras
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	@$(CC) $(OBJ) -L./libft -lft -L./minilibx-linux -lmlx -lX11 -lXext -lm -o $(NAME)
	@echo "	╔═════════════════════════════════════╗"
	@echo "	║ ✅ |${GREEN}All Files Compiled${RESET}     ║"
	@echo "	╚═════════════════════════════════════╝"  


$(OBJ): $(SRC)
	@echo "${GREEN}${BOLD}✅ | Compiling $<...${RESET}"
	@$(CC) $(CFLAGS) -I./libft -I./minilibx-linux -c $< -o $@

$(LIBFT):
	@make -C ./libft > /dev/null 2>&1

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
