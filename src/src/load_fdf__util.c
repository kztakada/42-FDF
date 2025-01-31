/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_fdf__util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 23:49:00 by katakada          #+#    #+#             */
/*   Updated: 2025/01/31 23:49:56 by katakada         ###   ########.fr       */
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
