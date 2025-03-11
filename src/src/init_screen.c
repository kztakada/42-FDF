/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:33:31 by katakada          #+#    #+#             */
/*   Updated: 2025/03/11 15:03:08 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_image	*init_image(void *mlx_ptr, int img_width, int img_height)
{
	t_image	*image;

	image = (t_image *)malloc(sizeof(t_image));
	if (!image)
		sys_func_error_exit("malloc failed", __FILE__, __LINE__);
	image->img = mlx_new_image(mlx_ptr, img_width, img_height);
	if (!image->img)
		sys_func_error_exit("mlx_new_image failed", __FILE__, __LINE__);
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel,
			&image->line_length, &image->endian);
	if (!image->addr)
		sys_func_error_exit("mlx_get_data_addr failed", __FILE__, __LINE__);
	image->width = img_width;
	image->height = img_height;
	return (image);
}

t_screen	*init_screen(const char *fdf_path)
{
	t_screen	*screen;
	char		*window_title;

	screen = (t_screen *)malloc(sizeof(t_screen));
	if (!screen)
		sys_func_error_exit("malloc failed", __FILE__, __LINE__);
	window_title = ft_strjoin("fdf - ", fdf_path);
	screen->mlx = mlx_init();
	if (!screen->mlx)
		sys_func_error_exit("mlx_init failed", __FILE__, __LINE__);
	screen->mlx_win = mlx_new_window(screen->mlx, SCREEN_WIDTH, SCREEN_HEIGHT,
			window_title);
	if (!screen->mlx_win)
		sys_func_error_exit("mlx_new_window failed", __FILE__, __LINE__);
	free(window_title);
	screen->image = init_image(screen->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	screen->mouse = (t_mouse *)malloc(sizeof(t_mouse));
	if (!screen->mouse)
		sys_func_error_exit("malloc failed", __FILE__, __LINE__);
	screen->settings = (t_settings *)malloc(sizeof(t_settings));
	if (!screen->settings)
		sys_func_error_exit("malloc failed", __FILE__, __LINE__);
	return (screen);
}
