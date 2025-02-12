/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_view__draw_line__is_out_of_view__util.        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 00:40:17 by katakada          #+#    #+#             */
/*   Updated: 2025/02/13 00:27:13 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_dot_within_view(t_dot_on_view dot, t_view *view)
{
	if (dot.x >= 0 && dot.x < view->width && dot.y >= 0 && dot.y < view->height)
		return (TRUE);
	return (FALSE);
}

static t_dot_on_view	corner_dot(int corner, t_view *view)
{
	t_dot_on_view	corner_dot;

	corner_dot.x = 0;
	corner_dot.y = 0;
	if (corner == LEFT_UP)
		return (corner_dot);
	if (corner == RIGHT_UP)
	{
		corner_dot.x = view->width;
		return (corner_dot);
	}
	if (corner == LEFT_DOWN)
	{
		corner_dot.y = view->height;
		return (corner_dot);
	}
	if (corner == RIGHT_DOWN)
	{
		corner_dot.x = view->width;
		corner_dot.y = view->height;
		return (corner_dot);
	}
	return (corner_dot);
}

static t_line_on_view	get_view_side_line(int side, t_view *view)
{
	t_dot_on_view	left_up;
	t_dot_on_view	right_up;
	t_dot_on_view	left_down;
	t_dot_on_view	right_down;

	left_up = corner_dot(LEFT_UP, view);
	right_up = corner_dot(RIGHT_UP, view);
	left_down = corner_dot(LEFT_DOWN, view);
	right_down = corner_dot(RIGHT_DOWN, view);
	if (side == SIDE_TOP)
		return (make_line_on_view(left_up, right_up));
	if (side == SIDE_BOTTOM)
		return (make_line_on_view(left_down, right_down));
	if (side == SIDE_LEFT)
		return (make_line_on_view(left_up, left_down));
	if (side == SIDE_RIGHT)
		return (make_line_on_view(right_up, right_down));
	return (make_line_on_view(left_up, right_up));
}

static int	are_crossing(t_line_on_view line_a, t_line_on_view line_b)
{
	double	delta1;
	double	delta2;
	double	delta3;
	double	delta4;

	delta1 = (line_b.end_dot.x - line_b.start_dot.x) * (line_a.start_dot.y
			- line_b.start_dot.y) - (line_b.end_dot.y - line_b.start_dot.y)
		* (line_a.start_dot.x - line_b.start_dot.x);
	delta2 = (line_b.end_dot.x - line_b.start_dot.x) * (line_a.end_dot.y
			- line_b.start_dot.y) - (line_b.end_dot.y - line_b.start_dot.y)
		* (line_a.end_dot.x - line_b.start_dot.x);
	delta3 = (line_a.end_dot.x - line_a.start_dot.x) * (line_b.start_dot.y
			- line_a.start_dot.y) - (line_a.end_dot.y - line_a.start_dot.y)
		* (line_b.start_dot.x - line_a.start_dot.x);
	delta4 = (line_a.end_dot.x - line_a.start_dot.x) * (line_b.end_dot.y
			- line_a.start_dot.y) - (line_a.end_dot.y - line_a.start_dot.y)
		* (line_b.end_dot.x - line_a.start_dot.x);
	if (delta1 * delta2 < 0 && delta3 * delta4 < 0)
		return (TRUE);
	return (FALSE);
}

int	is_crossing_view(t_line_on_view the_line, t_view *view)
{
	t_line_on_view	view_side_top;
	t_line_on_view	view_side_bottom;
	t_line_on_view	view_side_left;
	t_line_on_view	view_side_right;

	view_side_top = get_view_side_line(SIDE_TOP, view);
	view_side_bottom = get_view_side_line(SIDE_BOTTOM, view);
	view_side_left = get_view_side_line(SIDE_LEFT, view);
	view_side_right = get_view_side_line(SIDE_RIGHT, view);
	if (are_crossing(the_line, view_side_top) == FALSE)
		return (FALSE);
	if (are_crossing(the_line, view_side_left) == FALSE)
		return (FALSE);
	if (are_crossing(the_line, view_side_right) == FALSE)
		return (FALSE);
	if (are_crossing(the_line, view_side_bottom) == FALSE)
		return (FALSE);
	return (TRUE);
}
