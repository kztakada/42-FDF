/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface__util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 00:40:00 by katakada          #+#    #+#             */
/*   Updated: 2025/03/13 19:28:14 by katakada         ###   ########.fr       */
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

static double	reset_angles(double angle)
{
	if (angle >= M_PI)
		angle -= 2 * M_PI;
	else if (angle <= -M_PI)
		angle += 2 * M_PI;
	return (angle);
}

void	rotate_angle(double *angle, double delta)
{
	double	new_angle;

	new_angle = *angle + delta;
	*angle = reset_angles(new_angle);
}
