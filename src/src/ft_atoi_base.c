/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 23:31:48 by katakada          #+#    #+#             */
/*   Updated: 2025/01/30 12:23:08 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	is_invalid_char(const char c)
{
	if (c == '-' || c == '+')
		return (1);
	if (c == ' ' || (c >= '\t' && c <= '\r'))
		return (1);
	return (0);
}

static int	has_same_char(const char *str, const char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	is_invalid_base(const char *str)
{
	int	i;

	if (str[0] == '\0' || str[1] == '\0')
		return (1);
	i = 0;
	while (str[i] != '\0')
	{
		if (is_invalid_char(str[i]))
			return (1);
		if (has_same_char(str + i + 1, str[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	char_to_base_int(const char c, const char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			break ;
		i++;
	}
	if (base[i] != '\0')
		return (i);
	else
		return (-1);
}

unsigned int	ft_atoi_base(const char *str_src, const char *base)
{
	unsigned int	result;
	const char		*str_pos;

	str_pos = str_src;
	if (is_invalid_base(base))
		return (0);
	while ((*str_pos == ' ' || (*str_pos >= '\t' && *str_pos <= '\r')))
		str_pos++;
	if ((ft_strncmp(str_pos, HEX_LOWER_PREFIX, 2) == 0 && ft_strncmp(base,
				HEX_LOWER_BASE, 16) == 0) || (ft_strncmp(str_pos,
				HEX_UPPER_PREFIX, 2) == 0 && ft_strncmp(base, HEX_UPPER_BASE,
				16) == 0))
		str_pos += 2;
	result = 0;
	while (*str_pos != '\0')
	{
		if (char_to_base_int(*str_pos, base) >= 0)
			result = (result * ft_strlen(base)) + char_to_base_int(*str_pos,
					base);
		else
			break ;
		str_pos++;
	}
	return (result);
}
