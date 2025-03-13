/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface__keyboard.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 00:17:48 by katakada          #+#    #+#             */
/*   Updated: 2025/03/13 15:23:14 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	toggle_screen_mode(t_screen *screen)
{
	if (screen->settings->screen_mode == MAIN_SCREEN)
		screen->settings->screen_mode = MULTI_SCREEN;
	else if (screen->settings->screen_mode == MULTI_SCREEN)
		screen->settings->screen_mode = MAIN_SCREEN;
}

static void	translate_z_scale(int keycode, t_screen *screen)
{
	int	delta;

	delta = 0;
	if (keycode == KEY_PLUS)
		delta = +1;
	else if (keycode == KEY_MINUS)
		delta = -1;
	screen->z_scale += delta;
}

static void	toggle_auto_rotate_z(t_screen *screen)
{
	if (screen->settings->auto_rotate_z == STOP)
		screen->settings->auto_rotate_z = ROTATE_L;
	else if (screen->settings->auto_rotate_z == ROTATE_L)
		screen->settings->auto_rotate_z = ROTATE_R;
	else if (screen->settings->auto_rotate_z == ROTATE_R)
		screen->settings->auto_rotate_z = STOP;
}

static void	toggle_debug_mode(t_screen *screen)
{
	if (screen->settings->is_debug == TRUE)
		screen->settings->is_debug = FALSE;
	else
		screen->settings->is_debug = TRUE;
}

int	key_hook(int keycode, void *param)
{
	t_screen	*screen;

	ft_printf("keycode: %d\n", keycode);
	screen = (t_screen *)param;
	if (keycode == KEY_ESC)
		close_window(screen);
	else if (keycode == KEY_SPACE)
		toggle_screen_mode(screen);
	else if (keycode == KEY_C)
		reset_displayed_view(screen);
	else if (keycode == KEY_R)
		toggle_auto_rotate_z(screen);
	else if (keycode == KEY_D)
		toggle_debug_mode(screen);
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT || keycode == KEY_UP
		|| keycode == KEY_DOWN)
		translate_camera_pos(keycode, screen);
	else if (keycode == KEY_PLUS || keycode == KEY_MINUS)
		translate_z_scale(keycode, screen);
	return (0);
}
