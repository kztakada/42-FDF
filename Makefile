# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: katakada <katakada@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/17 18:59:18 by katakada          #+#    #+#              #
#    Updated: 2025/03/15 23:27:32 by katakada         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME			=	fdf

CC				=	cc
DEBUG_CC		=	cc -D IS_DEBUG=1 -g -fsanitize=address

CFLAGS			=	-Wall -Wextra -Werror

SRC_PATH		=	src/
INCS			=	-I $(SRC_PATH)includes/ -I $(LIBFT_DIR) -I $(MLX_DIR)

SRCS_PATH		=	$(SRC_PATH)src/
SRCS			=	$(SRCS_PATH)draw_view.c \
					$(SRCS_PATH)draw_view__draw_line.c \
					$(SRCS_PATH)draw_view__draw_line__calc_dot_color.c \
					$(SRCS_PATH)draw_view__draw_line__draw_dot_line.c \
					$(SRCS_PATH)draw_view__draw_line__is_out_of_view.c \
					$(SRCS_PATH)draw_view__draw_line__is_out_of_view__util.c \
					$(SRCS_PATH)draw_view__draw_line__util.c \
					$(SRCS_PATH)draw_view__util.c \
					$(SRCS_PATH)error_exit.c \
					$(SRCS_PATH)ft_atoi_base.c \
					$(SRCS_PATH)init_camera.c \
					$(SRCS_PATH)init_camera__camera_assets.c \
					$(SRCS_PATH)init_screen.c \
					$(SRCS_PATH)init_views.c \
					$(SRCS_PATH)interface__keyboard.c \
					$(SRCS_PATH)interface__keyboard__reset_displayed_view.c \
					$(SRCS_PATH)interface__keyboard__toggle_auto_rotate.c \
					$(SRCS_PATH)interface__keyboard__translate_camera_pos.c \
					$(SRCS_PATH)interface__mouse__mouse_down.c \
					$(SRCS_PATH)interface__mouse__mouse_move.c \
					$(SRCS_PATH)interface__mouse__mouse_move__rotate_camera_angle.c \
					$(SRCS_PATH)interface__mouse__mouse_up.c \
					$(SRCS_PATH)interface__util.c \
					$(SRCS_PATH)load_fdf.c \
					$(SRCS_PATH)load_fdf__calc_max_min_xyz.c \
					$(SRCS_PATH)load_fdf__read_fdf_lines.c \
					$(SRCS_PATH)load_fdf__read_fdf_lines__is_hex_str.c \
					$(SRCS_PATH)load_fdf__read_fdf_lines__is_int_str.c \
					$(SRCS_PATH)load_fdf__read_fdf_lines__validate_altitude_format.c \
					$(SRCS_PATH)load_fdf__util.c \
					$(SRCS_PATH)multi_view.c \
					$(SRCS_PATH)projection_exec.c \
					$(SRCS_PATH)projection_exec__auto_rotate_camera_angle.c \
					$(SRCS_PATH)projection_exec__draw_debag.c \
					$(SRCS_PATH)projection_exec__draw_debag__draw_debag_fdf.c \
					$(SRCS_PATH)projection_exec__draw_info.c \
					$(SRCS_PATH)projection_exec__draw_info__draw_global_info.c \
					$(SRCS_PATH)projection_exec__draw_info__util.c \
					$(SRCS_PATH)projection_exec__draw_screen.c \
					$(SRCS_PATH)projection_exec__draw_screen__util.c \
					$(SRCS_PATH)util.c \
					$(SRCS_PATH)util__convert_fdf_to_view_dot.c \
					$(SRCS_PATH)util__custom_get_next_line.c \
					$(SRCS_PATH)util__setup.c 

MAIN			=	$(SRCS_PATH)main.c
MAIN_BONUS		=	$(SRCS_PATH)main_bonus.c

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

ISBOUNS = 0
ISDEBUG = 0

ifeq ($(ISBOUNS), 1)
	SRCS += $(MAIN_BONUS)
else
	SRCS += $(MAIN)
endif

ifeq ($(ISDEBUG), 1)
	CC = $(DEBUG_CC)
endif



$(NAME): $(MLX) $(MAIN_OBJ) $(OBJS) $(LIBFT) 
	$(CC) $(CFLAGS) $(INCS) $(OBJS) $(LIBFT) $(MLX) $(FRAMEWORKS) -o $(NAME)

$(OBJS_PATH)%.o : $(SRCS_PATH)%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@


all:	$(NAME)

bonus:
	$(MAKE) ISBOUNS=1 all



debug: 
	$(MAKE) ISDEBUG=1 all

debug_bonus:
	$(MAKE) ISBOUNS=1 ISDEBUG=1 all 


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

.PHONY:	all bonus clean fclean re debug debug_bonus
