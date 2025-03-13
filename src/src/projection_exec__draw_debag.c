/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_exec__draw_debag.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 22:48:52 by katakada          #+#    #+#             */
/*   Updated: 2025/03/14 01:41:41 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_dtoa(double n)
{
	char	*str;
	char	*tmp;
	char	*tmp2;

	if (n < 0)
	{
		n = n * -1;
		str = ft_strjoin("-", ft_dtoa(n));
		return (str);
	}
	str = ft_itoa((int)n);
	tmp = ft_strjoin(str, ".");
	free(str);
	str = ft_itoa((int)((n - (int)n) * 1000000000));
	tmp2 = ft_strjoin(tmp, str);
	free(tmp);
	free(str);
	return (tmp2);
}

void	put_camera_status(t_screen *screen, t_view *view, int x, int y)
{
	mlx_string_put(screen->mlx, screen->mlx_win, x, y, TXT_C0, "CAMERA STATUS");
	mlx_string_put(screen->mlx, screen->mlx_win, x, y + 20, TXT_C0, "zoom");
	mlx_string_put(screen->mlx, screen->mlx_win, x, y + 40, TXT_C0, "x_angle");
	mlx_string_put(screen->mlx, screen->mlx_win, x, y + 60, TXT_C0, "y_angle");
	mlx_string_put(screen->mlx, screen->mlx_win, x, y + 80, TXT_C0, "z_angle");
	mlx_string_put(screen->mlx, screen->mlx_win, x, y + 100, TXT_C0,
		"x_offset");
	mlx_string_put(screen->mlx, screen->mlx_win, x, y + 120, TXT_C0,
		"y_offset");
	mlx_string_put(screen->mlx, screen->mlx_win, x, y + 140, TXT_C0, "z_scale");
	mlx_string_put(screen->mlx, screen->mlx_win, x + 80, y + 20, TXT_C0,
		ft_itoa(view->camera->zoom));
	mlx_string_put(screen->mlx, screen->mlx_win, x + 80, y + 40, TXT_C0,
		ft_dtoa(view->camera->x_angle));
	mlx_string_put(screen->mlx, screen->mlx_win, x + 80, y + 60, TXT_C0,
		ft_dtoa(view->camera->y_angle));
	mlx_string_put(screen->mlx, screen->mlx_win, x + 80, y + 80, TXT_C0,
		ft_dtoa(view->camera->z_angle));
	mlx_string_put(screen->mlx, screen->mlx_win, x + 80, y + 100, TXT_C0,
		ft_itoa(view->camera->x_offset));
	mlx_string_put(screen->mlx, screen->mlx_win, x + 80, y + 120, TXT_C0,
		ft_itoa(view->camera->y_offset));
	mlx_string_put(screen->mlx, screen->mlx_win, x + 80, y + 140, TXT_C0,
		ft_itoa(screen->z_scale));
}

void	draw_debag_main_view(t_screen *screen)
{
	put_camera_status(screen, screen->views->main_view,
		np_offset_x(screen->views->main_view), screen->views->main_view->height
		- 220);
}

void	draw_debag_multi_view(t_screen *screen)
{
	put_camera_status(screen, screen->views->multi_view->left_up,
		np_offset_x(screen->views->multi_view->left_up),
		np_offset_y(screen->views->multi_view->left_up)
		+ screen->views->multi_view->left_up->height - 220);
	put_camera_status(screen, screen->views->multi_view->right_up,
		np_offset_x(screen->views->multi_view->right_up),
		np_offset_y(screen->views->multi_view->right_up)
		+ screen->views->multi_view->right_up->height - 220);
	put_camera_status(screen, screen->views->multi_view->left_down,
		np_offset_x(screen->views->multi_view->left_down),
		np_offset_y(screen->views->multi_view->left_down)
		+ screen->views->multi_view->left_down->height - 220);
	put_camera_status(screen, screen->views->multi_view->right_down,
		np_offset_x(screen->views->multi_view->right_down),
		np_offset_y(screen->views->multi_view->right_down)
		+ screen->views->multi_view->right_down->height - 220);
}

void	draw_debag(t_screen *screen)
{
	if (screen->settings->screen_mode == MAIN_SCREEN)
		draw_debag_main_view(screen);
	else if (screen->settings->screen_mode == MULTI_SCREEN)
		draw_debag_multi_view(screen);
}
