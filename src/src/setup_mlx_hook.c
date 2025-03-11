/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_mlx_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:29:44 by katakada          #+#    #+#             */
/*   Updated: 2025/03/12 01:25:39 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	exec_by_frame_rate(void (*func_projection_exec)(t_screen *),
		t_screen *screen)
{
	static clock_t	last_time = 0;
	clock_t			current_time;
	double			elapsed_time;

	current_time = clock();
	elapsed_time = (double)(current_time - last_time) / CLOCKS_PER_SEC * 1000;
	if (elapsed_time >= FRAME_TIME)
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

void	setup_loop_exec_hook(t_screen *screen)
{
	mlx_loop_hook(screen->mlx, loop_exec, screen);
}

void	setup_user_action_hooks(t_screen *screen)
{
	mlx_key_hook(screen->mlx_win, key_hook, screen);
	mlx_hook(screen->mlx_win, 4, 1L << 2, mouse_down, screen);
	mlx_hook(screen->mlx_win, 5, 1L << 3, mouse_up, screen);
	mlx_hook(screen->mlx_win, 6, 1L << 6, mouse_move, screen);
	mlx_hook(screen->mlx_win, 17, 0, close_window, screen);
}
