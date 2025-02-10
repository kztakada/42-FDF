/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 00:29:45 by katakada          #+#    #+#             */
/*   Updated: 2025/02/10 17:50:30 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	is_included_x_raw_in_fdf(int fdf_x, t_model_fdf *fdf)
{
	int	min_x_raw;

	min_x_raw = 0;
	if (fdf_x <= fdf->max_x_raw && fdf_x >= min_x_raw)
		return (TRUE);
	return (FALSE);
}

static int	is_included_y_raw_in_fdf(int fdf_y, t_model_fdf *fdf)
{
	int	min_y_raw;

	min_y_raw = 0;
	if (fdf_y <= fdf->max_y_raw && fdf_y >= min_y_raw)
		return (TRUE);
	return (FALSE);
}

static int	has_next_x(int fdf_x_raw, t_model_fdf *fdf)
{
	if (fdf_x_raw == fdf->max_x_raw)
		return (FALSE);
	return (TRUE);
}

static int	has_next_y(int fdf_y_raw, t_model_fdf *fdf)
{
	if (fdf_y_raw == fdf->max_y_raw)
		return (FALSE);
	return (TRUE);
}

void	draw_view(t_view *view, t_image *image)
{
	t_vertex_fdf	drawing_start_fdf;
	t_vertex_fdf	raw_only_use;
	int				delta_x_raw;
	int				delta_y_raw;

	drawing_start_fdf = computed_deepest_corner(view);
	delta_x_raw = (drawing_start_fdf.x_raw > 0) * -2 + 1;
	delta_y_raw = (drawing_start_fdf.y_raw > 0) * -2 + 1;
	raw_only_use = drawing_start_fdf;
	while (is_included_y_raw_in_fdf(raw_only_use.y_raw, view->fdf))
	{
		while (is_included_x_raw_in_fdf(raw_only_use.x_raw, view->fdf))
		{
			if (has_next_x(raw_only_use.x_raw, view->fdf))
				draw_line_to_next_x(raw_only_use, view, image);
			if (has_next_y(raw_only_use.y_raw, view->fdf))
				draw_line_to_next_y(raw_only_use, view, image);
			raw_only_use.x_raw += delta_x_raw;
		}
		raw_only_use.x_raw = drawing_start_fdf.x_raw;
		raw_only_use.y_raw += delta_y_raw;
	}
}
