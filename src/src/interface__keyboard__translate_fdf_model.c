/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface__keyboard__translate_fdf_model.c         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 22:40:18 by katakada          #+#    #+#             */
/*   Updated: 2025/02/12 22:40:52 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	transrate_x_all_multi_view(t_screen *screen, int offset)
{
	screen->views->multi_view->left_up->transrate_x += offset;
	screen->views->multi_view->right_up->transrate_x += offset;
	screen->views->multi_view->left_down->transrate_x += offset;
	screen->views->multi_view->right_down->transrate_x += offset;
}

static void	transrate_y_all_multi_view(t_screen *screen, int offset)
{
	screen->views->multi_view->left_up->transrate_y += offset;
	screen->views->multi_view->right_up->transrate_y += offset;
	screen->views->multi_view->left_down->transrate_y += offset;
	screen->views->multi_view->right_down->transrate_y += offset;
}

void	translate_fdf_model(int keycode, t_screen *screen)
{
	if (screen->settings->screen_mode == MAIN_SCREEN)
	{
		if (keycode == KEY_LEFT)
			screen->views->main_view->transrate_x += 10;
		else if (keycode == KEY_RIGHT)
			screen->views->main_view->transrate_x -= 10;
		else if (keycode == KEY_UP)
			screen->views->main_view->transrate_y += 10;
		else if (keycode == KEY_DOWN)
			screen->views->main_view->transrate_y -= 10;
	}
	else if (screen->settings->screen_mode == MULTI_SCREEN)
	{
		if (keycode == KEY_LEFT)
			transrate_x_all_multi_view(screen, 10);
		else if (keycode == KEY_RIGHT)
			transrate_x_all_multi_view(screen, -10);
		else if (keycode == KEY_UP)
			transrate_y_all_multi_view(screen, 10);
		else if (keycode == KEY_DOWN)
			transrate_y_all_multi_view(screen, -10);
	}
}
