/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_exec__draw_debag.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 22:48:52 by katakada          #+#    #+#             */
/*   Updated: 2025/03/16 15:11:03 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	m_s_put_free_tc0(t_screen *screen, int x, int y, char *str)
{
	mlx_string_put(screen->mlx, screen->mlx_win, x, y, TXT_C0, str);
	free(str);
}

static void	put_camera_status(t_screen *screen, t_view *view, int x, int y)
{
	mlx_string_put(screen->mlx, screen->mlx_win, x, y, TXT_C0, "CAMERA STATUS");
	mlx_string_put(screen->mlx, screen->mlx_win, x, y + 20, TXT_C0, "zoom");
	mlx_string_put(screen->mlx, screen->mlx_win, x, y + 40, TXT_C0, "x_angle");
	mlx_string_put(screen->mlx, screen->mlx_win, x, y + 60, TXT_C0, "y_angle");
	mlx_string_put(screen->mlx, screen->mlx_win, x, y + 80, TXT_C0, "z_angle");
	mlx_string_put(screen->mlx, screen->mlx_win, x, y + 100, TXT_C0,
		"x_offset");
	mlx_string_put(screen->mlx, screen->mlx_win, x, y + 120, TXT_C0,
		"y_offset");
	mlx_string_put(screen->mlx, screen->mlx_win, x, y + 140, TXT_C0, "z_scale");
	m_s_put_free_tc0(screen, x + 80, y + 20, ft_itoa(view->camera->zoom));
	m_s_put_free_tc0(screen, x + 80, y + 40, ft_dtoa(view->camera->x_angle));
	m_s_put_free_tc0(screen, x + 80, y + 60, ft_dtoa(view->camera->y_angle));
	m_s_put_free_tc0(screen, x + 80, y + 80, ft_dtoa(view->camera->z_angle));
	m_s_put_free_tc0(screen, x + 80, y + 100, ft_itoa(view->camera->x_offset));
	m_s_put_free_tc0(screen, x + 80, y + 120, ft_itoa(view->camera->y_offset));
	m_s_put_free_tc0(screen, x + 80, y + 140, ft_itoa(screen->z_scale));
}

static void	draw_debag_main_view(t_screen *screen)
{
	put_camera_status(screen, screen->views->main_view,
		np_offset_x(screen->views->main_view), screen->views->main_view->height
		- 220);
}

static void	draw_debag_multi_view(t_screen *screen)
{
	put_camera_status(screen, screen->views->multi_view->left_up,
		np_offset_x(screen->views->multi_view->left_up),
		np_offset_y(screen->views->multi_view->left_up)
		+ screen->views->multi_view->left_up->height - 220);
	put_camera_status(screen, screen->views->multi_view->right_up,
		np_offset_x(screen->views->multi_view->right_up),
		np_offset_y(screen->views->multi_view->right_up)
		+ screen->views->multi_view->right_up->height - 220);
	put_camera_status(screen, screen->views->multi_view->left_down,
		np_offset_x(screen->views->multi_view->left_down),
		np_offset_y(screen->views->multi_view->left_down)
		+ screen->views->multi_view->left_down->height - 220);
	put_camera_status(screen, screen->views->multi_view->right_down,
		np_offset_x(screen->views->multi_view->right_down),
		np_offset_y(screen->views->multi_view->right_down)
		+ screen->views->multi_view->right_down->height - 220);
}

void	draw_debag(t_screen *screen)
{
	draw_debag_fdf_info(screen->mlx, screen->mlx_win, screen,
		screen->views->main_view->fdf);
	if (screen->settings->screen_mode == MAIN_SCREEN)
		draw_debag_main_view(screen);
	else if (screen->settings->screen_mode == MULTI_SCREEN)
		draw_debag_multi_view(screen);
}
