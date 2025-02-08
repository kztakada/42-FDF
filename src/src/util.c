/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 00:46:24 by katakada          #+#    #+#             */
/*   Updated: 2025/02/09 01:06:21 by katakada         ###   ########.fr       */
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
