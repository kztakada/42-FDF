/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:58:59 by katakada          #+#    #+#             */
/*   Updated: 2025/02/08 00:45:05 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
// {
// 	char	*dst;
// 	int		offset;

// 	offset = (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	dst = data->addr + offset;
// 	*(unsigned int *)dst = color;
// }

// void	error_exit(char *format, char *message)
// {
// 	if (message == NULL)
// 		ft_printf(format);
// 	else
// 		ft_printf(format, message);
// 	exit(1);
// }

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

// int	destory(void *param)
// {
// 	(void)param;
// 	ft_printf("destory\n");
// 	exit(0);
// }

// int	summ(int a, int b)
// {
// 	return (a + b);
// }

// int	AppMain(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_image	img;

// 	ft_printf("FDF Start\n");
// 	mlx = mlx_init();
// 	if (mlx == NULL)
// 		error_exit("Error: mlx_init failed\n", NULL);
// 	mlx_win = mlx_new_window(mlx, 800, 600, "My Window");
// 	if (mlx_win == NULL)
// 		error_exit("Error: mlx_new_window failed\n", NULL);
// 	// mlx_string_put(mlx, mlx_win, 100, 100, 0x00FFFF00, "Hello world!");
// 	img.img = mlx_new_image(mlx, 1920, 1080);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 			&img.endian);
// 	ft_printf("bits_per_pixel: %d\n", img.bits_per_pixel);
// 	ft_printf("line_length: %d\n", img.line_length);
// 	// img.bits_per_pixel = 1;
// 	// img.line_length = 10;
// 	my_mlx_pixel_put(&img, 5, 5, 0x00FFFF00);
// 	my_mlx_pixel_put(&img, 10, 10, 0x00FFFF00);
// 	ft_printf("addr: %s\n", img.addr);
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	// mlx_key_hook(mlx_win, key_hook, NULL);
// 	// mlx_mouse_hook(mlx_win, mouse_hook, NULL);
// 	mlx_hook(mlx_win, 4, 1L << 2, destory, NULL);
// 	mlx_hook(mlx_win, 17, 0, destory, NULL);
// 	mlx_loop(mlx);
// 	return (0);
// }
int	AppMain(int argc, char *argv[])
{
	t_model_fdf	fdf;
	t_screen	*screen;
	t_view		*main_view;

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
	main_view = init_view(SCREEN_WIDTH, SCREEN_HEIGHT, ISOMETRIC, &fdf);
	printf("main_view->camera->zoom: %d\n", main_view->camera->zoom);
	draw_view(main_view, screen->image);
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
