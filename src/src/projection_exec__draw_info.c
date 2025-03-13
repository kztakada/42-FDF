/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_exec__draw_info.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:18:44 by katakada          #+#    #+#             */
/*   Updated: 2025/03/13 21:37:10 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_global_info(void *mlx, void *win)
{
	mlx_string_put(mlx, win, BOL, G_L01, TXT_C0, G_INFO_L01);
	mlx_string_put(mlx, win, BOL, G_M01, TXT_C0, G_INFO_M01);
	mlx_string_put(mlx, win, BOL, G_M02, TXT_C0, G_INFO_M02);
	mlx_string_put(mlx, win, BOL, G_M03, TXT_C0, G_INFO_M03);
	mlx_string_put(mlx, win, BOL, G_K01, TXT_C0, G_INFO_K01);
	mlx_string_put(mlx, win, BOL, G_K02, TXT_C0, G_INFO_K02);
	mlx_string_put(mlx, win, BOL, G_K03, TXT_C0, G_INFO_K03);
	mlx_string_put(mlx, win, BOL, G_K04, TXT_C0, G_INFO_K04);
	mlx_string_put(mlx, win, BOL, G_K05, TXT_C0, G_INFO_K05);
	mlx_string_put(mlx, win, BOL, G_K06, TXT_C0, G_INFO_K06);
	mlx_string_put(mlx, win, BOL, G_K07, TXT_C0, G_INFO_K07);
	mlx_string_put(mlx, win, BOL, G_K08, TXT_C0, G_INFO_K08);
	mlx_string_put(mlx, win, BOL, G_K09, TXT_C0, G_INFO_K09);
	mlx_string_put(mlx, win, BOL, G_K10, TXT_C0, G_INFO_K10);
	mlx_string_put(mlx, win, BOL, G_K11, TXT_C0, G_INFO_K11);
	mlx_string_put(mlx, win, BOL, G_K12, TXT_C0, G_INFO_K12);
	mlx_string_put(mlx, win, BOL, G_K13, TXT_C0, G_INFO_K13);
	mlx_string_put(mlx, win, BOL, G_K14, TXT_C0, G_INFO_K14);
}

static char	*get_main_p_mode(t_screen *screen)
{
	if (screen->settings->is_moved == TRUE)
		return ("FREE");
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
	draw_mouse_drug_info(screen);
	mlx_string_put(screen->mlx, screen->mlx_win,
		np_offset_x(screen->views->main_view),
		np_offset_y(screen->views->main_view), TXT_C0, get_main_p_mode(screen));
}

static void	draw_multi_view_info(t_screen *screen)
{
	if (screen->settings->is_debug == TRUE)
		draw_mouse_drug_info(screen);
	else
		draw_mouse_click_info(screen);
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
