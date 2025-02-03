/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_fdf__read_fdf_lines.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 23:44:33 by katakada          #+#    #+#             */
/*   Updated: 2025/02/02 20:53:52 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	convert_hex_str_to_int(const char *str)
{
	ft_printf("color_str: %s\n", str);
	if (ft_strncmp(str, HEX_LOWER_PREFIX, 2) == 0)
		return (ft_atoi_base(str, HEX_LOWER_BASE));
	else if (ft_strncmp(str, HEX_UPPER_PREFIX, 2) == 0)
		return (ft_atoi_base(str, HEX_UPPER_BASE));
	else
		return (ft_atoi_base(str, HEX_LOWER_BASE));
}

static void	load_color(t_vertex_fdf *vertex, char *z_and_color_collection)
{
	while (z_and_color_collection[0] && z_and_color_collection[0] != ',')
		z_and_color_collection++;
	if (z_and_color_collection[0] == ',')
	{
		z_and_color_collection++;
		vertex->color = convert_hex_str_to_int(z_and_color_collection);
	}
	else
		vertex->color = -1;
}

static void	read_fdf_oneline(t_model_fdf *fdf, char *line, int y)
{
	char	**z_and_color_collection;
	int		x_i;
	int		size_x_raw;

	size_x_raw = fdf->max_x_raw + 1;
	ft_printf("size_x_raw: %d\n", size_x_raw);
	fdf->yx_matrix[y] = (t_vertex_fdf *)malloc(sizeof(t_vertex_fdf)
			* size_x_raw);
	if (!fdf->yx_matrix[y])
		sys_func_error_exit("malloc failed", __FILE__, __LINE__);
	z_and_color_collection = ft_split(line, ' ');
	x_i = 0;
	while (z_and_color_collection[x_i] && x_i < size_x_raw)
	{
		fdf->yx_matrix[y][x_i].x_raw = x_i;
		fdf->yx_matrix[y][x_i].y_raw = y;
		fdf->yx_matrix[y][x_i].z = ft_atoi(z_and_color_collection[x_i]);
		load_color(&fdf->yx_matrix[y][x_i], z_and_color_collection[x_i]);
		free(z_and_color_collection[x_i]);
		x_i++;
	}
	if (x_i != size_x_raw || z_and_color_collection[x_i] != NULL)
		forced_error_exit("Invalid fdf file (missing line segmentation)",
			__FILE__, __LINE__);
	free(z_and_color_collection);
}

void	read_fdf_lines(t_model_fdf *fdf, int fd)
{
	char	*line;
	int		i_y;

	i_y = 0;
	while (TRUE)
	{
		line = custom_get_next_line(fd);
		if (line == NULL || *line == '\0')
			break ;
		read_fdf_oneline(fdf, line, i_y);
		i_y++;
		free(line);
	}
	free(line);
}
