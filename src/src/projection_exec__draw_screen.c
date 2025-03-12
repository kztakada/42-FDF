/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_exec__draw_screen.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:16:31 by katakada          #+#    #+#             */
/*   Updated: 2025/03/12 20:50:27 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	put_buckground_color(t_image *image, int color)
{
	t_rectangle	rectangle;

	rectangle.width = image->width;
	rectangle.height = image->height;
	rectangle.color = color;
	put_rectangle(image, &rectangle, 0, 0);
}

static void	put_console_color(t_image *image)
{
	t_rectangle	rectangle;

	rectangle.width = CONSOLE_WIDTH;
	rectangle.height = CONSOLE_HEIGHT;
	rectangle.color = CONSOLE_BG;
	put_rectangle(image, &rectangle, 0, 0);
}

static void	put_nameplate_color(t_image *image, int x, int y)
{
	t_rectangle	rectangle;

	rectangle.width = NAMEPLATE_WIDTH;
	rectangle.height = NAMEPLATE_HEIGHT;
	rectangle.color = NAMEPLATE_BG;
	put_rectangle(image, &rectangle, x, y);
}

void	put_multi_view_nameplate_color(t_image *image, t_multi_view *multi_view)
{
	put_nameplate_color(image, v_offset_x(multi_view->left_up),
		v_offset_y(multi_view->left_up));
	put_nameplate_color(image, v_offset_x(multi_view->right_up),
		v_offset_y(multi_view->right_up));
	put_nameplate_color(image, v_offset_x(multi_view->left_down),
		v_offset_y(multi_view->left_down));
	put_nameplate_color(image, v_offset_x(multi_view->right_down),
		v_offset_y(multi_view->right_down));
}

void	draw_screen(t_screen *screen)
{
	ft_bzero(screen->image->addr, screen->image->width * screen->image->height
		* (screen->image->bits_per_pixel / 8));
	put_buckground_color(screen->image, SCREEN_BG);
	put_console_color(screen->image);
	if (screen->settings->screen_mode == MAIN_SCREEN)
	{
		draw_view(screen->views->main_view, screen);
		put_nameplate_color(screen->image, v_offset_x(screen->views->main_view),
			v_offset_y(screen->views->main_view));
	}
	else if (screen->settings->screen_mode == MULTI_SCREEN)
	{
		draw_multi_view(screen->views->multi_view, screen);
		put_multi_view_nameplate_color(screen->image,
			screen->views->multi_view);
	}
}
