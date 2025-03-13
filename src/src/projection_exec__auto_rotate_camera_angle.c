/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_exec__auto_rotate_camera_angle.c        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 22:18:41 by katakada          #+#    #+#             */
/*   Updated: 2025/03/13 22:19:37 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	get_rotate_degree(int auto_rotate_state)
{
	if (auto_rotate_state == STOP)
		return (0);
	else if (auto_rotate_state == ROTATE_L)
		return (+0.01);
	else if (auto_rotate_state == ROTATE_R)
		return (-0.01);
	return (0);
}

static void	auto_rotate_camera_angle_x(t_screen *screen)
{
	double	delta;

	delta = get_rotate_degree(screen->settings->auto_rotate_x);
	if (delta == 0)
		return ;
	if (screen->settings->screen_mode == MAIN_SCREEN)
		rotate_angle(&screen->views->main_view->camera->x_angle, delta);
	else if (screen->settings->screen_mode == MULTI_SCREEN)
	{
		rotate_angle(&screen->views->multi_view->left_up->camera->x_angle,
			delta);
		rotate_angle(&screen->views->multi_view->right_up->camera->x_angle,
			delta);
		rotate_angle(&screen->views->multi_view->left_down->camera->x_angle,
			delta);
		rotate_angle(&screen->views->multi_view->right_down->camera->x_angle,
			delta);
	}
}

static void	auto_rotate_camera_angle_y(t_screen *screen)
{
	double	delta;

	delta = get_rotate_degree(screen->settings->auto_rotate_y);
	if (delta == 0)
		return ;
	if (screen->settings->screen_mode == MAIN_SCREEN)
		rotate_angle(&screen->views->main_view->camera->y_angle, delta);
	else if (screen->settings->screen_mode == MULTI_SCREEN)
	{
		rotate_angle(&screen->views->multi_view->left_up->camera->y_angle,
			delta);
		rotate_angle(&screen->views->multi_view->right_up->camera->y_angle,
			delta);
		rotate_angle(&screen->views->multi_view->left_down->camera->y_angle,
			delta);
		rotate_angle(&screen->views->multi_view->right_down->camera->y_angle,
			delta);
	}
}

static void	auto_rotate_camera_angle_z(t_screen *screen)
{
	double	delta;

	delta = get_rotate_degree(screen->settings->auto_rotate_z);
	if (delta == 0)
		return ;
	if (screen->settings->screen_mode == MAIN_SCREEN)
		rotate_angle(&screen->views->main_view->camera->z_angle, delta);
	else if (screen->settings->screen_mode == MULTI_SCREEN)
	{
		rotate_angle(&screen->views->multi_view->left_up->camera->z_angle,
			delta);
		rotate_angle(&screen->views->multi_view->right_up->camera->z_angle,
			delta);
		rotate_angle(&screen->views->multi_view->left_down->camera->z_angle,
			delta);
		rotate_angle(&screen->views->multi_view->right_down->camera->z_angle,
			delta);
	}
}

void	auto_rotate_camera_angle(t_screen *screen)
{
	auto_rotate_camera_angle_x(screen);
	auto_rotate_camera_angle_y(screen);
	auto_rotate_camera_angle_z(screen);
}
