/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:58:59 by katakada          #+#    #+#             */
/*   Updated: 2025/01/09 20:27:31 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = (y * data->line_length + x * (data->bits_per_pixel / 8));
	dst = data->addr + offset;
	*(unsigned int *)dst = color;
}

void	error_exit(char *format, char *message)
{
	if (message == NULL)
		ft_printf(format);
	else
		ft_printf(format, message);
	exit(1);
}

int	key_hook(int keycode, void *param)
{
	(void)param;
	ft_printf("keycode: %d\n", keycode);
	return (0);
}
int	mouse_hook(int button, int x, int y, void *param)
{
	(void)param;
	ft_printf("x: %d, y: %d\n", x, y);
	ft_printf("keycode: %d\n", button);
	return (0);
}

int	destory(void *param)
{
	(void)param;
	ft_printf("destory\n");
	exit(0);
}

int	summ(int a, int b)
{
	return (a + b);
}

int	AppMain(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	ft_printf("FDF Start\n");
	mlx = mlx_init();
	if (mlx == NULL)
		error_exit("Error: mlx_init failed\n", NULL);
	mlx_win = mlx_new_window(mlx, 800, 600, "My Window");
	if (mlx_win == NULL)
		error_exit("Error: mlx_new_window failed\n", NULL);
	// mlx_string_put(mlx, mlx_win, 100, 100, 0x00FFFF00, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	ft_printf("bits_per_pixel: %d\n", img.bits_per_pixel);
	ft_printf("line_length: %d\n", img.line_length);
	// img.bits_per_pixel = 1;
	// img.line_length = 10;
	my_mlx_pixel_put(&img, 5, 5, 0x00FFFF00);
	my_mlx_pixel_put(&img, 10, 10, 0x00FFFF00);
	ft_printf("addr: %s\n", img.addr);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	// mlx_key_hook(mlx_win, key_hook, NULL);
	// mlx_mouse_hook(mlx_win, mouse_hook, NULL);
	mlx_hook(mlx_win, 4, 1L << 2, destory, NULL);
	mlx_hook(mlx_win, 17, 0, destory, NULL);
	mlx_loop(mlx);
	return (0);
}

#ifndef TEST
int	main(void)
{
	return (AppMain());
}
#endif // TEST