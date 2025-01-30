/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 00:26:27 by katakada          #+#    #+#             */
/*   Updated: 2025/01/30 23:07:18 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	load_color(t_vertex_fdf *vertex, char *z_and_color_collection)
{
	while (z_and_color_collection[0] && z_and_color_collection[0] != ',')
		z_and_color_collection++;
	if (z_and_color_collection[0] == ',')
		vertex->color = convert_hex_str_to_int(z_and_color_collection);
	else
		vertex->color = -1;
}

static void	load_oneline(t_model_fdf *fdf, char *line, int y)
{
	char	**z_and_color_collection;
	int		i_x;
	int		size_x_raw;

	size_x_raw = fdf->max_x_raw + 1;
	fdf->yx_matrix[y] = (t_vertex_fdf *)malloc(sizeof(t_vertex_fdf)
			* size_x_raw);
	if (!fdf->yx_matrix[y])
		sys_func_error_exit("malloc failed", __FILE__, __LINE__);
	z_and_color_collection = ft_split(line, ' ');
	i_x = 0;
	while (z_and_color_collection[i_x] && i_x < fdf->max_x_raw)
	{
		fdf->yx_matrix[y][i_x].x_raw = i_x;
		fdf->yx_matrix[y][i_x].y_raw = y;
		fdf->yx_matrix[y][i_x].z = ft_atoi(z_and_color_collection[i_x]);
		load_color(&fdf->yx_matrix[y][i_x], z_and_color_collection[i_x]);
		free(z_and_color_collection[i_x]);
		i_x++;
	}
	if (i_x != fdf->max_x_raw || z_and_color_collection[i_x])
		forced_error_exit("Invalid fdf file (missing line segmentation)",
			__FILE__, __LINE__);
	free(z_and_color_collection);
}

void	load_lines(t_model_fdf *fdf, int fd)
{
	char	*line;
	char	**z_and_color_collection;
	int		i_y;

	i_y = 0;
	while (TRUE)
	{
		line = get_next_line(fd);
		if (line == NULL || *line == '\0')
			break ;
		load_oneline(fdf, line, i_y);
		i_y++;
		free(line);
	}
	free(line);
}
