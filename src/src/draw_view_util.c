/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_view_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 00:30:08 by katakada          #+#    #+#             */
/*   Updated: 2025/01/22 00:30:10 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_vertex_fdf	calc_deeper_corner(t_vertex_fdf deepest_temp,
		t_vertex_fdf candidate, t_view *view)
{
	t_dot_of_view	deepest_temp_dot;
	t_dot_of_view	candidate_dot;

	deepest_temp_dot = convert_fdf_to_view(deepest_temp, view);
	candidate_dot = convert_fdf_to_view(candidate, view);
	if (candidate_dot.z < deepest_temp_dot.z)
		return (candidate);
	return (deepest_temp);
}

t_vertex_fdf	computed_deepest_corner(t_view *view)
{
	t_vertex_fdf	left_up;
	t_vertex_fdf	right_up;
	t_vertex_fdf	left_down;
	t_vertex_fdf	right_down;
	t_vertex_fdf	deepest_corner;

	left_up = get_vertex_fdf(0, 0, view->fdf);
	right_up = get_vertex_fdf(view->fdf->max_x_raw, 0, view->fdf);
	left_down = get_vertex_fdf(0, view->fdf->max_y_raw, view->fdf);
	right_down = get_vertex_fdf(view->fdf->max_x_raw, view->fdf->max_y_raw,
			view->fdf);
	deepest_corner = left_up;
	deepest_corner = calc_deeper_corner(deepest_corner, right_up, view);
	deepest_corner = calc_deeper_corner(deepest_corner, left_down, view);
	deepest_corner = calc_deeper_corner(deepest_corner, right_down, view);
	return (deepest_corner);
}
