/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_view__draw_line__calc_dot_color.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 22:31:48 by katakada          #+#    #+#             */
/*   Updated: 2025/03/15 16:56:07 by katakada         ###   ########.fr       */
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

static t_tricromatic	get_base_color(t_anti_aliased_dot *drawing_dot,
		t_line_on_view *line)
{
	int				start_color;
	int				end_color;
	double			mix_ratio;
	t_tricromatic	b_color;

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
	b_color.r = get_primary_color(RED_SHIFT, start_color, end_color, mix_ratio);
	b_color.g = get_primary_color(GREEN_SHIFT, start_color, end_color,
			mix_ratio);
	b_color.b = get_primary_color(BLUE_SHIFT, start_color, end_color,
			mix_ratio);
	b_color.hex = ((b_color.r << 16) | (b_color.g << 8) | b_color.b);
	return (b_color);
}

static int	get_anti_alias_color(t_tricromatic base_color)
{
	t_tricromatic	a_a_color;

	a_a_color.r = base_color.r * BLEND + SCREEN_BG_R * (1 - BLEND);
	a_a_color.g = base_color.g * BLEND + SCREEN_BG_G * (1 - BLEND);
	a_a_color.b = base_color.b * BLEND + SCREEN_BG_B * (1 - BLEND);
	return ((a_a_color.r << 16) | (a_a_color.g << 8) | a_a_color.b);
}

static void	calc_antiailiased_color(t_anti_aliased_dot *drawing_dot,
		t_tricromatic base_color)
{
	float	top_occupied_ratio;
	float	bottom_occupied_ratio;

	if (drawing_dot->y_f > 0.f)
		bottom_occupied_ratio = drawing_dot->y_f - (int)drawing_dot->y_f;
	else
		bottom_occupied_ratio = drawing_dot->y_f - ((int)drawing_dot->y_f
				+ 1.f);
	top_occupied_ratio = 1.f - bottom_occupied_ratio;
	if (top_occupied_ratio >= bottom_occupied_ratio)
	{
		drawing_dot->top_color = base_color.hex;
		drawing_dot->bottom_color = get_anti_alias_color(base_color);
	}
	else
	{
		drawing_dot->top_color = get_anti_alias_color(base_color);
		drawing_dot->bottom_color = base_color.hex;
	}
}

void	calc_dot_color(t_anti_aliased_dot *drawing_dot, t_line_on_view *line,
		int is_antialiasing)
{
	t_tricromatic	base_color;

	drawing_dot->y = (int)drawing_dot->y_f;
	drawing_dot->z = (int)drawing_dot->z_f;
	base_color = get_base_color(drawing_dot, line);
	drawing_dot->base_color = base_color.hex;
	if (!is_antialiasing)
		return ;
	calc_antiailiased_color(drawing_dot, base_color);
}
