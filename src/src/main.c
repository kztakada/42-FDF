/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:58:59 by katakada          #+#    #+#             */
/*   Updated: 2025/02/11 21:46:25 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// int	key_hook(int keycode, void *param)
// {
// 	(void)param;
// 	ft_printf("keycode: %d\n", keycode);
// 	return (0);
// }
// int	mouse_hook(int button, int x, int y, void *param)
// {
// 	(void)param;
// 	ft_printf("x: %d, y: %d\n", x, y);
// 	ft_printf("keycode: %d\n", button);
// 	return (0);
// }

// int	summ(int a, int b)
// {
// 	return (a + b);
// }

int	AppMain(int argc, char *argv[])
{
	t_model_fdf	fdf;
	t_screen	*screen;

	// t_view		*main_view;
	ft_printf("FDF Start\n");
	if (argc < 2)
		forced_error_exit("No file name\n", __FILE__, __LINE__);
	if (argc > 2)
		forced_error_exit("Too many arguments\n", __FILE__, __LINE__);
	screen = init_screen(argv[1]);
	fdf = load_fdf(argv[1]);
	ft_printf("size_x_raw: %d\n", fdf.size_x_raw);
	ft_printf("size_y_raw: %d\n", fdf.size_y_raw);
	ft_printf("max_x_raw: %d\n", fdf.max_x_raw);
	ft_printf("max_y_raw: %d\n", fdf.max_y_raw);
	ft_printf("max_x: %d\n", fdf.max_x);
	ft_printf("max_y: %d\n", fdf.max_y);
	ft_printf("max_z: %d\n", fdf.max_z);
	ft_printf("min_x: %d\n", fdf.min_x);
	ft_printf("min_y: %d\n", fdf.min_y);
	ft_printf("min_z: %d\n", fdf.min_z);
	ft_printf("vertex.x: %d\n", fdf.yx_matrix[0][0].x);
	ft_printf("vertex.y: %d\n", fdf.yx_matrix[0][0].y);
	ft_printf("vertex.z: %d\n", fdf.yx_matrix[0][0].z);
	ft_printf("vertex.x_raw: %d\n", fdf.yx_matrix[0][0].x_raw);
	ft_printf("vertex.y_raw: %d\n", fdf.yx_matrix[0][0].y_raw);
	ft_printf("vertex.color: %d\n", fdf.yx_matrix[0][0].color);
	screen->views = init_screen_views(&fdf);
	// printf("main_view->camera->zoom: %d\n", main_view->camera->zoom);
	project_screen(screen);
	mlx_loop(screen->mlx);
	return (0);
}

#ifndef TEST
int	main(int argc, char *argv[])
{
	return (AppMain(argc, argv));
}
#endif // TEST
