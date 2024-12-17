# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: katakada <katakada@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/17 18:59:18 by katakada          #+#    #+#              #
#    Updated: 2024/12/17 21:25:14 by katakada         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME			=	fdf

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror

INCS			=	-I includes/ -I $(LIBFT_DIR) -I $(MLX_DIR)

SRCS_PATH		=	src/
SRCS			=	$(wildcard $(SRCS_PATH)*.c)

OBJS_PATH		=	objs/
OBJS			=	$(SRCS:src/%.c=objs/%.o)

LIBFT_DIR		=	libft/
LIBFT			=	$(LIBFT_DIR)libft.a

MLX_DIR			=	minilibx/
MLX				=	$(MLX_DIR)libmlx_Linux.a
FRAMEWORKS		=	-lXext -lX11 -lm -lbsd


all:	$(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(INCS) $(OBJS) $(LIBFT) $(MLX) $(FRAMEWORKS) -o $(NAME)

$(OBJS_PATH)%.o : $(SRCS_PATH)%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@


bonus:	all


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
	rm -f $(NAME) $(NAME_BONUS)

re:		fclean all

.PHONY:	all bonus clean fclean re