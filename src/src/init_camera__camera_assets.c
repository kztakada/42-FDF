/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera__camera_assets.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:35:29 by katakada          #+#    #+#             */
/*   Updated: 2025/03/11 16:35:30 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_camera	get_isometric_camera(void)
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

t_camera	get_front_view_camera(void)
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

t_camera	get_top_view_camera(void)
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

t_camera	get_side_view_camera(void)
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
