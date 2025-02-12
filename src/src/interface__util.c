/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface__util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 00:40:00 by katakada          #+#    #+#             */
/*   Updated: 2025/02/12 00:40:19 by katakada         ###   ########.fr       */
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
