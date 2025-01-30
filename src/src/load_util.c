/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:10:52 by katakada          #+#    #+#             */
/*   Updated: 2025/01/30 12:24:06 by katakada         ###   ########.fr       */
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

int	convert_hex_str_to_int(const char *str)
{
	if (ft_strncmp(str, HEX_LOWER_PREFIX, 2) == 0)
		return (ft_atoi_base(str, HEX_LOWER_BASE));
	else if (ft_strncmp(str, HEX_UPPER_PREFIX, 2) == 0)
		return (ft_atoi_base(str, HEX_UPPER_BASE));
	else
		return (ft_atoi_base(str, HEX_LOWER_BASE));
}
