/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_view__draw_line.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 00:00:03 by katakada          #+#    #+#             */
/*   Updated: 2025/02/02 03:16:37 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_line_dot(t_dot_on_view line_dot, t_line_on_view *line,
		t_view *view, t_image *image)
{
	int	x;
	int	y;
	int	anti_alias_x;
	int	anti_alias_y;

	if (line->is_steep)
	{
		x = line_dot.y - view->offset_x;
		y = line_dot.x - view->offset_y;
		anti_alias_x = line_dot.anti_alias_y - view->offset_x;
		anti_alias_y = line_dot.x - view->offset_y;
	}
	else
	{
		x = line_dot.x - view->offset_x;
		y = line_dot.y - view->offset_y;
		anti_alias_x = line_dot.x - view->offset_x;
		anti_alias_y = line_dot.anti_alias_y - view->offset_y;
	}
	put_pixel_to_image(x, y, line_dot.color, image);
	put_pixel_to_image(anti_alias_x, anti_alias_y, line_dot.anti_alias_color,
		image);
}

float	ft_fpart(float n)
{
	if (n > 0.f)
		return (n - (int)n);
	return (n - ((int)n + 1.f));
}

float	ft_rfpart(float n)
{
	return (1.f - ft_fpart(n));
}

static void	draw_line(t_line_on_view *line, t_view *view, t_image *image)
{
	t_dot_on_view	line_dot;

	if (is_out_of_view(line, view) == TRUE)
		return ;
	if (line->is_steep)
		swap_xy_to_less_steep(line);
	calc_yz_gradient(line);
	line_dot.y_f = (float)line->start_dot.y;
	line_dot.z_f = (float)line->start_dot.z;
	line_dot.x = line->start_dot.x;
	while (line_dot.x <= line->end_dot.x)
	{
		if (line_dot.z_f < view->camera->z_offset)
		{
			line_dot.y = (int)line_dot.y_f;
			line_dot.color = ft_get_color(line_dot.x, ft_rfpart(line_dot.y_f),
					line);
			line_dot.anti_alias_y = (int)line_dot.y_f + 1;
			line_dot.anti_alias_color = ft_get_color(line_dot.x,
					ft_fpart(line_dot.y_f), line);
			draw_line_dot(line_dot, line, view, image);
		}
		line_dot.y_f += line->y_gradient;
		line_dot.z_f += line->z_gradient;
		line_dot.x++;
	}
}

void	draw_line_to_next_x(t_vertex_fdf s_fdf, t_view *view, t_image *image)
{
	t_dot_on_view	start_dot;
	int				next_x_raw;
	t_vertex_fdf	*end_fdf;
	t_dot_on_view	end_dot;
	t_line_on_view	line;

	start_dot = convert_fdf_to_view_dot(s_fdf, view);
	next_x_raw = s_fdf.x_raw + 1;
	end_fdf = get_vertex_fdf(next_x_raw, s_fdf.y_raw, view->fdf);
	if (end_fdf == NULL)
		forced_error_exit("fdf model data is invalid", __FILE__, __LINE__);
	end_dot = convert_fdf_to_view_dot(*end_fdf, view);
	line = make_line_on_view(start_dot, end_dot);
	draw_line(&line, view, image);
}

void	draw_line_to_next_y(t_vertex_fdf s_fdf, t_view *view, t_image *image)
{
	t_dot_on_view	start_dot;
	int				next_y_raw;
	t_vertex_fdf	*end_fdf;
	t_dot_on_view	end_dot;
	t_line_on_view	line;

	start_dot = convert_fdf_to_view_dot(s_fdf, view);
	next_y_raw = s_fdf.y_raw + 1;
	end_fdf = get_vertex_fdf(s_fdf.x_raw, next_y_raw, view->fdf);
	if (end_fdf == NULL)
		forced_error_exit("fdf model data is invalid", __FILE__, __LINE__);
	end_dot = convert_fdf_to_view_dot(*end_fdf, view);
	line = make_line_on_view(start_dot, end_dot);
	draw_line(&line, view, image);
}
