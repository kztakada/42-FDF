/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:58:59 by katakada          #+#    #+#             */
/*   Updated: 2024/12/18 19:51:22 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
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

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	// t_data	img;
	ft_printf("FDF Start\n");
	mlx = mlx_init();
	if (mlx == NULL)
		error_exit("Error: mlx_init failed\n", NULL);
	mlx_win = mlx_new_window(mlx, 800, 600, "My Window");
	if (mlx_win == NULL)
		error_exit("Error: mlx_new_window failed\n", NULL);
	mlx_string_put(mlx, mlx_win, 100, 100, 0x00FFFF00, "Hello world!");
	// img.img = mlx_new_image(mlx, 1920, 1080);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
	// &img.line_length,
	// 		&img.endian);
	// my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
