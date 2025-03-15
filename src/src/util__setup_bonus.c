/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util__setup_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 23:47:23 by katakada          #+#    #+#             */
/*   Updated: 2025/03/16 00:03:47 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static int	is_nutural_num_str(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		return (FALSE);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	setup_framerate(t_screen *screen, char *frame_rate_str)
{
	if (is_nutural_num_str(frame_rate_str) == TRUE)
		screen->settings->frame_rate = ft_atoi(frame_rate_str);
	else
		forced_error_exit("Invalid frame rate (nonnegative integer only)",
			__FILE__, __LINE__);
}