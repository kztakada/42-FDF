/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_view__util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 00:02:38 by katakada          #+#    #+#             */
/*   Updated: 2025/03/15 13:25:30 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_vertex_fdf	calc_deeper_corner(t_vertex_fdf deepest_temp,
		t_vertex_fdf candidate, t_view *view, int z_scale)
{
	t_dot_on_view	deepest_temp_dot;
	t_dot_on_view	candidate_dot;

	deepest_temp_dot = convert_fdf_to_view_dot(deepest_temp, view, z_scale,
			TRUE);
	candidate_dot = convert_fdf_to_view_dot(candidate, view, z_scale, TRUE);
	if (candidate_dot.z < deepest_temp_dot.z)
		return (candidate);
	return (deepest_temp);
}

t_vertex_fdf	computed_deepest_corner(t_view *view, int z_scale)
{
	t_vertex_fdf	*left_up;
	t_vertex_fdf	*right_up;
	t_vertex_fdf	*left_down;
	t_vertex_fdf	*right_down;
	t_vertex_fdf	deepest_corner;

	left_up = get_vertex_fdf(0, 0, view->fdf);
	right_up = get_vertex_fdf(view->fdf->max_x_raw, 0, view->fdf);
	left_down = get_vertex_fdf(0, view->fdf->max_y_raw, view->fdf);
	right_down = get_vertex_fdf(view->fdf->max_x_raw, view->fdf->max_y_raw,
			view->fdf);
	if (!left_up || !right_up || !left_down || !right_down)
		forced_error_exit("vertex is NULL", __FILE__, __LINE__);
	deepest_corner = *left_up;
	deepest_corner = calc_deeper_corner(deepest_corner, *right_up, view,
			z_scale);
	deepest_corner = calc_deeper_corner(deepest_corner, *left_down, view,
			z_scale);
	deepest_corner = calc_deeper_corner(deepest_corner, *right_down, view,
			z_scale);
	return (deepest_corner);
}

t_line_on_view	make_line_on_view(t_dot_on_view start_dot,
		t_dot_on_view end_dot)
{
	t_line_on_view	line;

	line.start_dot = start_dot;
	line.end_dot = end_dot;
	line.is_steep = (get_int_abs(line.end_dot.y
				- line.start_dot.y) > get_int_abs(line.end_dot.x
				- line.start_dot.x));
	line.is_reversed = FALSE;
	return (line);
}
