/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_view__draw_line__util.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:47:36 by katakada          #+#    #+#             */
/*   Updated: 2025/02/11 01:45:47 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	swap_int(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	swap_xy_to_less_steep(t_line_on_view *line)
{
	swap_int(&line->start_dot.x, &line->start_dot.y);
	swap_int(&line->end_dot.x, &line->end_dot.y);
}

void	swap_start_end_xyz(t_line_on_view *line)
{
	swap_int(&line->start_dot.x, &line->end_dot.x);
	swap_int(&line->start_dot.y, &line->end_dot.y);
	swap_int(&line->start_dot.z, &line->end_dot.z);
	line->is_reversed = TRUE;
}

void	swap_xy_to_restore_steep(t_anti_aliased_dot *dot)
{
	swap_int(&dot->x, &dot->y);
}

void	calc_yz_gradient(t_line_on_view *line)
{
	float	dy;
	float	dx;
	float	dz;

	dx = (float)(line->end_dot.x - line->start_dot.x);
	dy = (float)(line->end_dot.y - line->start_dot.y);
	dz = (float)(line->end_dot.z - line->start_dot.z);
	if (dx == 0.0f)
	{
		line->y_gradient = 1.f;
		line->z_gradient = 1.f;
	}
	else
	{
		line->y_gradient = dy / dx;
		line->z_gradient = dz / dx;
	}
}
