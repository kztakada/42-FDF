/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util__setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:18:53 by katakada          #+#    #+#             */
/*   Updated: 2025/03/15 22:13:08 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	setup_user_action_hooks(t_screen *screen)
{
	mlx_key_hook(screen->mlx_win, key_hook, screen);
	mlx_hook(screen->mlx_win, 4, 1L << 2, mouse_down, screen);
	mlx_hook(screen->mlx_win, 5, 1L << 3, mouse_up, screen);
	mlx_hook(screen->mlx_win, 6, 1L << 6, mouse_move, screen);
	mlx_hook(screen->mlx_win, 17, 0, close_window, screen);
}

void	reset_settings(t_screen *screen)
{
	screen->settings->projection_mode = ISOMETRIC;
	screen->settings->screen_mode = MAIN_SCREEN;
	screen->settings->auto_rotate_x = STOP;
	screen->settings->auto_rotate_y = STOP;
	screen->settings->auto_rotate_z = STOP;
	screen->settings->is_anti_aliasing = TRUE;
	screen->settings->is_debug = FALSE;
	screen->z_scale = Z_SCALE_DEFAULT;
	screen->settings->frame_rate = FRAME_RATE;
}
