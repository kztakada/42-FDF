/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_view__draw_line.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 00:00:03 by katakada          #+#    #+#             */
/*   Updated: 2025/02/01 18:57:57 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_line_spec	make_drawing_line(t_dot_of_view *start, t_dot_of_view *end)
{
	t_line_spec	line;
	float		dy;
	float		dx;
	float		dz;

	line = reflect_line_to_smooth(start, end);
	dx = (float)(end->x - start->x);
	dy = (float)(end->y - start->y);
	dz = (float)(end->z - start->z);
	if (dx == 0.0f)
	{
		line.y_gradient = 1.f;
		line.z_gradient = 1.f;
	}
	else
	{
		line.y_gradient = dy / dx;
		line.z_gradient = dz / dx;
	}
	return (line);
}

static void	unreflect_and_draw_dot(t_dot_of_view dot, t_line_spec line,
		t_view *view, t_image *image)
{
	if (line.is_steep)
	{
		put_pixel_to_image((dot.y - view->offset_x), (dot.x - view->offset_y),
			dot.color, image);
		put_pixel_to_image((dot.anti_alias_y - view->offset_x), (dot.x
				- view->offset_y), dot.anti_alias_color, image);
	}
	else
	{
		put_pixel_to_image((dot.x - view->offset_x), (dot.y - view->offset_y),
			dot.color, image);
		put_pixel_to_image((dot.x - view->offset_x), (dot.anti_alias_y
				- view->offset_y), dot.anti_alias_color, image);
	}
}

static void	draw_line(t_dot_of_view start, t_dot_of_view end, t_view *view,
		t_image *image)
{
	t_line_spec		line;
	t_dot_of_view	i_dot;

	if (is_out_of_screen(start, end, view) == TRUE)
		return ;
	line = make_drawing_line(&start, &end);
	i_dot.y_f = (float)start.y;
	i_dot.z_f = (float)start.z;
	i_dot.x = start.x;
	while (i_dot.x <= end.x)
	{
		if (i_dot.z_f < view->camera->z_offset)
		{
			i_dot.y = (int)i_dot.y_f;
			i_dot.color = ft_get_color(i_dot.x, start, end,
					ft_rfpart(i_dot.y_f));
			i_dot.anti_alias_y = (int)i_dot.y_f + 1;
			i_dot.anti_alias_color = ft_get_color(i_dot.x, start, end,
					ft_fpart(i_dot.y_f));
			unreflect_and_draw_dot(i_dot, line, view, image);
		}
		i_dot.y_f += line.y_gradient;
		i_dot.z_f += line.z_gradient;
		i_dot.x++;
	}
}

void	draw_line_to_next_x(t_vertex_fdf s_fdf, t_view *view, t_image *image)
{
	t_dot_of_view	start_dot;
	int				next_x_raw;
	t_vertex_fdf	*end_fdf;
	t_dot_of_view	end_dot;

	start_dot = convert_fdf_to_view_dot(s_fdf, view);
	next_x_raw = s_fdf.x_raw + 1;
	end_fdf = get_vertex_fdf(next_x_raw, s_fdf.y_raw, view->fdf);
	if (end_fdf == NULL)
		forced_error_exit("fdf model data is invalid", __FILE__, __LINE__);
	end_dot = convert_fdf_to_view_dot(*end_fdf, view);
	draw_line(start_dot, end_dot, view, image);
}

void	draw_line_to_next_y(t_vertex_fdf s_fdf, t_view *view, t_image *image)
{
	t_dot_of_view	start;
	t_vertex_fdf	*end_fdf;
	t_dot_of_view	end;

	start = convert_fdf_to_view_dot(s_fdf, view);
	end_fdf = get_vertex_fdf(s_fdf.x_raw, s_fdf.y_raw + 1, view->fdf);
	if (end_fdf == NULL)
		forced_error_exit("fdf model data is invalid", __FILE__, __LINE__);
	end = convert_fdf_to_view_dot(*end_fdf, view);
	draw_line(start, end, view, image);
}
