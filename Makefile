# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggomes-v <ggomes-v@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 13:11:58 by ggomes-v          #+#    #+#              #
#    Updated: 2025/03/19 13:16:49 by ggomes-v         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilador e flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Diretórios
SRCDIR = src
BONUSDIR = src_bonus
LIBFTDIR = inc/libft
PRINTF_DIR = inc/ft_printf
GNL_DIR = inc/get_next_line
MLX_DIR = inc/minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_INCLUDE = -I$(MLX_DIR)

# Arquivos de so_long
SRCS = src/so_long.c src/ft_check.c src/ft_check2.c src/ft_check3.c src/startgame.c\
		src/moves.c src/load_images.c src/utils.c
OBJS = $(SRCS:.c=.o)

# Arquivos de so_long_bonus (MANUALMENTE)
BONUS_SRCS = src_bonus/ft_check.c src_bonus/ft_check2.c src_bonus/ft_check3.c\
				src_bonus/startgame.c src_bonus/moves.c src_bonus/utils.c\
				src_bonus/bonus.c src_bonus/load_images.c src_bonus/so_long_bonus.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# Bibliotecas
LIBFT = $(LIBFTDIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a
GNL = $(GNL_DIR)/get_next_line.a
MLX = $(MLX_DIR)/libmlx.a

# Nome dos executáveis
NAME = so_long
BONUS_NAME = so_long_bonus

# 🛠 **Regra padrão: compila apenas so_long**
all: $(NAME)

# Compilar so_long (NORMAL)
$(NAME): $(OBJS) $(LIBFT) $(PRINTF) $(GNL) $(MLX)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(MLX_DIR) -lmlx -lX11 -lXext -lm $(LIBFT) $(PRINTF) $(GNL)

# Compilar so_long_bonus SOMENTE quando `make bonus` for chamado
bonus: $(BONUS_OBJS) $(LIBFT) $(PRINTF) $(GNL) $(MLX_LIB)
	$(CC) $(CFLAGS) $(MLX_INCLUDE) -o $(BONUS_NAME) $(BONUS_OBJS) -L$(MLX_DIR) -lmlx -lX11 -lXext -lm $(LIBFT) $(PRINTF) $(GNL)

# Regras para compilar cada .c em .o (sem wildcard)
src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

so_long_bonus_path/%.o: so_long_bonus_path/%.c
	$(CC) $(CFLAGS) $(MLX_INCLUDE) -c $< -o $@

# Criar as bibliotecas (libft, ft_printf, get_next_line)
$(LIBFT):
	make -C $(LIBFTDIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

$(GNL):
	make -C $(GNL_DIR)

$(MLX):
	make -C $(MLX_DIR)

# Limpeza
clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	make -C $(LIBFTDIR) clean
	make -C $(PRINTF_DIR) clean
	make -C $(GNL_DIR) clean

fclean: clean
	rm -f $(NAME) so_long_bonus/$(BONUS_NAME)
	rm -f $(BONUS_NAME)
	make -C $(LIBFTDIR) fclean
	make -C $(PRINTF_DIR) fclean
	make -C $(GNL_DIR) fclean

re: fclean all


RESET = \033[0m
BOLD = \033[1m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
WHITE = \033[37m