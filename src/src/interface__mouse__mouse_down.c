/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface__mouse__mouse_down.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 23:45:41 by katakada          #+#    #+#             */
/*   Updated: 2025/02/12 23:45:41 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	add_zoom(int *zoom, int delta)
{
	*zoom += delta;
	if (*zoom < 1)
		*zoom = 1;
}

static void	alter_camera_zoom(int button, t_screen *screen)
{
	if (screen->settings->screen_mode == MAIN_SCREEN)
	{
		if (button == MOUSE_SCROLL_UP)
			add_zoom(&screen->views->main_view->camera->zoom, +1);
		else if (button == MOUSE_SCROLL_DOWN)
			add_zoom(&screen->views->main_view->camera->zoom, -1);
	}
	else if (screen->settings->screen_mode == MULTI_SCREEN)
	{
		if (button == MOUSE_SCROLL_UP)
		{
			add_zoom(&screen->views->multi_view->left_up->camera->zoom, +1);
			add_zoom(&screen->views->multi_view->right_up->camera->zoom, +1);
			add_zoom(&screen->views->multi_view->left_down->camera->zoom, +1);
			add_zoom(&screen->views->multi_view->right_down->camera->zoom, +1);
		}
		else if (button == MOUSE_SCROLL_DOWN)
		{
			add_zoom(&screen->views->multi_view->left_up->camera->zoom, -1);
			add_zoom(&screen->views->multi_view->right_up->camera->zoom, -1);
			add_zoom(&screen->views->multi_view->left_down->camera->zoom, -1);
			add_zoom(&screen->views->multi_view->right_down->camera->zoom, -1);
		}
	}
}

int	mouse_down(int button, int x, int y, void *param)
{
	t_screen	*screen;

	screen = (t_screen *)param;
	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
		alter_camera_zoom(button, screen);
	else if (button == MOUSE_LEFT || button == MOUSE_RIGHT
		|| button == MOUSE_MIDDLE)
	{
		screen->mouse->button = button;
		screen->mouse->prev_x = x;
		screen->mouse->prev_y = y;
	}
	return (0);
}
