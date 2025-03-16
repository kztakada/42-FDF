/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_fdf__util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 23:49:00 by katakada          #+#    #+#             */
/*   Updated: 2025/03/14 18:29:34 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	open_or_exit(const char *path, const char *file, int line)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		sys_func_error_exit("open failed", file, line);
	return (fd);
}

t_model_fdf	get_empty_fdf(void)
{
	t_model_fdf	fdf;

	fdf.size_x_raw = 0;
	fdf.size_y_raw = 0;
	fdf.max_x_raw = 0;
	fdf.max_y_raw = 0;
	fdf.yx_matrix = NULL;
	fdf.max_x = 0;
	fdf.max_y = 0;
	fdf.max_z = 0;
	fdf.min_x = 0;
	fdf.min_y = 0;
	fdf.min_z = 0;
	return (fdf);
}

void	inspect_for_newlines_only(int fd, char **line)
{
	while (*line != NULL && **line == '\0')
	{
		free(*line);
		*line = custom_get_next_line(fd);
	}
	if (*line != NULL)
		forced_error_exit("Invalid fdf file (invalid file format)", __FILE__,
			__LINE__);
}

int	verify_empty_fdf(const char *fdf_path)
{
	int		fd;
	char	*line;
	int		result;

	fd = open_or_exit(fdf_path, __FILE__, __LINE__);
	line = custom_get_next_line(fd);
	if (line != NULL && *line == '\0')
		inspect_for_newlines_only(fd, &line);
	if (line == NULL)
	{
		result = 1;
		ft_printf("Attention: fdf file is empty\n");
	}
	else
	{
		result = 0;
		flush_get_next_line(fd);
	}
	if (close(fd) < 0)
		sys_func_error_exit("close failed", __FILE__, __LINE__);
	return (result);
}
