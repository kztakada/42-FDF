/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_view__draw_line__calc_dot_color.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 22:31:48 by katakada          #+#    #+#             */
/*   Updated: 2025/03/14 02:07:49 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_primary_color(int shift_color, int start_color_24bit,
		int end_color_24bit, double mix_ratio)
{
	int	start_color_8bit;
	int	end_color_8bit;
	int	color_range;
	int	primary_color;

	start_color_8bit = (start_color_24bit >> shift_color) & 0xFF;
	end_color_8bit = (end_color_24bit >> shift_color) & 0xFF;
	color_range = end_color_8bit - start_color_8bit;
	if (start_color_8bit == end_color_8bit)
		primary_color = start_color_8bit;
	else
		primary_color = start_color_8bit + (int)(color_range * mix_ratio);
	return (primary_color);
}

int	get_base_color(t_anti_aliased_dot *drawing_dot, t_line_on_view *line)
{
	int				start_color;
	int				end_color;
	double			mix_ratio;
	t_tricromatic	base_color;

	mix_ratio = (float)get_int_abs(drawing_dot->x - line->start_dot.x)
		/ (float)get_int_abs(line->end_dot.x - line->start_dot.x);
	if (line->is_reversed)
	{
		start_color = line->end_dot.color;
		end_color = line->start_dot.color;
	}
	else
	{
		start_color = line->start_dot.color;
		end_color = line->end_dot.color;
	}
	base_color.r = get_primary_color(RED_SHIFT, start_color, end_color,
			mix_ratio);
	base_color.g = get_primary_color(GREEN_SHIFT, start_color, end_color,
			mix_ratio);
	base_color.b = get_primary_color(BLUE_SHIFT, start_color, end_color,
			mix_ratio);
	return ((base_color.r << 16) | (base_color.g << 8) | base_color.b);
}

static int	get_anti_alias_color(int base_color, float anti_alias_ratio)
{
	t_tricromatic	a_a_color;

	a_a_color.r = base_color >> RED_SHIFT & 0xFF;
	a_a_color.g = base_color >> GREEN_SHIFT & 0xFF;
	a_a_color.b = base_color >> BLUE_SHIFT & 0xFF;
	a_a_color.r *= anti_alias_ratio;
	a_a_color.g *= anti_alias_ratio;
	a_a_color.b *= anti_alias_ratio;
	return ((a_a_color.r << 16) | (a_a_color.g << 8) | a_a_color.b);
}

void	calc_anti_alias_dots(t_anti_aliased_dot *drawing_dot,
		t_line_on_view *line)
{
	int		base_color;
	float	top_color_ratio;
	float	bottom_color_ratio;

	drawing_dot->y = (int)drawing_dot->y_f;
	drawing_dot->z = (int)drawing_dot->z_f;
	base_color = get_base_color(drawing_dot, line);
	if (drawing_dot->y_f > 0.f)
		bottom_color_ratio = drawing_dot->y_f - (int)drawing_dot->y_f;
	else
		bottom_color_ratio = drawing_dot->y_f - ((int)drawing_dot->y_f + 1.f);
	top_color_ratio = 1.f - bottom_color_ratio;
	drawing_dot->top_color = get_anti_alias_color(base_color, top_color_ratio);
	drawing_dot->bottom_color = get_anti_alias_color(base_color,
			bottom_color_ratio);
}
