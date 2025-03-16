/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera__camera_assets.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:35:29 by katakada          #+#    #+#             */
/*   Updated: 2025/03/14 01:45:05 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//	Use constants to reduce calculation processing
//	acos(1 / sqrt(3)) = 0.955316618
//	45 * M_PI / 180 = 0.785398163
t_camera	get_isometric_camera(void)
{
	t_camera	camera;

	camera.zoom = 0;
	camera.x_angle = 0.955316618;
	camera.y_angle = 0;
	camera.z_angle = 0.785398163;
	camera.x_offset = 0;
	camera.y_offset = 0;
	return (camera);
}

//	Use constants to reduce calculation processing
//	90 * M_PI / 180 = 1.570796327
t_camera	get_front_view_camera(void)
{
	t_camera	camera;

	camera.zoom = 0;
	camera.x_angle = 1.570796327;
	camera.y_angle = 0;
	camera.z_angle = 0;
	camera.x_offset = 0;
	camera.y_offset = 0;
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
	return (camera);
}

//	Use constants to reduce calculation processing
//	90 * M_PI / 180 = 1.570796327
t_camera	get_side_view_camera(void)
{
	t_camera	camera;

	camera.zoom = 0;
	camera.x_angle = 1.570796327;
	camera.y_angle = 0;
	camera.z_angle = 1.570796327;
	camera.x_offset = 0;
	camera.y_offset = 0;
	return (camera);
}
