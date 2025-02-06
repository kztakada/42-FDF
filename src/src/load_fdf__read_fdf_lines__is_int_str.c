/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_fdf__read_fdf_lines__util.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 00:49:17 by katakada          #+#    #+#             */
/*   Updated: 2025/02/07 00:18:03 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	is_numeric_str(const char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!('0' <= *str && *str <= '9'))
			return (FALSE);
		str++;
	}
	return (TRUE);
}

static int	is_within_int_max_min_range(const char *str)
{
	int	is_mainus;

	is_mainus = 0;
	if (str[0] == '-')
	{
		is_mainus = 1;
		str++;
	}
	if (str[0] == '+')
		str++;
	if (ft_strlen(str) > 10)
		return (FALSE);
	if (is_mainus)
	{
		if (ft_strlen(str) == 10 && ft_strncmp(str, "2147483648", 10) > 0)
			return (FALSE);
	}
	else
	{
		if (ft_strlen(str) == 10 && ft_strncmp(str, "2147483647", 10) > 0)
			return (FALSE);
	}
	return (TRUE);
}

int	is_int_str(const char *str)
{
	if (!is_numeric_str(str))
		return (FALSE);
	if (!is_within_int_max_min_range(str))
		return (FALSE);
	return (TRUE);
}
