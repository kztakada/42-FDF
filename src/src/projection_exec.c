/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_exec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 01:22:09 by katakada          #+#    #+#             */
/*   Updated: 2025/03/12 01:22:09 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = (y * data->line_length + x * (data->bits_per_pixel / 8));
	dst = data->addr + offset;
	*(unsigned int *)dst = color;
}

static void	put_buckground_color(t_image *image, int color)
{
	int	x;
	int	y;

	x = 0;
	while (x < image->width)
	{
		y = 0;
		while (y < image->height)
		{
			my_mlx_pixel_put(image, x, y, color);
			y++;
		}
		x++;
	}
}

static void	draw_screen(t_screen *screen)
{
	ft_bzero(screen->image->addr, screen->image->width * screen->image->height
		* (screen->image->bits_per_pixel / 8));
	put_buckground_color(screen->image, SCREEN_BG_COLOR);
	if (screen->settings->screen_mode == MAIN_SCREEN)
		draw_view(screen->views->main_view, screen);
	else if (screen->settings->screen_mode == MULTI_SCREEN)
		draw_multi_view(screen->views->multi_view, screen);
}

static void	auto_rotate_camera_angle_z(t_screen *screen)
{
	double	delta;

	if (screen->settings->auto_rotate_z == STOP)
		return ;
	delta = 0;
	if (screen->settings->auto_rotate_z == ROTATE_L)
		delta = +0.01;
	else if (screen->settings->auto_rotate_z == ROTATE_R)
		delta = -0.01;
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

void	projection_exec(t_screen *screen)
{
	auto_rotate_camera_angle_z(screen);
	draw_screen(screen);
	// mlx_string_put(mlx, mlx_win, 100, 100, 0x00FFFF00, "Hello world!");
	mlx_put_image_to_window(screen->mlx, screen->mlx_win, screen->image->img, 0,
		0);
	// draw_instructions(screen);
	// draw_debag(screen);
}
