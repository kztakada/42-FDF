/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_exec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 01:22:09 by katakada          #+#    #+#             */
/*   Updated: 2025/03/13 15:23:54 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	auto_rotate_camera_angle_z(t_screen *screen)
{
	double	delta;

	if (screen->settings->auto_rotate_z == STOP)
		return ;
	delta = 0;
	if (screen->settings->auto_rotate_z == ROTATE_L)
		delta = +0.01;
	else if (screen->settings->auto_rotate_z == ROTATE_R)
		delta = -0.01;
	if (screen->settings->screen_mode == MAIN_SCREEN)
		rotate_angle(&screen->views->main_view->camera->z_angle, delta);
	else if (screen->settings->screen_mode == MULTI_SCREEN)
	{
		rotate_angle(&screen->views->multi_view->left_up->camera->z_angle,
			delta);
		rotate_angle(&screen->views->multi_view->right_up->camera->z_angle,
			delta);
		rotate_angle(&screen->views->multi_view->left_down->camera->z_angle,
			delta);
		rotate_angle(&screen->views->multi_view->right_down->camera->z_angle,
			delta);
	}
}

void	projection_exec(t_screen *screen)
{
	auto_rotate_camera_angle_z(screen);
	draw_screen(screen);
	mlx_put_image_to_window(screen->mlx, screen->mlx_win, screen->image->img, 0,
		0);
	draw_info(screen);
	if (screen->settings->is_debug == TRUE)
		draw_debag(screen);
}
