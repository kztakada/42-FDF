/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:58:59 by katakada          #+#    #+#             */
/*   Updated: 2025/03/15 16:56:37 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
}

int	app_main(int argc, char *argv[])
{
	t_model_fdf	fdf;
	t_screen	*screen;

	if (argc < 2)
		forced_error_exit("No file name\n", __FILE__, __LINE__);
	if (argc > 2)
		forced_error_exit("Too many arguments\n", __FILE__, __LINE__);
	screen = init_screen(argv[1]);
	fdf = load_fdf(argv[1]);
	screen->views = init_screen_views(&fdf);
	reset_settings(screen);
	setup_user_action_hooks(screen);
	setup_loop_exec_hook(screen);
	mlx_loop(screen->mlx);
	return (0);
}

#ifndef TEST

int	main(int argc, char *argv[])
{
	return (app_main(argc, argv));
}
#endif // TEST
