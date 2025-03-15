/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:58:59 by katakada          #+#    #+#             */
/*   Updated: 2025/03/16 00:02:07 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	exec_by_frame_rate(void (*func_projection_exec)(t_screen *),
		t_screen *screen)
{
	static clock_t	last_time = 0;
	clock_t			current_time;
	double			elapsed_time;
	double			one_frame_time;

	one_frame_time = PER_MILLI_SEC / screen->settings->frame_rate;
	current_time = clock();
	elapsed_time = (double)(current_time - last_time) / CLOCKS_PER_SEC
		* PER_MILLI_SEC;
	if (elapsed_time >= one_frame_time)
	{
		func_projection_exec(screen);
		last_time = current_time;
	}
}

static int	loop_exec(void *param)
{
	t_screen	*screen;

	screen = (t_screen *)param;
	exec_by_frame_rate(projection_exec, screen);
	return (0);
}

static void	setup_loop_exec_hook(t_screen *screen)
{
	mlx_loop_hook(screen->mlx, loop_exec, screen);
}

static int	app_main(int argc, char *argv[])
{
	t_model_fdf	fdf;
	t_screen	*screen;

	if (argc < 2)
		forced_error_exit("No file name", __FILE__, __LINE__);
	if (argc > 3)
		forced_error_exit("Too many arguments", __FILE__, __LINE__);
	screen = init_screen(argv[1]);
	fdf = load_fdf(argv[1]);
	screen->views = init_screen_views(&fdf);
	reset_settings(screen);
	if (argc == 3)
		setup_framerate(screen, argv[2]);
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
