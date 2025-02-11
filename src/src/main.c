/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:58:59 by katakada          #+#    #+#             */
/*   Updated: 2025/02/12 00:11:27 by katakada         ###   ########.fr       */
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

int	exec_by_frame_rate(void (*func_projector)(t_screen *), t_screen *screen)
{
	static clock_t	last_time = 0;
	clock_t			current_time;
	double			elapsed_time;

	current_time = clock();
	elapsed_time = (double)(current_time - last_time) / CLOCKS_PER_SEC * 1000;
	if (elapsed_time >= FRAME_TIME)
	{
		func_projector(screen);
		last_time = current_time;
	}
	return (0);
}

int	loop_runner(void *param)
{
	t_screen	*screen;

	screen = (t_screen *)param;
	exec_by_frame_rate(project_screen, screen);
	return (0);
}

int	AppMain(int argc, char *argv[])
{
	t_model_fdf	fdf;
	t_screen	*screen;

	ft_printf("FDF Start\n");
	if (argc < 2)
		forced_error_exit("No file name\n", __FILE__, __LINE__);
	if (argc > 2)
		forced_error_exit("Too many arguments\n", __FILE__, __LINE__);
	screen = init_screen(argv[1]);
	fdf = load_fdf(argv[1]);
	screen->views = init_screen_views(&fdf);
	mlx_loop_hook(screen->mlx, loop_runner, screen);
	mlx_loop(screen->mlx);
	return (0);
}

#ifndef TEST
int	main(int argc, char *argv[])
{
	return (AppMain(argc, argv));
}
#endif // TEST

// ft_printf("size_x_raw: %d\n", fdf.size_x_raw);
// ft_printf("size_y_raw: %d\n", fdf.size_y_raw);
// ft_printf("max_x_raw: %d\n", fdf.max_x_raw);
// ft_printf("max_y_raw: %d\n", fdf.max_y_raw);
// ft_printf("max_x: %d\n", fdf.max_x);
// ft_printf("max_y: %d\n", fdf.max_y);
// ft_printf("max_z: %d\n", fdf.max_z);
// ft_printf("min_x: %d\n", fdf.min_x);
// ft_printf("min_y: %d\n", fdf.min_y);
// ft_printf("min_z: %d\n", fdf.min_z);
// ft_printf("vertex.x: %d\n", fdf.yx_matrix[0][0].x);
// ft_printf("vertex.y: %d\n", fdf.yx_matrix[0][0].y);
// ft_printf("vertex.z: %d\n", fdf.yx_matrix[0][0].z);
// ft_printf("vertex.x_raw: %d\n", fdf.yx_matrix[0][0].x_raw);
// ft_printf("vertex.y_raw: %d\n", fdf.yx_matrix[0][0].y_raw);
// ft_printf("vertex.color: %d\n", fdf.yx_matrix[0][0].color);