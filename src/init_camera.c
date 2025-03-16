/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:16:17 by katakada          #+#    #+#             */
/*   Updated: 2025/03/14 17:01:23 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	setup_camera_zoom_to_fit_view_whole(t_camera *camera, int view_width,
		int view_height, t_model_fdf *fdf)
{
	if (fdf->size_x_raw == 0 || fdf->size_y_raw == 0)
	{
		camera->zoom = 1;
		return ;
	}
	camera->zoom = view_width / fdf->size_x_raw / 2;
	if (camera->zoom > view_height / fdf->size_y_raw / 2)
		camera->zoom = view_height / fdf->size_y_raw / 2;
	if (camera->zoom < 1)
		camera->zoom = 1;
}

t_camera	*init_camera(int projection_mode, const char *file, int line)
{
	t_camera	*camera;

	camera = (t_camera *)malloc(sizeof(t_camera));
	if (!camera)
		forced_error_exit("malloc failed", file, line);
	if (projection_mode == ISOMETRIC)
		*camera = get_isometric_camera();
	else if (projection_mode == FRONT_VIEW)
		*camera = get_front_view_camera();
	else if (projection_mode == TOP_VIEW)
		*camera = get_top_view_camera();
	else if (projection_mode == SIDE_VIEW)
		*camera = get_side_view_camera();
	else
		forced_error_exit("Invalid projection mode", file, line);
	return (camera);
}
