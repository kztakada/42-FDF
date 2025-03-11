/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface__mouse__mouse_move__rotate_camera        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:36:59 by katakada          #+#    #+#             */
/*   Updated: 2025/03/11 14:55:14 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotate_angle_xy(int mouse_x, int mouse_y, t_camera *camera,
		t_mouse *mouse)
{
	camera->x_angle -= (mouse_y - mouse->prev_y) * MOUSE_SCALE;
	camera->y_angle += (mouse_x - mouse->prev_x) * MOUSE_SCALE;
	camera->x_angle = reset_angles(camera->x_angle);
	camera->y_angle = reset_angles(camera->y_angle);
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

static void	rotate_angle_z(int mouse_x, int mouse_y, t_camera *camera,
		t_mouse *mouse)
{
	camera->z_angle += (mouse_x - mouse->prev_x) * MOUSE_SCALE;
	camera->z_angle += (mouse_y - mouse->prev_y) * MOUSE_SCALE;
	camera->z_angle = reset_angles(camera->z_angle);
}

void	rotate_camera_angle_z(int mouse_x, int mouse_y, t_screen *screen)
{
	if (screen->settings->screen_mode == MAIN_SCREEN)
		rotate_angle_z(mouse_x, mouse_y, screen->views->main_view->camera,
			screen->mouse);
	else if (screen->settings->screen_mode == MULTI_SCREEN)
	{
		rotate_angle_z(mouse_x, mouse_y,
			screen->views->multi_view->left_up->camera, screen->mouse);
		rotate_angle_z(mouse_x, mouse_y,
			screen->views->multi_view->right_up->camera, screen->mouse);
		rotate_angle_z(mouse_x, mouse_y,
			screen->views->multi_view->left_down->camera, screen->mouse);
		rotate_angle_z(mouse_x, mouse_y,
			screen->views->multi_view->right_down->camera, screen->mouse);
	}
}
