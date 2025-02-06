/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_fdf__read_fdf_lines__is_hex_str.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 23:38:26 by katakada          #+#    #+#             */
/*   Updated: 2025/02/07 00:18:13 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_first_letter_case(const char *str)
{
	while (*str)
	{
		if ('a' <= *str && *str <= 'f')
			return (LOWER_CASE);
		if ('A' <= *str && *str <= 'F')
			return (UPPER_CASE);
		str++;
	}
	return (NO_CASE);
}

static int	has_sign(const char *str)
{
	while (*str)
	{
		if (*str == '-' || *str == '+')
			return (TRUE);
		str++;
	}
	return (FALSE);
}

static int	is_hex_within_uint_max_min_range(const char *str)
{
	char	*uint_max;

	uint_max = "ffffffff";
	if (ft_strncmp(str, HEX_LOWER_PREFIX, 2) == 0)
		str += 2;
	else if (ft_strncmp(str, HEX_UPPER_PREFIX, 2) == 0)
	{
		str += 2;
		uint_max = "FFFFFFFF";
	}
	else if (get_first_letter_case(str) == LOWER_CASE)
		uint_max = "ffffffff";
	else if (get_first_letter_case(str) == UPPER_CASE)
		uint_max = "FFFFFFFF";
	else
		return (TRUE);
	if (ft_strlen(str) > 8)
		return (FALSE);
	if (ft_strlen(str) == 8 && ft_strncmp(str, uint_max, 8) > 0)
		return (FALSE);
	return (TRUE);
}

static int	is_hex_base_str(const char *str)
{
	char	*base;

	if (has_sign(str))
		return (FALSE);
	base = HEX_LOWER_BASE;
	if (ft_strncmp(str, HEX_LOWER_PREFIX, 2) == 0)
		str += 2;
	if (ft_strncmp(str, HEX_UPPER_PREFIX, 2) == 0)
	{
		str += 2;
		base = HEX_UPPER_BASE;
	}
	if (get_first_letter_case(str) == LOWER_CASE)
		base = HEX_LOWER_BASE;
	if (get_first_letter_case(str) == UPPER_CASE)
		base = HEX_UPPER_BASE;
	while (*str)
	{
		if (!(base[0] <= *str && *str <= base[9]) && !(base[10] <= *str
				&& *str <= base[15]))
			return (FALSE);
		str++;
	}
	return (TRUE);
}

int	is_hex_str(const char *str)
{
	if (!is_hex_base_str(str))
		return (FALSE);
	if (!is_hex_within_uint_max_min_range(str))
		return (FALSE);
	return (TRUE);
}
