/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:10:05 by katakada          #+#    #+#             */
/*   Updated: 2025/03/14 19:31:33 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	calc_max_x_raw(const char *fdf_path)
{
	int		fd;
	char	*line;
	char	**z_and_color_collection;
	int		size_x_raw;
	int		i;

	fd = open_or_exit(fdf_path, __FILE__, __LINE__);
	line = custom_get_next_line(fd);
	if (line == NULL || *line == '\0')
		forced_error_exit("Can not find line", __FILE__, __LINE__);
	size_x_raw = 0;
	z_and_color_collection = ft_split(line, ' ');
	i = 0;
	while (z_and_color_collection[i])
	{
		if (*z_and_color_collection[i] != '\0')
			size_x_raw++;
		free(z_and_color_collection[i]);
		i++;
	}
	flush_get_next_line(fd);
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
		line = custom_get_next_line(fd);
		if (line == NULL || *line == '\0')
			break ;
		size_y_raw++;
		free(line);
	}
	inspect_for_newlines_only(fd, &line);
	flush_get_next_line(fd);
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

	if (verify_empty_fdf(fdf_path))
		return (get_empty_fdf());
	fdf.max_x_raw = calc_max_x_raw(fdf_path);
	fdf.size_x_raw = fdf.max_x_raw + 1;
	fdf.max_y_raw = calc_max_y_raw(fdf_path);
	fdf.size_y_raw = fdf.max_y_raw + 1;
	fd = open_or_exit(fdf_path, __FILE__, __LINE__);
	fdf.yx_matrix = (t_vertex_fdf **)malloc(sizeof(t_vertex_fdf *)
			* fdf.size_y_raw);
	if (!fdf.yx_matrix)
		sys_func_error_exit("malloc failed", __FILE__, __LINE__);
	read_fdf_lines(&fdf, fd);
	if (close(fd) < 0)
		sys_func_error_exit("close failed", __FILE__, __LINE__);
	fdf = calc_balanced_x_y(fdf);
	fdf = calc_max_min_xyz(fdf);
	return (fdf);
}
