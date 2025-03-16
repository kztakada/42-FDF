/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface__mouse__mouse_up.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 23:49:53 by katakada          #+#    #+#             */
/*   Updated: 2025/03/11 14:44:43 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_up(int button, int mouse_x, int mouse_y, void *param)
{
	t_screen	*screen;

	(void)mouse_x;
	(void)mouse_y;
	screen = (t_screen *)param;
	if (button == MOUSE_LEFT || button == MOUSE_RIGHT || button == MOUSE_MIDDLE)
		screen->mouse->button = 0;
	return (0);
}
