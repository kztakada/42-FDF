/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 00:46:24 by katakada          #+#    #+#             */
/*   Updated: 2025/03/16 17:12:04 by katakada         ###   ########.fr       */
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

char	*ft_dtoa(double n)
{
	char	*tmp;
	char	*tmp2;
	char	*result;

	if (n < 0)
	{
		n = n * -1;
		tmp = ft_dtoa(n);
		result = ft_strjoin("-", tmp);
		free(tmp);
		return (result);
	}
	tmp = ft_itoa((int)n);
	tmp2 = ft_strjoin(tmp, ".");
	free(tmp);
	tmp = ft_itoa((int)((n - (int)n) * 1000000000));
	result = ft_strjoin(tmp2, tmp);
	free(tmp2);
	free(tmp);
	return (result);
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
		line = get_next_line(fd);
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
