/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_exec__draw_debag__draw_debag_fdf        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 15:21:13 by katakada          #+#    #+#             */
/*   Updated: 2025/03/16 15:10:29 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_debag_fdf_data(t_screen *screen, t_model_fdf *fdf)
{
	m_s_put_free_tc0(screen, 105, SCREEN_HEIGHT - 222,
		ft_itoa(fdf->size_x_raw));
	m_s_put_free_tc0(screen, 105, SCREEN_HEIGHT - 204,
		ft_itoa(fdf->size_y_raw));
	m_s_put_free_tc0(screen, 105, SCREEN_HEIGHT - 186, ft_itoa(fdf->max_x_raw));
	m_s_put_free_tc0(screen, 105, SCREEN_HEIGHT - 168, ft_itoa(fdf->max_y_raw));
	m_s_put_free_tc0(screen, 105, SCREEN_HEIGHT - 150, ft_itoa(fdf->max_x));
	m_s_put_free_tc0(screen, 105, SCREEN_HEIGHT - 132, ft_itoa(fdf->max_y));
	m_s_put_free_tc0(screen, 105, SCREEN_HEIGHT - 114, ft_itoa(fdf->max_z));
	m_s_put_free_tc0(screen, 105, SCREEN_HEIGHT - 78, ft_itoa(fdf->min_x));
	m_s_put_free_tc0(screen, 105, SCREEN_HEIGHT - 96, ft_itoa(fdf->min_y));
	m_s_put_free_tc0(screen, 105, SCREEN_HEIGHT - 60, ft_itoa(fdf->min_z));
}

void	draw_debag_fdf_info(void *mlx, void *mlx_win, t_screen *screen,
		t_model_fdf *fdf)
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
	draw_debag_fdf_data(screen, fdf);
}
