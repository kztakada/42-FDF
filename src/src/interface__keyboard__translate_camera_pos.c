/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface__keyboard__translate_camera_pos.c        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 01:03:50 by katakada          #+#    #+#             */
/*   Updated: 2025/02/13 01:18:15 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	transrate_x_all_multi_view(t_screen *screen, int offset)
{
	screen->views->multi_view->left_up->camera->x_offset += offset;
	screen->views->multi_view->right_up->camera->x_offset += offset;
	screen->views->multi_view->left_down->camera->x_offset += offset;
	screen->views->multi_view->right_down->camera->x_offset += offset;
}

static void	transrate_y_all_multi_view(t_screen *screen, int offset)
{
	screen->views->multi_view->left_up->camera->y_offset += offset;
	screen->views->multi_view->right_up->camera->y_offset += offset;
	screen->views->multi_view->left_down->camera->y_offset += offset;
	screen->views->multi_view->right_down->camera->y_offset += offset;
}

void	translate_camera_pos(int keycode, t_screen *screen)
{
	if (screen->settings->screen_mode == MAIN_SCREEN)
	{
		if (keycode == KEY_LEFT)
			screen->views->main_view->camera->x_offset -= 10;
		else if (keycode == KEY_RIGHT)
			screen->views->main_view->camera->x_offset += 10;
		else if (keycode == KEY_UP)
			screen->views->main_view->camera->y_offset -= 10;
		else if (keycode == KEY_DOWN)
			screen->views->main_view->camera->y_offset += 10;
	}
	else if (screen->settings->screen_mode == MULTI_SCREEN)
	{
		if (keycode == KEY_LEFT)
			transrate_x_all_multi_view(screen, -10);
		else if (keycode == KEY_RIGHT)
			transrate_x_all_multi_view(screen, 10);
		else if (keycode == KEY_UP)
			transrate_y_all_multi_view(screen, -10);
		else if (keycode == KEY_DOWN)
			transrate_y_all_multi_view(screen, 10);
	}
}
