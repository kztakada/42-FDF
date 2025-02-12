/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_screen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 00:28:53 by katakada          #+#    #+#             */
/*   Updated: 2025/02/12 01:56:36 by katakada         ###   ########.fr       */
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
	put_buckground_color(screen->image, 0x040404);
	if (screen->settings->screen_mode == MAIN_SCREEN)
		draw_view(screen->views->main_view, screen->image);
	else if (screen->settings->screen_mode == MULTI_SCREEN)
		draw_multi_view(screen->views->multi_view, screen->image);
}

static void	auto_rote_z(t_screen *screen)
{
	if (screen->settings->screen_mode == MAIN_SCREEN)
	{
		if (screen->settings->auto_rotate_z == ROTATE_L)
			screen->views->main_view->camera->z_angle += 0.01;
		else if (screen->settings->auto_rotate_z == ROTATE_R)
			screen->views->main_view->camera->z_angle -= 0.01;
	}
	else if (screen->settings->screen_mode == MULTI_SCREEN)
	{
		if (screen->settings->auto_rotate_z == ROTATE_L)
		{
			screen->views->multi_view->left_up->camera->z_angle += 0.01;
			screen->views->multi_view->right_up->camera->z_angle += 0.01;
			screen->views->multi_view->left_down->camera->z_angle += 0.01;
			screen->views->multi_view->right_down->camera->z_angle += 0.01;
		}
		else if (screen->settings->auto_rotate_z == ROTATE_R)
		{
			screen->views->multi_view->left_up->camera->z_angle -= 0.01;
			screen->views->multi_view->right_up->camera->z_angle -= 0.01;
			screen->views->multi_view->left_down->camera->z_angle -= 0.01;
			screen->views->multi_view->right_down->camera->z_angle -= 0.01;
		}
	}
}

void	project_screen(t_screen *screen)
{
	auto_rote_z(screen);
	draw_screen(screen);
	// mlx_string_put(mlx, mlx_win, 100, 100, 0x00FFFF00, "Hello world!");
	mlx_put_image_to_window(screen->mlx, screen->mlx_win, screen->image->img, 0,
		0);
	// draw_instructions(screen);
	// draw_debag(screen);
	// mlx_key_hook(mlx_win, key_hook, NULL);
	// mlx_mouse_hook(mlx_win, mouse_hook, NULL);
}
