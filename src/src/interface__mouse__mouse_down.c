/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface__mouse__mouse_down.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 23:45:41 by katakada          #+#    #+#             */
/*   Updated: 2025/03/13 15:38:17 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	shift_zoom(int *zoom, int delta)
{
	*zoom += delta;
	if (*zoom < 1)
		*zoom = 1;
}

static void	shift_camera_zoom(int button, t_screen *screen)
{
	int	delta;

	delta = 0;
	if (button == MOUSE_SCROLL_UP)
		delta = +1;
	else if (button == MOUSE_SCROLL_DOWN)
		delta = -1;
	if (screen->settings->screen_mode == MAIN_SCREEN)
		shift_zoom(&screen->views->main_view->camera->zoom, delta);
	else if (screen->settings->screen_mode == MULTI_SCREEN)
	{
		shift_zoom(&screen->views->multi_view->left_up->camera->zoom, delta);
		shift_zoom(&screen->views->multi_view->right_up->camera->zoom, delta);
		shift_zoom(&screen->views->multi_view->left_down->camera->zoom, delta);
		shift_zoom(&screen->views->multi_view->right_down->camera->zoom, delta);
	}
}

void	switch_main_view_projection(t_screen *screen, int dest_projection)
{
	t_camera	*prev_camera;

	prev_camera = screen->views->main_view->camera;
	if (dest_projection == ISOMETRIC)
		screen->views->main_view->camera = init_camera(ISOMETRIC, __FILE__,
				__LINE__);
	else if (dest_projection == FRONT_VIEW)
		screen->views->main_view->camera = init_camera(FRONT_VIEW, __FILE__,
				__LINE__);
	else if (dest_projection == TOP_VIEW)
		screen->views->main_view->camera = init_camera(TOP_VIEW, __FILE__,
				__LINE__);
	else if (dest_projection == SIDE_VIEW)
		screen->views->main_view->camera = init_camera(SIDE_VIEW, __FILE__,
				__LINE__);
	setup_camera_zoom_to_fit_view_whole(screen->views->main_view->camera,
		screen->views->main_view->width, screen->views->main_view->height,
		screen->views->main_view->fdf);
	free(prev_camera);
	screen->settings->projection_mode = dest_projection;
	screen->settings->screen_mode = MAIN_SCREEN;
}

static void	select_area_for_switch_projection(t_screen *screen, int mouse_x,
		int mouse_y)
{
	if (mouse_x <= v_offset_x(screen->views->main_view))
		return ;
	if (mouse_x < screen->views->main_view->width / 2
		+ v_offset_x(screen->views->main_view))
	{
		if (mouse_y < screen->views->main_view->height / 2)
			switch_main_view_projection(screen, FRONT_VIEW);
		else
			switch_main_view_projection(screen, ISOMETRIC);
	}
	else if (mouse_x >= screen->views->main_view->width / 2
		+ v_offset_x(screen->views->main_view))
	{
		if (mouse_y < screen->views->main_view->height / 2)
			switch_main_view_projection(screen, TOP_VIEW);
		else
			switch_main_view_projection(screen, SIDE_VIEW);
	}
}

int	mouse_down(int button, int mouse_x, int mouse_y, void *param)
{
	t_screen	*screen;

	screen = (t_screen *)param;
	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
		shift_camera_zoom(button, screen);
	if (screen->settings->screen_mode == MAIN_SCREEN
		|| screen->settings->is_debug == TRUE)
	{
		if (button == MOUSE_LEFT || button == MOUSE_RIGHT
			|| button == MOUSE_MIDDLE)
		{
			screen->mouse->button = button;
			screen->mouse->prev_x = mouse_x;
			screen->mouse->prev_y = mouse_y;
		}
	}
	else if (screen->settings->screen_mode == MULTI_SCREEN)
	{
		if (button == MOUSE_LEFT)
			select_area_for_switch_projection(screen, mouse_x, mouse_y);
	}
	return (0);
}
