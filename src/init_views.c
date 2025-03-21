/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_views.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:46:04 by katakada          #+#    #+#             */
/*   Updated: 2025/03/16 16:32:03 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_view	*init_view(int view_width, int view_height, int projection_mode,
		t_model_fdf *fdf)
{
	t_view	*view;

	view = (t_view *)ft_calloc(1, sizeof(t_view));
	if (!view)
		sys_func_error_exit("malloc failed", __FILE__, __LINE__);
	view->width = view_width;
	view->height = view_height;
	view->offset_x = 0;
	view->offset_y = 0;
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
	int				multi_view_width;
	int				multi_view_height;

	multi_view_width = (SCREEN_WIDTH - CONSOLE_WIDTH) / 2;
	multi_view_height = SCREEN_HEIGHT / 2;
	multi_view = (t_multi_view *)malloc(sizeof(t_multi_view));
	if (!multi_view)
		sys_func_error_exit("malloc failed", __FILE__, __LINE__);
	multi_view->left_up = init_view(multi_view_width, multi_view_height,
			FRONT_VIEW, fdf);
	multi_view->right_up = init_view(multi_view_width, multi_view_height,
			TOP_VIEW, fdf);
	multi_view->left_down = init_view(multi_view_width, multi_view_height,
			ISOMETRIC, fdf);
	multi_view->right_down = init_view(multi_view_width, multi_view_height,
			SIDE_VIEW, fdf);
	set_console_offset(multi_view);
	multi_view->right_up->offset_x -= multi_view_width;
	multi_view->left_down->offset_y -= multi_view_height;
	multi_view->right_down->offset_x -= multi_view_width;
	multi_view->right_down->offset_y -= multi_view_height;
	return (multi_view);
}

t_screen_views	*init_screen_views(t_model_fdf *fdf)
{
	t_screen_views	*screen_views;
	int				main_view_width;

	main_view_width = SCREEN_WIDTH - CONSOLE_WIDTH;
	screen_views = (t_screen_views *)malloc(sizeof(t_screen_views));
	if (!screen_views)
		sys_func_error_exit("malloc failed", __FILE__, __LINE__);
	screen_views->main_view = init_view(main_view_width, SCREEN_HEIGHT,
			ISOMETRIC, fdf);
	screen_views->main_view->offset_x -= CONSOLE_WIDTH;
	screen_views->multi_view = init_multi_view(fdf);
	return (screen_views);
}
