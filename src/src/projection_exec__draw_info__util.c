/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_exec__draw_info__util.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:45:34 by katakada          #+#    #+#             */
/*   Updated: 2025/03/13 21:20:51 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	np_offset_x(t_view *view)
{
	return (view->offset_x * -1 + NAMEPLATE_OFFSET_X);
}

int	np_offset_y(t_view *view)
{
	return (view->offset_y * -1 + INFO_BASE_OFFSET_Y);
}

void	draw_mouse_drug_info(t_screen *screen)
{
	mlx_string_put(screen->mlx, screen->mlx_win, BOL, M_M01, TXT_C0,
		MAIN_INFO_M01);
	mlx_string_put(screen->mlx, screen->mlx_win, BOL, M_M02, TXT_C0,
		MAIN_INFO_M02);
	mlx_string_put(screen->mlx, screen->mlx_win, BOL, M_M03, TXT_C0,
		MAIN_INFO_M03);
	mlx_string_put(screen->mlx, screen->mlx_win, BOL, M_M04, TXT_C0,
		MAIN_INFO_M04);
}

void	draw_mouse_click_info(t_screen *screen)
{
	mlx_string_put(screen->mlx, screen->mlx_win, BOL, M_M01, TXT_C0,
		MULTI_INFO_M01);
	mlx_string_put(screen->mlx, screen->mlx_win, BOL, M_M02, TXT_C0,
		MULTI_INFO_M02);
}
