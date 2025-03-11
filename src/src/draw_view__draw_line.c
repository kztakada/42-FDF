/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_view__draw_line.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:29:15 by katakada          #+#    #+#             */
/*   Updated: 2025/03/11 17:46:47 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_line(t_line_on_view *line, t_view *view, t_image *image)
{
	if (is_out_of_view(line, view) == TRUE)
		return ;
	if (line->is_steep)
		swap_xy_to_less_steep(line);
	if (line->start_dot.x > line->end_dot.x)
		swap_start_end_xyz(line);
	calc_yz_gradient(line);
	draw_dot_line(line, view, image);
}

static void	draw_line_start_to_end(t_vertex_fdf start_raws,
		t_vertex_fdf end_raws, t_view *view, t_screen *screen)
{
	t_vertex_fdf	*start_fdf;
	t_vertex_fdf	*end_fdf;
	t_dot_on_view	start_dot;
	t_dot_on_view	end_dot;
	t_line_on_view	line;

	start_fdf = get_vertex_fdf(start_raws.x_raw, start_raws.y_raw, view->fdf);
	if (start_fdf == NULL)
		forced_error_exit("fdf model data is invalid", __FILE__, __LINE__);
	end_fdf = get_vertex_fdf(end_raws.x_raw, end_raws.y_raw, view->fdf);
	if (end_fdf == NULL)
		forced_error_exit("fdf model data is invalid", __FILE__, __LINE__);
	start_dot = convert_fdf_to_view_dot(*start_fdf, view, screen->z_scale);
	end_dot = convert_fdf_to_view_dot(*end_fdf, view, screen->z_scale);
	line = make_line_on_view(start_dot, end_dot);
	draw_line(&line, view, screen->image);
}

void	draw_line_to_next_x(t_vertex_fdf start_raws, t_view *view,
		t_screen *screen)
{
	t_vertex_fdf	end_raws;

	end_raws = start_raws;
	end_raws.x_raw = start_raws.x_raw + 1;
	draw_line_start_to_end(start_raws, end_raws, view, screen);
}

void	draw_line_to_next_y(t_vertex_fdf start_raws, t_view *view,
		t_screen *screen)
{
	t_vertex_fdf	end_raws;

	end_raws = start_raws;
	end_raws.y_raw = start_raws.y_raw + 1;
	draw_line_start_to_end(start_raws, end_raws, view, screen);
}
