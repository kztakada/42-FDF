/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_view__draw_line__is_out_of_view.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 00:40:17 by katakada          #+#    #+#             */
/*   Updated: 2025/02/02 02:11:08 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_out_of_view(t_line_on_view *the_line, t_view *view)
{
	if (is_dot_within_view(the_line->start_dot, view) == TRUE)
		return (FALSE);
	if (is_dot_within_view(the_line->end_dot, view) == TRUE)
		return (FALSE);
	if (is_crossing_view(*the_line, view) == TRUE)
		return (FALSE);
	return (TRUE);
}
