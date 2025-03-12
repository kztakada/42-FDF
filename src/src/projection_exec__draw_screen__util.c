/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_exec__draw_screen__util.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:49:53 by katakada          #+#    #+#             */
/*   Updated: 2025/03/12 20:50:37 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	put_mlx_pixel_dot(t_image *data, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = (y * data->line_length + x * (data->bits_per_pixel / 8));
	dst = data->addr + offset;
	*(unsigned int *)dst = color;
}

void	put_rectangle(t_image *image, t_rectangle *rectangle, int start_x,
		int start_y)
{
	int	x;
	int	y;

	x = 0;
	while (x < rectangle->width)
	{
		y = 0;
		while (y < rectangle->height)
		{
			if (start_x + x >= 0 && start_x + x < image->width && start_y
				+ y >= 0 && start_y + y < image->height)
				put_mlx_pixel_dot(image, start_x + x, start_y + y,
					rectangle->color);
			y++;
		}
		x++;
	}
}

int	v_offset_x(t_view *view)
{
	return (view->offset_x * -1);
}

int	v_offset_y(t_view *view)
{
	return (view->offset_y * -1);
}
