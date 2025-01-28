/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_screen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 00:28:53 by katakada          #+#    #+#             */
/*   Updated: 2025/01/22 00:29:21 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	project_screen(t_screen *screen)
{
	mlx_put_image_to_window(screen->mlx, screen->mlx_win, screen->image->img, 0,
		0);
	draw_instructions(screen);
	draw_debag(screen);
}
