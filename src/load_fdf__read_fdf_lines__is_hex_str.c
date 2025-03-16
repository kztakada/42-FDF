/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_fdf__read_fdf_lines__is_hex_str.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 23:38:26 by katakada          #+#    #+#             */
/*   Updated: 2025/02/09 23:18:48 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_first_hex_letter_case(const char *str)
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

int	convert_hex_str_to_int(const char *hex_str)
{
	if (hex_str[0] == '-' || hex_str[0] == '+')
		hex_str++;
	if (ft_strncmp(hex_str, HEX_LOWER_PREFIX, 2) == 0 || ft_strncmp(hex_str,
			HEX_UPPER_PREFIX, 2) == 0)
		hex_str += 2;
	if (get_first_hex_letter_case(hex_str) == LOWER_CASE)
		return (ft_atoi_base(hex_str, HEX_LOWER_BASE));
	else if (get_first_hex_letter_case(hex_str) == UPPER_CASE)
		return (ft_atoi_base(hex_str, HEX_UPPER_BASE));
	else if (is_int_str(hex_str))
		return (ft_atoi_base(hex_str, HEX_LOWER_BASE));
	else
	{
		forced_error_exit("Invalid fdf file (invalid altitude color value)",
			__FILE__, __LINE__);
		return (-1);
	}
}

static int	is_hex_under_int_max(const char *str)
{
	char	*int_max;

	if (str[0] == '+')
		str++;
	int_max = "7fffffff";
	if (ft_strncmp(str, HEX_LOWER_PREFIX, 2) == 0)
		str += 2;
	else if (ft_strncmp(str, HEX_UPPER_PREFIX, 2) == 0)
	{
		str += 2;
		int_max = "7FFFFFFF";
	}
	else if (get_first_hex_letter_case(str) == LOWER_CASE)
		int_max = "7fffffff";
	else if (get_first_hex_letter_case(str) == UPPER_CASE)
		int_max = "7FFFFFFF";
	else
		return (TRUE);
	if (ft_strlen(str) > 8)
		return (FALSE);
	if (ft_strlen(str) == 8 && ft_strncmp(str, int_max, 8) > 0)
		return (FALSE);
	return (TRUE);
}

static int	is_hex_base_str(const char *str)
{
	char	*base;

	if (str[0] == '-' || str[0] == '+')
		str++;
	base = HEX_LOWER_BASE;
	if (ft_strncmp(str, HEX_LOWER_PREFIX, 2) == 0 || ft_strncmp(str,
			HEX_UPPER_PREFIX, 2) == 0)
		str += 2;
	if (get_first_hex_letter_case(str) == LOWER_CASE)
		base = HEX_LOWER_BASE;
	else if (get_first_hex_letter_case(str) == UPPER_CASE)
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
	if (has_invalid_sign(str))
		return (FALSE);
	if (!is_hex_base_str(str))
		return (FALSE);
	if (str[0] == '-')
	{
		str++;
		if (convert_hex_str_to_int(str) != 0)
			return (FALSE);
	}
	else if (!is_hex_under_int_max(str))
		return (FALSE);
	return (TRUE);
}
