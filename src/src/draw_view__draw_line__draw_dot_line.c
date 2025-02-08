/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_view__draw_line__draw_dot_line.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:27:36 by katakada          #+#    #+#             */
/*   Updated: 2025/02/09 01:03:18 by katakada         ###   ########.fr       */
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

static void	draw_dot(t_dot_on_view dot_line, t_line_on_view *line, t_view *view,
		t_image *image)
{
	int	x;
	int	y;
	int	anti_alias_x;
	int	anti_alias_y;

	if (line->is_steep)
	{
		x = dot_line.y - view->offset_x;
		y = dot_line.x - view->offset_y;
		anti_alias_x = dot_line.anti_alias_y - view->offset_x;
		anti_alias_y = dot_line.x - view->offset_y;
	}
	else
	{
		x = dot_line.x - view->offset_x;
		y = dot_line.y - view->offset_y;
		anti_alias_x = dot_line.x - view->offset_x;
		anti_alias_y = dot_line.anti_alias_y - view->offset_y;
	}
	put_pixel_to_image(x, y, dot_line.color, image);
	put_pixel_to_image(anti_alias_x, anti_alias_y, dot_line.anti_alias_color,
		image);
}

static float	ft_fpart(float n)
{
	if (n > 0.f)
		return (n - (int)n);
	return (n - ((int)n + 1.f));
}

static float	ft_rfpart(float n)
{
	return (1.f - ft_fpart(n));
}

void	draw_dot_line(t_line_on_view *line, t_view *view, t_image *image)
{
	t_dot_on_view	dot_line;

	dot_line.y_f = (float)line->start_dot.y;
	dot_line.z_f = (float)line->start_dot.z;
	dot_line.x = line->start_dot.x;
	while (dot_line.x <= line->end_dot.x)
	{
		if (dot_line.z_f < view->camera->z_offset)
		{
			dot_line.y = (int)dot_line.y_f;
			dot_line.color = ft_get_color(dot_line.x, ft_rfpart(dot_line.y_f),
					line);
			dot_line.anti_alias_y = (int)dot_line.y_f + 1;
			dot_line.anti_alias_color = ft_get_color(dot_line.x,
					ft_fpart(dot_line.y_f), line);
			draw_dot(dot_line, line, view, image);
		}
		dot_line.y_f += line->y_gradient;
		dot_line.z_f += line->z_gradient;
		dot_line.x++;
	}
}
