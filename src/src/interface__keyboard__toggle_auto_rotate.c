/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface__keyboard__toggle_auto_rotate.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 22:28:18 by katakada          #+#    #+#             */
/*   Updated: 2025/03/13 22:28:39 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_next_auto_rotate(int auto_rotate)
{
	if (auto_rotate == STOP)
		return (ROTATE_L);
	else if (auto_rotate == ROTATE_L)
		return (ROTATE_R);
	else if (auto_rotate == ROTATE_R)
		return (STOP);
	return (STOP);
}

void	toggle_auto_rotate(t_screen *screen, int keycode)
{
	int	next_state;

	next_state = -1;
	if (keycode == KEY_X)
	{
		next_state = get_next_auto_rotate(screen->settings->auto_rotate_x);
		screen->settings->auto_rotate_x = next_state;
	}
	else if (keycode == KEY_Y)
	{
		next_state = get_next_auto_rotate(screen->settings->auto_rotate_y);
		screen->settings->auto_rotate_y = next_state;
	}
	else if (keycode == KEY_Z)
	{
		next_state = get_next_auto_rotate(screen->settings->auto_rotate_z);
		screen->settings->auto_rotate_z = next_state;
	}
	if (next_state == STOP)
		screen->settings->is_moved = TRUE;
}
