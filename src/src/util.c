/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 00:46:24 by katakada          #+#    #+#             */
/*   Updated: 2025/02/06 00:55:09 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vertex_fdf	*get_vertex_fdf(int x_raw, int y_raw, t_model_fdf *fdf)
{
	if (&(fdf->yx_matrix[y_raw][x_raw]) == NULL)
		return (NULL);
	else
		return (&(fdf->yx_matrix[y_raw][x_raw]));
}

int	get_int_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

t_line_on_view	make_line_on_view(t_dot_on_view start_dot,
		t_dot_on_view end_dot)
{
	t_line_on_view	line;

	line.start_dot = start_dot;
	line.end_dot = end_dot;
	line.is_steep = get_int_abs(line.end_dot.y
			- line.start_dot.y) > get_int_abs(line.end_dot.x
			- line.start_dot.x);
	line.is_reversed = FALSE;
	return (line);
}

void	flush_get_next_line(int fd)
{
	char	*line;

	while (TRUE)
	{
		line = custom_get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
	}
}

void	free_all(char **str_collection)
{
	int	i;

	i = 0;
	while (str_collection[i])
	{
		free(str_collection[i]);
		i++;
	}
	free(str_collection);
}
