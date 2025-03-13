/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_views.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:46:04 by katakada          #+#    #+#             */
/*   Updated: 2025/03/13 17:44:03 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_view	*init_view(int view_width, int view_height, int projection_mode,
		t_model_fdf *fdf)
{
	t_view	*view;

	view = (t_view *)malloc(sizeof(t_view));
	if (!view)
		sys_func_error_exit("malloc failed", __FILE__, __LINE__);
	view->width = view_width;
	view->height = view_height;
	view->camera = init_camera(projection_mode, __FILE__, __LINE__);
	setup_camera_zoom_to_fit_view_whole(view->camera, view_width, view_height,
		fdf);
	view->fdf = fdf;
	return (view);
}

static void	set_console_offset(t_multi_view *multi_view)
{
	multi_view->left_up->offset_x -= CONSOLE_WIDTH;
	multi_view->right_up->offset_x -= CONSOLE_WIDTH;
	multi_view->left_down->offset_x -= CONSOLE_WIDTH;
	multi_view->right_down->offset_x -= CONSOLE_WIDTH;
}

static t_multi_view	*init_multi_view(t_model_fdf *fdf)
{
	t_multi_view	*multi_view;

	multi_view = (t_multi_view *)malloc(sizeof(t_multi_view));
	if (!multi_view)
		sys_func_error_exit("malloc failed", __FILE__, __LINE__);
	multi_view->left_up = init_view(MULTI_VIEW_WIDTH, MULTI_VIEW_HEIGHT,
			FRONT_VIEW, fdf);
	multi_view->right_up = init_view(MULTI_VIEW_WIDTH, MULTI_VIEW_HEIGHT,
			TOP_VIEW, fdf);
	multi_view->left_down = init_view(MULTI_VIEW_WIDTH, MULTI_VIEW_HEIGHT,
			ISOMETRIC, fdf);
	multi_view->right_down = init_view(MULTI_VIEW_WIDTH, MULTI_VIEW_HEIGHT,
			SIDE_VIEW, fdf);
	set_console_offset(multi_view);
	multi_view->right_up->offset_x -= MULTI_VIEW_WIDTH;
	multi_view->left_down->offset_y -= MULTI_VIEW_HEIGHT;
	multi_view->right_down->offset_x -= MULTI_VIEW_WIDTH;
	multi_view->right_down->offset_y -= MULTI_VIEW_HEIGHT;
	return (multi_view);
}

t_screen_views	*init_screen_views(t_model_fdf *fdf)
{
	t_screen_views	*screen_views;

	screen_views = (t_screen_views *)malloc(sizeof(t_screen_views));
	if (!screen_views)
		sys_func_error_exit("malloc failed", __FILE__, __LINE__);
	screen_views->main_view = init_view(MAIN_VIEW_WIDTH, MAIN_VIEW_HEIGHT,
			ISOMETRIC, fdf);
	screen_views->main_view->offset_x -= CONSOLE_WIDTH;
	screen_views->multi_view = init_multi_view(fdf);
	return (screen_views);
}
