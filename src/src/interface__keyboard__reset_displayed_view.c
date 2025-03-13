/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface__keyboard__reset_displayed_view.c        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:05:25 by katakada          #+#    #+#             */
/*   Updated: 2025/03/13 17:43:21 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	copy_camera(t_camera *dest, t_camera src)
{
	dest->zoom = src.zoom;
	dest->x_angle = src.x_angle;
	dest->y_angle = src.y_angle;
	dest->z_angle = src.z_angle;
	dest->x_offset = src.x_offset;
	dest->y_offset = src.y_offset;
	dest->z_offset = src.z_offset;
}

static void	reset_view(t_view *view, t_camera preset)
{
	copy_camera(view->camera, preset);
	setup_camera_zoom_to_fit_view_whole(view->camera, view->width, view->height,
		view->fdf);
}

void	reset_displayed_view(t_screen *screen)
{
	screen->settings->is_moved = FALSE;
	if (screen->settings->screen_mode == MAIN_SCREEN)
	{
		if (screen->settings->projection_mode == ISOMETRIC)
			reset_view(screen->views->main_view, get_isometric_camera());
		else if (screen->settings->projection_mode == FRONT_VIEW)
			reset_view(screen->views->main_view, get_front_view_camera());
		else if (screen->settings->projection_mode == TOP_VIEW)
			reset_view(screen->views->main_view, get_top_view_camera());
		else if (screen->settings->projection_mode == SIDE_VIEW)
			reset_view(screen->views->main_view, get_side_view_camera());
	}
	else if (screen->settings->screen_mode == MULTI_SCREEN)
	{
		reset_view(screen->views->multi_view->left_up, get_front_view_camera());
		reset_view(screen->views->multi_view->right_up, get_top_view_camera());
		reset_view(screen->views->multi_view->left_down,
			get_isometric_camera());
		reset_view(screen->views->multi_view->right_down,
			get_side_view_camera());
	}
}
