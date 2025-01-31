/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:10:05 by katakada          #+#    #+#             */
/*   Updated: 2025/01/31 23:33:18 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	calc_max_x_raw(const char *fdf_path)
{
	int		fd;
	char	*line;
	int		size_x_raw;
	int		i;

	fd = open_or_exit(fdf_path, __FILE__, __LINE__);
	line = get_next_line(fd);
	if (*line == '\0')
		forced_error_exit("Invalid fdf file (empty file)", __FILE__, __LINE__);
	size_x_raw = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && (line[i + 1] == ' ' || line[i + 1] == '\0'))
			size_x_raw++;
		i++;
	}
	free(line);
	while (get_next_line(fd))
		free(line);
	free(line);
	if (close(fd) < 0)
		sys_func_error_exit("close failed", __FILE__, __LINE__);
	return (size_x_raw - 1);
}

static int	calc_max_y_raw(const char *fdf_path)
{
	int		fd;
	char	*line;
	int		size_y_raw;

	fd = open_or_exit(fdf_path, __FILE__, __LINE__);
	size_y_raw = 0;
	while (TRUE)
	{
		line = get_next_line(fd);
		if (line == NULL || *line == '\0')
			break ;
		size_y_raw++;
		free(line);
	}
	free(line);
	if (close(fd) < 0)
		sys_func_error_exit("close failed", __FILE__, __LINE__);
	return (size_y_raw - 1);
}

static t_model_fdf	calc_balanced_x_y(t_model_fdf fdf)
{
	int	x_offset;
	int	y_offset;
	int	y;
	int	x;

	x_offset = fdf.max_x_raw / 2;
	y_offset = fdf.max_y_raw / 2;
	y = 0;
	while (y <= fdf.max_y_raw)
	{
		x = 0;
		while (x <= fdf.max_x_raw)
		{
			fdf.yx_matrix[y][x].x = x - x_offset;
			fdf.yx_matrix[y][x].y = y - y_offset;
			x++;
		}
		y++;
	}
	return (fdf);
}

t_model_fdf	load_fdf(const char *fdf_path)
{
	int			fd;
	t_model_fdf	fdf;
	int			size_y_raw;

	fdf.max_x_raw = calc_max_x_raw(fdf_path);
	fdf.max_y_raw = calc_max_y_raw(fdf_path);
	size_y_raw = fdf.max_y_raw + 1;
	fd = open_or_exit(fdf_path, __FILE__, __LINE__);
	fdf.yx_matrix = (t_vertex_fdf **)malloc(sizeof(t_vertex_fdf *)
			* size_y_raw);
	if (!fdf.yx_matrix)
		sys_func_error_exit("malloc failed", __FILE__, __LINE__);
	read_fdf_lines(&fdf, fd);
	if (close(fd) < 0)
		sys_func_error_exit("close failed", __FILE__, __LINE__);
	fdf = calc_balanced_x_y(fdf);
	// x,y,zの最大値、最小値を計算
	// fdf = calc_max_min_xyz(fdf);
	return (fdf);
}
