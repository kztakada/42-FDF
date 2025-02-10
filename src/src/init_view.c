/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:54:01 by katakada          #+#    #+#             */
/*   Updated: 2025/02/10 01:26:53 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_camera_zoom_to_fit_view_whole(t_camera *camera, int view_width,
		int view_height, t_model_fdf *fdf)
{
	printf("view_width: %d view_height: %d\n", view_width, view_height);
	printf("fdf->size_x_raw: %d fdf->size_y_raw: %d\n", fdf->size_x_raw,
		fdf->size_y_raw);
	camera->zoom = view_width / fdf->size_x_raw / 2;
	if (camera->zoom > view_height / fdf->size_y_raw / 2)
		camera->zoom = view_height / fdf->size_y_raw / 2;
	if (camera->zoom < 1)
		camera->zoom = 1;
}

t_view	*init_view(int view_width, int view_height, int projection_mode,
		t_model_fdf *fdf)
{
	t_view	*view;

	view = (t_view *)malloc(sizeof(t_view));
	if (!view)
		sys_func_error_exit("malloc failed", __FILE__, __LINE__);
	view->width = view_width;
	view->height = view_height;
	view->z_scale = Z_SCALE_DEFAULT;
	view->camera = init_camera(projection_mode, __FILE__, __LINE__);
	set_camera_zoom_to_fit_view_whole(view->camera, view_width, view_height,
		fdf);
	view->fdf = fdf;
	return (view);
}
