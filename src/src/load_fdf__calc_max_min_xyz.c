/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_fdf__calc_max_min_xyz.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 23:49:43 by katakada          #+#    #+#             */
/*   Updated: 2025/01/31 23:50:03 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_model_fdf	calc_max_min_z(t_model_fdf fdf)
{
	int	y;
	int	x;

	fdf.max_z = fdf.yx_matrix[0][0].z;
	fdf.min_z = fdf.yx_matrix[0][0].z;
	y = 0;
	while (y <= fdf.max_y_raw)
	{
		x = 0;
		while (x <= fdf.max_x_raw)
		{
			if (fdf.yx_matrix[y][x].z > fdf.max_z)
				fdf.max_z = fdf.yx_matrix[y][x].z;
			if (fdf.yx_matrix[y][x].z < fdf.min_z)
				fdf.min_z = fdf.yx_matrix[y][x].z;
			x++;
		}
		y++;
	}
	return (fdf);
}

static t_model_fdf	calc_max_min_x(t_model_fdf fdf)
{
	int	y;
	int	x;

	fdf.max_x = fdf.yx_matrix[0][0].x;
	fdf.min_x = fdf.yx_matrix[0][0].x;
	y = 0;
	while (y <= fdf.max_y_raw)
	{
		x = 0;
		while (x <= fdf.max_x_raw)
		{
			if (fdf.yx_matrix[y][x].x > fdf.max_x)
				fdf.max_x = fdf.yx_matrix[y][x].x;
			if (fdf.yx_matrix[y][x].x < fdf.min_x)
				fdf.min_x = fdf.yx_matrix[y][x].x;
			x++;
		}
		y++;
	}
	return (fdf);
}

static t_model_fdf	calc_max_min_y(t_model_fdf fdf)
{
	int	y;
	int	x;

	fdf.max_y = fdf.yx_matrix[0][0].y;
	fdf.min_y = fdf.yx_matrix[0][0].y;
	y = 0;
	while (y <= fdf.max_y_raw)
	{
		x = 0;
		while (x <= fdf.max_x_raw)
		{
			if (fdf.yx_matrix[y][x].y > fdf.max_y)
				fdf.max_y = fdf.yx_matrix[y][x].y;
			if (fdf.yx_matrix[y][x].y < fdf.min_y)
				fdf.min_y = fdf.yx_matrix[y][x].y;
			x++;
		}
		y++;
	}
	return (fdf);
}

t_model_fdf	calc_max_min_xyz(t_model_fdf fdf)
{
	fdf = calc_max_min_z(fdf);
	fdf = calc_max_min_x(fdf);
	fdf = calc_max_min_y(fdf);
}
