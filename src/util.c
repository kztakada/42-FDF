/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 00:46:24 by katakada          #+#    #+#             */
/*   Updated: 2025/03/15 14:48:47 by katakada         ###   ########.fr       */
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
	char	*str;
	char	*tmp;
	char	*tmp2;

	if (n < 0)
	{
		n = n * -1;
		str = ft_strjoin("-", ft_dtoa(n));
		return (str);
	}
	str = ft_itoa((int)n);
	tmp = ft_strjoin(str, ".");
	free(str);
	str = ft_itoa((int)((n - (int)n) * 1000000000));
	tmp2 = ft_strjoin(tmp, str);
	free(tmp);
	free(str);
	return (tmp2);
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
