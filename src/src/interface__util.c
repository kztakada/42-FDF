/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface__util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 00:40:00 by katakada          #+#    #+#             */
/*   Updated: 2025/02/12 22:54:36 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(void *param)
{
	t_screen	*screen;

	screen = (t_screen *)param;
	mlx_destroy_image(screen->mlx, screen->image->img);
	mlx_destroy_window(screen->mlx, screen->mlx_win);
	exit(0);
}

double	reset_angles(double angle)
{
	if (angle >= M_PI)
		return (-2 * M_PI - angle);
	else if (angle <= -M_PI)
		return (2 * M_PI + angle);
	return (angle);
}
