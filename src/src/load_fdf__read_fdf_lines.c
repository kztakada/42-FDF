/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_fdf__read_fdf_lines.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 23:44:33 by katakada          #+#    #+#             */
/*   Updated: 2025/02/08 00:15:29 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*skip_z(char *z_and_color)
{
	while (z_and_color[0] && z_and_color[0] != ',')
		z_and_color++;
	return (z_and_color);
}

static int	read_color(char *verified_altitude)
{
	char	*color;

	verified_altitude = skip_z(verified_altitude);
	if (verified_altitude[0] == ',')
	{
		verified_altitude++;
		color = verified_altitude;
		return (convert_hex_str_to_int(color));
	}
	else
		return (-1);
}

static void	read_fdf_oneline(t_model_fdf *fdf, char *line, int y)
{
	char	**z_and_color_collection;
	int		x_i;

	fdf->yx_matrix[y] = (t_vertex_fdf *)malloc(sizeof(t_vertex_fdf)
			* fdf->size_x_raw);
	if (!fdf->yx_matrix[y])
		sys_func_error_exit("malloc failed", __FILE__, __LINE__);
	z_and_color_collection = ft_split(line, ' ');
	x_i = 0;
	while (z_and_color_collection[x_i] && x_i < fdf->size_x_raw)
	{
		fdf->yx_matrix[y][x_i].x_raw = x_i;
		fdf->yx_matrix[y][x_i].y_raw = y;
		validate_altitude_format(z_and_color_collection[x_i], __FILE__,
			__LINE__);
		fdf->yx_matrix[y][x_i].z = ft_atoi(z_and_color_collection[x_i]);
		fdf->yx_matrix[y][x_i].color = read_color(z_and_color_collection[x_i]);
		free(z_and_color_collection[x_i]);
		x_i++;
	}
	if (x_i != fdf->size_x_raw || z_and_color_collection[x_i] != NULL)
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
