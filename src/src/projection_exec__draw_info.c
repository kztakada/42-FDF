/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_exec__draw_info.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:18:44 by katakada          #+#    #+#             */
/*   Updated: 2025/03/12 21:01:18 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_global_info(void *mlx, void *win)
{
	mlx_string_put(mlx, win, BOL, I_ROW01, TXT_C0, G_INFO_L01);
	mlx_string_put(mlx, win, BOL, I_ROW03, TXT_C0, G_INFO_L03);
	mlx_string_put(mlx, win, BOL, I_ROW04, TXT_C0, G_INFO_L04);
	mlx_string_put(mlx, win, BOL, I_ROW05, TXT_C0, G_INFO_L05);
	mlx_string_put(mlx, win, BOL, I_ROW13, TXT_C0, G_INFO_L13);
	mlx_string_put(mlx, win, BOL, I_ROW14, TXT_C0, G_INFO_L14);
	mlx_string_put(mlx, win, BOL, I_ROW16, TXT_C0, G_INFO_L16);
	mlx_string_put(mlx, win, BOL, I_ROW18, TXT_C0, G_INFO_L18);
	mlx_string_put(mlx, win, BOL, I_ROW19, TXT_C0, G_INFO_L19);
	mlx_string_put(mlx, win, BOL, I_ROW20, TXT_C0, G_INFO_L20);
	mlx_string_put(mlx, win, BOL, I_ROW21, TXT_C0, G_INFO_L21);
	mlx_string_put(mlx, win, BOL, I_ROW23, TXT_C0, G_INFO_L23);
	mlx_string_put(mlx, win, BOL, I_ROW24, TXT_C0, G_INFO_L24);
	mlx_string_put(mlx, win, BOL, I_ROW26, TXT_C0, G_INFO_L26);
	mlx_string_put(mlx, win, BOL, I_ROW27, TXT_C0, G_INFO_L27);
}

static char	*get_p_mode(t_screen *screen)
{
	if (screen->settings->projection_mode == ISOMETRIC)
		return ("ISOMETRIC");
	else if (screen->settings->projection_mode == FRONT_VIEW)
		return ("FRONT VIEW");
	else if (screen->settings->projection_mode == TOP_VIEW)
		return ("TOP VIEW");
	else if (screen->settings->projection_mode == SIDE_VIEW)
		return ("SIDE VIEW");
	return ("FREE");
}

static void	draw_main_view_info(t_screen *screen)
{
	mlx_string_put(screen->mlx, screen->mlx_win, BOL, I_ROW07, TXT_C0,
		MAIN_L07);
	mlx_string_put(screen->mlx, screen->mlx_win, BOL, I_ROW08, TXT_C0,
		MAIN_L08);
	mlx_string_put(screen->mlx, screen->mlx_win, BOL, I_ROW09, TXT_C0,
		MAIN_L09);
	mlx_string_put(screen->mlx, screen->mlx_win, BOL, I_ROW10, TXT_C0,
		MAIN_L10);
	mlx_string_put(screen->mlx, screen->mlx_win,
		np_offset_x(screen->views->main_view),
		np_offset_y(screen->views->main_view), TXT_C0, get_p_mode(screen));
}

static void	draw_multi_view_info(t_screen *screen)
{
	mlx_string_put(screen->mlx, screen->mlx_win, BOL, I_ROW07, TXT_C0,
		MULTI_L07);
	mlx_string_put(screen->mlx, screen->mlx_win, BOL, I_ROW08, TXT_C0,
		MULTI_L08);
	mlx_string_put(screen->mlx, screen->mlx_win,
		np_offset_x(screen->views->multi_view->left_up),
		np_offset_y(screen->views->multi_view->left_up), TXT_C0, "FRONT VIEW");
	mlx_string_put(screen->mlx, screen->mlx_win,
		np_offset_x(screen->views->multi_view->right_up),
		np_offset_y(screen->views->multi_view->right_up), TXT_C0, "TOP VIEW");
	mlx_string_put(screen->mlx, screen->mlx_win,
		np_offset_x(screen->views->multi_view->left_down),
		np_offset_y(screen->views->multi_view->left_down), TXT_C0, "ISOMETRIC");
	mlx_string_put(screen->mlx, screen->mlx_win,
		np_offset_x(screen->views->multi_view->right_down),
		np_offset_y(screen->views->multi_view->right_down), TXT_C0,
		"SIDE VIEW");
}

void	draw_info(t_screen *screen)
{
	draw_global_info(screen->mlx, screen->mlx_win);
	if (screen->settings->screen_mode == MAIN_SCREEN)
		draw_main_view_info(screen);
	else if (screen->settings->screen_mode == MULTI_SCREEN)
		draw_multi_view_info(screen);
}
