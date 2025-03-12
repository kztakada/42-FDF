/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_exec__draw_info__util.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:45:34 by katakada          #+#    #+#             */
/*   Updated: 2025/03/12 20:45:57 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	np_offset_x(t_view *view)
{
	return (view->offset_x * -1 + NAMEPLATE_OFFSET_X);
}

int	np_offset_y(t_view *view)
{
	return (view->offset_y * -1 + INFO_BASE_OFFSET_Y);
}
