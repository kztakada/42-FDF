/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 00:29:45 by katakada          #+#    #+#             */
/*   Updated: 2025/01/22 01:16:06 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	is_x_included_in_fdf(int fdf_x, t_model_fdf *fdf)
{
	int	min_x_raw;

	min_x_raw = 0;
	if (fdf_x < fdf->max_x_raw && fdf_x >= min_x_raw)
		return (TRUE);
	return (FALSE);
}

static int	is_y_included_in_fdf(int fdf_y, t_model_fdf *fdf)
{
	int	min_y_raw;

	min_y_raw = 0;
	if (fdf_y < fdf->max_y_raw && fdf_y >= min_y_raw)
		return (TRUE);
	return (FALSE);
}

static int	is_end_vertex_x(int fdf_x_raw, t_model_fdf *fdf)
{
	if (fdf_x_raw == fdf->max_x_raw)
		return (TRUE);
	return (FALSE);
}

static int	is_end_vertex_y(int fdf_y_raw, t_model_fdf *fdf)
{
	if (fdf_y_raw == fdf->max_y_raw)
		return (TRUE);
	return (FALSE);
}

void	draw_view(t_view *view, t_image *image)
{
	t_vertex_fdf	drawing_start_fdf;
	t_vertex_fdf	i_fdf;
	int				delta_x_raw;
	int				delta_y_raw;

	drawing_start_fdf = computed_deepest_corner(view);
	delta_x_raw = (drawing_start_fdf.x_raw > 0) * -2 + 1;
	delta_y_raw = (drawing_start_fdf.y_raw > 0) * -2 + 1;
	i_fdf = drawing_start_fdf;
	while (i_fdf.y != NULL && is_y_included_in_fdf(i_fdf.y_raw, view->fdf))
	{
		while (i_fdf.x != NULL && is_x_included_in_fdf(i_fdf.x_raw, view->fdf))
		{
			if (!is_end_vertex_x(i_fdf.x_raw, view->fdf))
				draw_line_to_next_x(i_fdf, view, image);
			if (!is_end_vertex_y(i_fdf.y_raw, view->fdf))
				draw_line_to_next_y(i_fdf, view, image);
			i_fdf = get_vertex_fdf((i_fdf.x_raw + delta_x_raw), i_fdf.y_raw,
					view->fdf);
		}
		i_fdf = get_vertex_fdf(drawing_start_fdf.x_raw, (i_fdf.y_raw
					+ delta_y_raw), view->fdf);
	}
}
