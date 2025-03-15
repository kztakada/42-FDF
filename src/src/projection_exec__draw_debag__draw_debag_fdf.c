/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_exec__draw_debag__draw_debag_fdf        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 15:21:13 by katakada          #+#    #+#             */
/*   Updated: 2025/03/15 15:22:58 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_debag_fdf_data(void *mlx, void *mlx_win, t_model_fdf *fdf)
{
	mlx_string_put(mlx, mlx_win, 105, SCREEN_HEIGHT - 222, TXT_C0,
		ft_itoa(fdf->size_x_raw));
	mlx_string_put(mlx, mlx_win, 105, SCREEN_HEIGHT - 204, TXT_C0,
		ft_itoa(fdf->size_y_raw));
	mlx_string_put(mlx, mlx_win, 105, SCREEN_HEIGHT - 186, TXT_C0,
		ft_itoa(fdf->max_x_raw));
	mlx_string_put(mlx, mlx_win, 105, SCREEN_HEIGHT - 168, TXT_C0,
		ft_itoa(fdf->max_y_raw));
	mlx_string_put(mlx, mlx_win, 105, SCREEN_HEIGHT - 150, TXT_C0,
		ft_itoa(fdf->max_x));
	mlx_string_put(mlx, mlx_win, 105, SCREEN_HEIGHT - 132, TXT_C0,
		ft_itoa(fdf->max_y));
	mlx_string_put(mlx, mlx_win, 105, SCREEN_HEIGHT - 114, TXT_C0,
		ft_itoa(fdf->max_z));
	mlx_string_put(mlx, mlx_win, 105, SCREEN_HEIGHT - 78, TXT_C0,
		ft_itoa(fdf->min_x));
	mlx_string_put(mlx, mlx_win, 105, SCREEN_HEIGHT - 96, TXT_C0,
		ft_itoa(fdf->min_y));
	mlx_string_put(mlx, mlx_win, 105, SCREEN_HEIGHT - 60, TXT_C0,
		ft_itoa(fdf->min_z));
}

void	draw_debag_fdf_info(void *mlx, void *mlx_win, t_model_fdf *fdf)
{
	mlx_string_put(mlx, mlx_win, 5, SCREEN_HEIGHT - 240, TXT_C0, "FDF MODEL");
	mlx_string_put(mlx, mlx_win, 5, SCREEN_HEIGHT - 222, TXT_C0, "size_x_raw");
	mlx_string_put(mlx, mlx_win, 5, SCREEN_HEIGHT - 204, TXT_C0, "size_y_raw");
	mlx_string_put(mlx, mlx_win, 5, SCREEN_HEIGHT - 186, TXT_C0, "max_x_raw");
	mlx_string_put(mlx, mlx_win, 5, SCREEN_HEIGHT - 168, TXT_C0, "max_y_raw");
	mlx_string_put(mlx, mlx_win, 5, SCREEN_HEIGHT - 150, TXT_C0, "max_x");
	mlx_string_put(mlx, mlx_win, 5, SCREEN_HEIGHT - 132, TXT_C0, "max_y");
	mlx_string_put(mlx, mlx_win, 5, SCREEN_HEIGHT - 114, TXT_C0, "max_z");
	mlx_string_put(mlx, mlx_win, 5, SCREEN_HEIGHT - 78, TXT_C0, "min_x");
	mlx_string_put(mlx, mlx_win, 5, SCREEN_HEIGHT - 96, TXT_C0, "min_y");
	mlx_string_put(mlx, mlx_win, 5, SCREEN_HEIGHT - 60, TXT_C0, "min_z");
	draw_debag_fdf_data(mlx, mlx_win, fdf);
}
