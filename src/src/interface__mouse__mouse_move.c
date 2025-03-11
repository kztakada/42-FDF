/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface__mouse__mouse_move.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 23:59:55 by katakada          #+#    #+#             */
/*   Updated: 2025/03/12 00:56:42 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	shift_offset_xy(int mouse_x, int mouse_y, t_camera *camera,
		t_mouse *mouse)
{
	camera->x_offset += mouse_x - mouse->prev_x;
	camera->y_offset += mouse_y - mouse->prev_y;
}

static void	shift_camera_offset_xy(int mouse_x, int mouse_y, t_screen *screen)
{
	if (screen->settings->screen_mode == MAIN_SCREEN)
		shift_offset_xy(mouse_x, mouse_y, screen->views->main_view->camera,
			screen->mouse);
	else if (screen->settings->screen_mode == MULTI_SCREEN)
	{
		shift_offset_xy(mouse_x, mouse_y,
			screen->views->multi_view->left_up->camera, screen->mouse);
		shift_offset_xy(mouse_x, mouse_y,
			screen->views->multi_view->right_up->camera, screen->mouse);
		shift_offset_xy(mouse_x, mouse_y,
			screen->views->multi_view->left_down->camera, screen->mouse);
		shift_offset_xy(mouse_x, mouse_y,
			screen->views->multi_view->right_down->camera, screen->mouse);
	}
}

int	mouse_move(int mouse_x, int mouse_y, void *param)
{
	t_screen	*screen;

	screen = (t_screen *)param;
	if (screen->mouse->button == MOUSE_LEFT)
		shift_camera_offset_xy(mouse_x, mouse_y, screen);
	else if (screen->mouse->button == MOUSE_MIDDLE)
		rotate_camera_angle_xy(mouse_x, mouse_y, screen);
	else if (screen->mouse->button == MOUSE_RIGHT)
		rotate_camera_angle_z_by_mouse(mouse_x, mouse_y, screen);
	if (screen->mouse->button == MOUSE_LEFT
		|| screen->mouse->button == MOUSE_RIGHT
		|| screen->mouse->button == MOUSE_MIDDLE)
	{
		screen->mouse->prev_x = mouse_x;
		screen->mouse->prev_y = mouse_y;
	}
	return (0);
}
