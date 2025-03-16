/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util__custom_get_next_line.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:53:58 by katakada          #+#    #+#             */
/*   Updated: 2025/02/03 18:54:39 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	replace_with_space(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] >= '\t' && line[i] <= '\r')
			line[i] = ' ';
		i++;
	}
}

// custom in order to no newline character at the end of the line
char	*custom_get_next_line(int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (line == NULL)
		return (NULL);
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	replace_with_space(line);
	return (line);
}
