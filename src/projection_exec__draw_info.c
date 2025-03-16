/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_exec__draw_info.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:18:44 by katakada          #+#    #+#             */
/*   Updated: 2025/03/15 18:11:12 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	draw_global_instructions(screen->mlx, screen->mlx_win);
	draw_global_switch_status(screen);
	if (screen->settings->screen_mode == MAIN_SCREEN)
		draw_main_view_info(screen);
	else if (screen->settings->screen_mode == MULTI_SCREEN)
		draw_multi_view_info(screen);
}
