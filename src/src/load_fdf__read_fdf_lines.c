/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_fdf__read_fdf_lines.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 23:44:33 by katakada          #+#    #+#             */
/*   Updated: 2025/02/06 16:27:56 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	convert_hex_str_to_int(const char *hex_str)
{
	ft_printf("color_str: %s\n", hex_str);
	if (ft_strncmp(hex_str, HEX_LOWER_PREFIX, 2) == 0)
		return (ft_atoi_base(hex_str, HEX_LOWER_BASE));
	else if (ft_strncmp(hex_str, HEX_UPPER_PREFIX, 2) == 0)
		return (ft_atoi_base(hex_str, HEX_UPPER_BASE));
	else if (get_first_letter_case(hex_str) == LOWER_CASE)
		return (ft_atoi_base(hex_str, HEX_LOWER_BASE));
	else if (get_first_letter_case(hex_str) == UPPER_CASE)
		return (ft_atoi_base(hex_str, HEX_UPPER_BASE));
	else
	{
		forced_error_exit("Invalid fdf file (invalid altitude color value)",
			__FILE__, __LINE__);
		return (-1);
	}
}

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
		verified_altitude[0] = '\0';
		color = verified_altitude + 1;
		return (convert_hex_str_to_int(color));
	}
	else
		return (-1);
}

static void	read_fdf_oneline(t_model_fdf *fdf, char *line, int y)
{
	char	**z_and_color_collection;
	int		x_i;
	int		size_x_raw;

	size_x_raw = fdf->max_x_raw + 1;
	// ft_printf("size_x_raw: %d\n", size_x_raw);
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
		verify_altitude_format(z_and_color_collection[x_i], __FILE__, __LINE__);
		fdf->yx_matrix[y][x_i].z = ft_atoi(z_and_color_collection[x_i]);
		fdf->yx_matrix[y][x_i].color = read_color(z_and_color_collection[x_i]);
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
