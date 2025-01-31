/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:47:36 by katakada          #+#    #+#             */
/*   Updated: 2025/01/21 16:47:38 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel_to_image(int x, int y, int color, t_image *image)
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

t_line_spec	reflect_line_to_smooth(t_dot_of_view *start, t_dot_of_view *end)
{
	t_line_spec	line;

	line.is_steep = ft_abs(end->y - start->y) > ft_abs(end->x - start->x);
	if (line.is_steep)
	{
		ft_swap(&start->x, &start->y);
		ft_swap(&end->x, &end->y);
	}
	if (start->x > end->x)
	{
		ft_swap(&start->x, &end->x);
		ft_swap(&start->y, &end->y);
		ft_swap(&start->z, &end->z);
		line.is_in_reverse = TRUE;
	}
	else
		line.is_in_reverse = FALSE;
	return (line);
}

static int	is_crossing(t_dot_of_view start, t_dot_of_view end,
		t_dot_of_view left_up, t_dot_of_view right_up)
{
	double	delta1;
	double	delta2;
	double	delta3;
	double	delta4;

	delta1 = (right_up.x - left_up.x) * (start.y - left_up.y) - (right_up.y
			- left_up.y) * (start.x - left_up.x);
	delta2 = (right_up.x - left_up.x) * (end.y - left_up.y) - (right_up.y
			- left_up.y) * (end.x - left_up.x);
	delta3 = (end.x - start.x) * (left_up.y - start.y) - (end.y - start.y)
		* (left_up.x - start.x);
	delta4 = (end.x - start.x) * (right_up.y - start.y) - (end.y - start.y)
		* (right_up.x - start.x);
	if (delta1 * delta2 < 0 && delta3 * delta4 < 0)
		return (TRUE);
	return (FALSE);
}

static t_dot_of_view	corner_dot(int corner, t_view *view)
{
	t_dot_of_view	corner_dot;

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

int	is_out_of_screen(t_dot_of_view start, t_dot_of_view end, t_view *view)
{
	t_dot_of_view	left_up;
	t_dot_of_view	right_up;
	t_dot_of_view	left_down;
	t_dot_of_view	right_down;

	left_up = corner_dot(LEFT_UP, view);
	right_up = corner_dot(RIGHT_UP, view);
	left_down = corner_dot(LEFT_DOWN, view);
	right_down = corner_dot(RIGHT_DOWN, view);
	if (start.x >= 0 && start.x < view->width && start.y >= 0
		&& start.y < view->height)
		return (FALSE);
	if (end.x >= 0 && end.x < view->width && end.y >= 0 && end.y < view->height)
		return (FALSE);
	if (is_crossing(start, end, left_up, right_up) == FALSE)
		return (FALSE);
	if (is_crossing(start, end, left_up, left_down) == FALSE)
		return (FALSE);
	if (is_crossing(start, end, right_up, right_down) == FALSE)
		return (FALSE);
	if (is_crossing(start, end, left_down, right_down) == FALSE)
		return (FALSE);
	return (TRUE);
}
