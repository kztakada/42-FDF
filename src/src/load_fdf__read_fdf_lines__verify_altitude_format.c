/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_fdf__read_fdf_lines__verify_altitude_f        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 01:17:41 by katakada          #+#    #+#             */
/*   Updated: 2025/02/07 00:02:44 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	is_end_of_str(const char *str)
{
	if (str == NULL)
		return (TRUE);
	if (str[0] == '\0')
		return (TRUE);
	return (FALSE);
}

int	verify_altitude_format(char *z_and_color, const char *file, int line)
{
	char	**delimited_by_comma;

	delimited_by_comma = ft_split(z_and_color, ',');
	if (delimited_by_comma == NULL)
		return (forced_error_exit("Value is NULL", file, line), FALSE);
	if (is_end_of_str(delimited_by_comma[0]))
		return (forced_error_exit("Invalid fdf file (invalid altitude value)",
				file, line), FALSE);
	if (is_int_str(delimited_by_comma[0]) == FALSE)
		return (forced_error_exit("Invalid fdf file (invalid altitude value)",
				file, line), FALSE);
	if (is_end_of_str(delimited_by_comma[1]))
		return (free_all(delimited_by_comma), TRUE);
	if (!is_end_of_str(delimited_by_comma[2]))
		return (forced_error_exit("Invalid fdf file (too many commas)", file,
				line), FALSE);
	if (is_hex_str(delimited_by_comma[1]))
		return (free_all(delimited_by_comma), TRUE);
	else
	{
		free_all(delimited_by_comma);
		forced_error_exit("Invalid fdf file (invalid altitude color value)",
			file, line);
		return (FALSE);
	}
}
