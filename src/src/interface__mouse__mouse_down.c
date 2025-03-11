/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface__mouse__mouse_down.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 23:45:41 by katakada          #+#    #+#             */
/*   Updated: 2025/03/11 14:00:27 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	shift_zoom(int *zoom, int delta)
{
	*zoom += delta;
	if (*zoom < 1)
		*zoom = 1;
}

static void	shift_camera_zoom(int button, t_screen *screen)
{
	int	delta;

	delta = 0;
	if (button == MOUSE_SCROLL_UP)
		delta = +1;
	else if (button == MOUSE_SCROLL_DOWN)
		delta = -1;
	if (screen->settings->screen_mode == MAIN_SCREEN)
		shift_zoom(&screen->views->main_view->camera->zoom, delta);
	else if (screen->settings->screen_mode == MULTI_SCREEN)
	{
		shift_zoom(&screen->views->multi_view->left_up->camera->zoom, delta);
		shift_zoom(&screen->views->multi_view->right_up->camera->zoom, delta);
		shift_zoom(&screen->views->multi_view->left_down->camera->zoom, delta);
		shift_zoom(&screen->views->multi_view->right_down->camera->zoom, delta);
	}
}

int	mouse_down(int button, int mouse_x, int mouse_y, void *param)
{
	t_screen	*screen;

	screen = (t_screen *)param;
	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
		shift_camera_zoom(button, screen);
	else if (button == MOUSE_LEFT || button == MOUSE_RIGHT
		|| button == MOUSE_MIDDLE)
	{
		screen->mouse->button = button;
		screen->mouse->prev_x = mouse_x;
		screen->mouse->prev_y = mouse_y;
	}
	return (0);
}
