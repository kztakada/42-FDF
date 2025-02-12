/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:16:17 by katakada          #+#    #+#             */
/*   Updated: 2025/02/13 00:30:04 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_camera	get_isometric_camera(void)
{
	t_camera	camera;

	camera.zoom = 0;
	camera.x_angle = 0.955316618;
	camera.y_angle = 0;
	camera.z_angle = 0.785398163;
	camera.x_offset = 0;
	camera.y_offset = 0;
	camera.z_offset = 0;
	return (camera);
}

static t_camera	get_front_view_camera(void)
{
	t_camera	camera;

	camera.zoom = 0;
	camera.x_angle = 1.570796327;
	camera.y_angle = 0;
	camera.z_angle = 0;
	camera.x_offset = 0;
	camera.y_offset = 0;
	camera.z_offset = 0;
	return (camera);
}

static t_camera	get_top_view_camera(void)
{
	t_camera	camera;

	camera.zoom = 0;
	camera.x_angle = 0;
	camera.y_angle = 0;
	camera.z_angle = 0;
	camera.x_offset = 0;
	camera.y_offset = 0;
	camera.z_offset = 0;
	return (camera);
}

static t_camera	get_side_view_camera(void)
{
	t_camera	camera;

	camera.zoom = 0;
	camera.x_angle = 1.570796327;
	camera.y_angle = 0;
	camera.z_angle = 1.570796327;
	camera.x_offset = 0;
	camera.y_offset = 0;
	camera.z_offset = 0;
	return (camera);
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
	camera->z_offset = INT_MAX;
	return (camera);
}
