/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_exec__draw_info__draw_instructio        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 18:09:08 by katakada          #+#    #+#             */
/*   Updated: 2025/03/15 18:11:54 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_global_instructions(void *mlx, void *win)
{
	mlx_string_put(mlx, win, BOL, G_L01, TXT_C0, G_INFO_L01);
	mlx_string_put(mlx, win, BOL, G_M01, TXT_C0, G_INFO_M01);
	mlx_string_put(mlx, win, BOL, G_M02, TXT_C0, G_INFO_M02);
	mlx_string_put(mlx, win, BOL, G_M03, TXT_C0, G_INFO_M03);
	mlx_string_put(mlx, win, BOL, G_K01, TXT_C0, G_INFO_K01);
	mlx_string_put(mlx, win, BOL, G_K02, TXT_C0, G_INFO_K02);
	mlx_string_put(mlx, win, BOL, G_K03, TXT_C0, G_INFO_K03);
	mlx_string_put(mlx, win, BOL, G_K04, TXT_C0, G_INFO_K04);
	mlx_string_put(mlx, win, BOL, G_K05, TXT_C0, G_INFO_K05);
	mlx_string_put(mlx, win, BOL, G_K06, TXT_C0, G_INFO_K06);
	mlx_string_put(mlx, win, BOL, G_K07, TXT_C0, G_INFO_K07);
	mlx_string_put(mlx, win, BOL, G_K08, TXT_C0, G_INFO_K08);
	mlx_string_put(mlx, win, BOL, G_K09, TXT_C0, G_INFO_K09);
	mlx_string_put(mlx, win, BOL, G_K10, TXT_C0, G_INFO_K10);
	mlx_string_put(mlx, win, BOL, G_K11, TXT_C0, G_INFO_K11);
	mlx_string_put(mlx, win, BOL, G_K12, TXT_C0, G_INFO_K12);
	mlx_string_put(mlx, win, BOL, G_K13, TXT_C0, G_INFO_K13);
	mlx_string_put(mlx, win, BOL, G_K14, TXT_C0, G_INFO_K14);
	mlx_string_put(mlx, win, BOL, G_K15, TXT_C0, G_INFO_K15);
}

static void	draw_a_rotate_status(t_screen *screen)
{
	if (screen->settings->auto_rotate_x == ROTATE_L)
		mlx_string_put(screen->mlx, screen->mlx_win, BOL2, G_S03, TXT_C1,
			"ROTATE L");
	if (screen->settings->auto_rotate_y == ROTATE_L)
		mlx_string_put(screen->mlx, screen->mlx_win, BOL2, G_S04, TXT_C1,
			"ROTATE L");
	if (screen->settings->auto_rotate_z == ROTATE_L)
		mlx_string_put(screen->mlx, screen->mlx_win, BOL2, G_S05, TXT_C1,
			"ROTATE L");
	if (screen->settings->auto_rotate_x == ROTATE_R)
		mlx_string_put(screen->mlx, screen->mlx_win, BOL2, G_S03, TXT_C2,
			"ROTATE R");
	if (screen->settings->auto_rotate_y == ROTATE_R)
		mlx_string_put(screen->mlx, screen->mlx_win, BOL2, G_S04, TXT_C2,
			"ROTATE R");
	if (screen->settings->auto_rotate_z == ROTATE_R)
		mlx_string_put(screen->mlx, screen->mlx_win, BOL2, G_S05, TXT_C2,
			"ROTATE R");
}

void	draw_global_switch_status(t_screen *screen)
{
	if (screen->settings->is_debug == TRUE)
		mlx_string_put(screen->mlx, screen->mlx_win, BOL, 35, TXT_C3,
			"DEBUG MODE");
	mlx_string_put(screen->mlx, screen->mlx_win, BOL, G_S01, TXT_C0,
		"SWITCH STATUS");
	mlx_string_put(screen->mlx, screen->mlx_win, BOL, G_S02, TXT_C0,
		"Anti-aliasing");
	mlx_string_put(screen->mlx, screen->mlx_win, BOL, G_S03, TXT_C0,
		"Auto-rotate x");
	mlx_string_put(screen->mlx, screen->mlx_win, BOL, G_S04, TXT_C0,
		"Auto-rotate y");
	mlx_string_put(screen->mlx, screen->mlx_win, BOL, G_S05, TXT_C0,
		"Auto-rotate z");
	if (screen->settings->is_anti_aliasing == TRUE)
		mlx_string_put(screen->mlx, screen->mlx_win, BOL2, G_S02, COLOR_L4,
			"ON");
	draw_a_rotate_status(screen);
}
