/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface__mouse__mouse_move__rotate_camera        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:36:59 by katakada          #+#    #+#             */
/*   Updated: 2025/03/12 00:52:54 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotate_angle_xy(int mouse_x, int mouse_y, t_camera *camera,
		t_mouse *mouse)
{
	double	delta_x;
	double	delta_y;

	delta_x = (mouse_y - mouse->prev_y) * MOUSE_SCALE * -1;
	delta_y = (mouse_x - mouse->prev_x) * MOUSE_SCALE;
	rotate_angle(&camera->x_angle, delta_x);
	rotate_angle(&camera->y_angle, delta_y);
}

void	rotate_camera_angle_xy(int mouse_x, int mouse_y, t_screen *screen)
{
	if (screen->settings->screen_mode == MAIN_SCREEN)
		rotate_angle_xy(mouse_x, mouse_y, screen->views->main_view->camera,
			screen->mouse);
	else if (screen->settings->screen_mode == MULTI_SCREEN)
	{
		rotate_angle_xy(mouse_x, mouse_y,
			screen->views->multi_view->left_up->camera, screen->mouse);
		rotate_angle_xy(mouse_x, mouse_y,
			screen->views->multi_view->right_up->camera, screen->mouse);
		rotate_angle_xy(mouse_x, mouse_y,
			screen->views->multi_view->left_down->camera, screen->mouse);
		rotate_angle_xy(mouse_x, mouse_y,
			screen->views->multi_view->right_down->camera, screen->mouse);
	}
}

static void	rotate_angle_z_by_mouse(int mouse_x, int mouse_y, t_camera *camera,
		t_mouse *mouse)
{
	double	delta;

	delta = (mouse_x - mouse->prev_x) * MOUSE_SCALE;
	delta += (mouse_y - mouse->prev_y) * MOUSE_SCALE;
	rotate_angle(&camera->z_angle, delta);
}

void	rotate_camera_angle_z_by_mouse(int mouse_x, int mouse_y,
		t_screen *screen)
{
	if (screen->settings->screen_mode == MAIN_SCREEN)
		rotate_angle_z_by_mouse(mouse_x, mouse_y,
			screen->views->main_view->camera, screen->mouse);
	else if (screen->settings->screen_mode == MULTI_SCREEN)
	{
		rotate_angle_z_by_mouse(mouse_x, mouse_y,
			screen->views->multi_view->left_up->camera, screen->mouse);
		rotate_angle_z_by_mouse(mouse_x, mouse_y,
			screen->views->multi_view->right_up->camera, screen->mouse);
		rotate_angle_z_by_mouse(mouse_x, mouse_y,
			screen->views->multi_view->left_down->camera, screen->mouse);
		rotate_angle_z_by_mouse(mouse_x, mouse_y,
			screen->views->multi_view->right_down->camera, screen->mouse);
	}
}
