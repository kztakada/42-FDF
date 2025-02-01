/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util__convert_fdf_to_view_dot.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:58:49 by katakada          #+#    #+#             */
/*   Updated: 2025/02/01 18:58:49 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	calc_default_color(int z, t_model_fdf *fdf)
{
	unsigned int	range;
	double			percentile;

	range = fdf->max_z - fdf->min_z;
	if (range == 0)
		return (COLOR_L0);
	percentile = ((double)(z - fdf->min_z) / range);
	if (percentile < 0.2)
		return (COLOR_L0);
	else if (percentile < 0.4)
		return (COLOR_L1);
	else if (percentile < 0.6)
		return (COLOR_L2);
	else if (percentile < 0.8)
		return (COLOR_L3);
	else
		return (COLOR_L4);
}

static void	rotate_x(int *y, int *z, double x_angle)
{
	int	prev_y;

	prev_y = *y;
	*y = prev_y * cos(x_angle) - *z * sin(x_angle);
	*z = prev_y * sin(x_angle) + *z * cos(x_angle);
}

static void	rotate_y(int *x, int *z, double y_angle)
{
	int	prev_x;

	prev_x = *x;
	*x = prev_x * cos(y_angle) + *z * sin(y_angle);
	*z = prev_x * -sin(y_angle) + *z * cos(y_angle);
}

static void	rotate_z(int *x, int *y, double z_angle)
{
	t_dot_of_view	prev;

	prev.x = *x;
	prev.y = *y;
	*x = prev.x * cos(z_angle) - prev.y * sin(z_angle);
	*y = prev.x * sin(z_angle) + prev.y * cos(z_angle);
}

t_dot_of_view	convert_fdf_to_view_dot(t_vertex_fdf v_fdf, t_view *view)
{
	t_dot_of_view	view_dot;

	view_dot.z = view->fdf->yx_matrix[v_fdf.y_raw][v_fdf.x_raw].z;
	if (view->fdf->yx_matrix[v_fdf.y_raw][v_fdf.x_raw].color >= 0)
		view_dot.color = view->fdf->yx_matrix[v_fdf.y_raw][v_fdf.x_raw].color;
	else
		view_dot.color = calc_default_color(view_dot.z, view->fdf);
	view_dot.x = v_fdf.x * view->camera->zoom;
	view_dot.y = v_fdf.y * view->camera->zoom;
	view_dot.z = view_dot.z * view->camera->zoom * view->fdf->max_z
		/ Z_HEIGHT_RATIO;
	rotate_z(&view_dot.x, &view_dot.y, view->camera->z_angle);
	rotate_y(&view_dot.x, &view_dot.z, view->camera->y_angle);
	rotate_x(&view_dot.y, &view_dot.z, view->camera->x_angle);
	view_dot.x += (view->width / 2) + view->camera->x_offset;
	view_dot.y += (view->height / 2) + view->camera->y_offset;
	return (view_dot);
}
