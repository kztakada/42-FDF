# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: katakada <katakada@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/17 18:59:18 by katakada          #+#    #+#              #
#    Updated: 2025/03/15 18:37:57 by katakada         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME			=	fdf

CC				=	cc
DEBUG_CC		=	cc -g -fsanitize=address

CFLAGS			=	-Wall -Wextra -Werror

SRC_PATH		=	src/
INCS			=	-I $(SRC_PATH)includes/ -I $(LIBFT_DIR) -I $(MLX_DIR)

SRCS_PATH		=	$(SRC_PATH)src/
SRCS			=	$(wildcard $(SRCS_PATH)*.c)

OBJS_PATH		=	$(SRC_PATH)objs/
OBJS			=	$(SRCS:src/src/%.c=src/objs/%.o)

LIBFT_DIR		=	$(SRC_PATH)libft/
LIBFT			=	$(LIBFT_DIR)libft.a

MLX_DIR			=	$(SRC_PATH)minilibx/
MLX				=	$(MLX_DIR)libmlx_Linux.a
FRAMEWORKS		=	-lXext -lX11 -lm -lbsd

MLX_MAC			=	$(MLX_DIR)libmlx_Darwin.a
FRAMEWORKS_MAC	=	-L /usr/X11/include/../lib -lXext -lX11

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Darwin)
	INCS += -I /usr/X11/include
    MLX = $(MLX_MAC)
    FRAMEWORKS = $(FRAMEWORKS_MAC)
endif

all:	$(NAME)

$(NAME): $(MLX) $(OBJS) $(LIBFT) 
	$(CC) $(CFLAGS) $(INCS) $(OBJS) $(LIBFT) $(MLX) $(FRAMEWORKS) -o $(NAME)

$(OBJS_PATH)%.o : $(SRCS_PATH)%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@


bonus:	all

debug: $(OBJS) $(LIBFT) $(MLX)
	$(DEBUG_CC) $(CFLAGS) $(INCS) $(OBJS) $(LIBFT) $(MLX) $(FRAMEWORKS) -o $(NAME)


$(LIBFT):
	make bonus -C $(LIBFT_DIR)

$(MLX): | $(MLX_DIR)
	$(MAKE) -C $(MLX_DIR)

$(MLX_DIR):
	git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR)


clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)
	rm -rf $(OBJS_PATH)

fclean:
	make fclean -C $(LIBFT_DIR)
	rm -rf $(MLX_DIR)
	rm -rf $(OBJS_PATH)
	rm -f $(NAME)

re:		fclean all

.PHONY:	all bonus clean fclean re
