/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:58:59 by katakada          #+#    #+#             */
/*   Updated: 2025/03/16 00:05:24 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	loop_exec(void *param)
{
	t_screen	*screen;

	screen = (t_screen *)param;
	projection_exec(screen);
	return (0);
}

static void	setup_loop_exec_hook(t_screen *screen)
{
	mlx_loop_hook(screen->mlx, loop_exec, screen);
}

int	app_main(int argc, char *argv[])
{
	t_model_fdf	fdf;
	t_screen	*screen;

	if (argc < 2)
		forced_error_exit("No file name", __FILE__, __LINE__);
	if (argc > 2)
		forced_error_exit("Too many arguments", __FILE__, __LINE__);
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
