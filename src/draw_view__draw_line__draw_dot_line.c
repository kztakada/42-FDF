/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_view__draw_line__draw_dot_line.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:27:36 by katakada          #+#    #+#             */
/*   Updated: 2025/03/15 16:45:39 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	put_pixel_to_image(int x, int y, int color, t_image *image)
{
	int	i;

	if (x >= 2 && x < image->width && y >= 2 && y < image->height)
	{
		i = (x * image->bits_per_pixel / 8) + (y * image->line_length);
		image->addr[i] = color;
		image->addr[++i] = color >> 8;
		image->addr[++i] = color >> 16;
	}
}

static int	is_within_view(t_anti_aliased_dot drawing_dot, t_view *view)
{
	if (drawing_dot.x <= 2 || drawing_dot.x >= view->width)
		return (FALSE);
	if (drawing_dot.y <= 2 || drawing_dot.y >= view->height)
		return (FALSE);
	return (TRUE);
}

static void	draw_antialiasing_dot(t_anti_aliased_dot drawing_dot,
		t_line_on_view *line, t_view *view, t_image *image)
{
	int	extended_dot_x;
	int	extended_dot_y;

	if (line->is_steep)
	{
		swap_xy_to_restore_steep(&drawing_dot);
		extended_dot_x = drawing_dot.x + 1;
		extended_dot_y = drawing_dot.y;
	}
	else
	{
		extended_dot_x = drawing_dot.x;
		extended_dot_y = drawing_dot.y + 1;
	}
	if (!is_within_view(drawing_dot, view))
		return ;
	drawing_dot.x = drawing_dot.x - view->offset_x;
	drawing_dot.y = drawing_dot.y - view->offset_y;
	extended_dot_x = extended_dot_x - view->offset_x;
	extended_dot_y = extended_dot_y - view->offset_y;
	put_pixel_to_image(drawing_dot.x, drawing_dot.y, drawing_dot.top_color,
		image);
	put_pixel_to_image(extended_dot_x, extended_dot_y, drawing_dot.bottom_color,
		image);
}

static void	draw_one_dot(t_anti_aliased_dot drawing_dot, t_line_on_view *line,
		t_view *view, t_image *image)
{
	if (line->is_steep)
		swap_xy_to_restore_steep(&drawing_dot);
	if (!is_within_view(drawing_dot, view))
		return ;
	drawing_dot.x = drawing_dot.x - view->offset_x;
	drawing_dot.y = drawing_dot.y - view->offset_y;
	put_pixel_to_image(drawing_dot.x, drawing_dot.y, drawing_dot.base_color,
		image);
}

void	draw_dot_line(t_line_on_view *line, t_view *view, t_screen *screen)
{
	t_anti_aliased_dot	drawing_dot;

	drawing_dot.y_f = (float)line->start_dot.y;
	drawing_dot.z_f = (float)line->start_dot.z;
	drawing_dot.x = line->start_dot.x;
	while (drawing_dot.x <= line->end_dot.x)
	{
		calc_dot_color(&drawing_dot, line, screen->settings->is_anti_aliasing);
		if (screen->settings->is_anti_aliasing)
			draw_antialiasing_dot(drawing_dot, line, view, screen->image);
		else
			draw_one_dot(drawing_dot, line, view, screen->image);
		drawing_dot.y_f += line->y_gradient;
		drawing_dot.z_f += line->z_gradient;
		drawing_dot.x++;
	}
}
