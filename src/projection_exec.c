/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_exec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 01:22:09 by katakada          #+#    #+#             */
/*   Updated: 2025/03/13 22:19:04 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	projection_exec(t_screen *screen)
{
	auto_rotate_camera_angle(screen);
	draw_screen(screen);
	mlx_put_image_to_window(screen->mlx, screen->mlx_win, screen->image->img, 0,
		0);
	draw_info(screen);
	if (screen->settings->is_debug == TRUE)
		draw_debag(screen);
}
