/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_view__draw_line__is_out_of_view.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 00:40:17 by katakada          #+#    #+#             */
/*   Updated: 2025/02/13 00:35:20 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_out_of_view(t_line_on_view *the_line, t_view *view)
{
	t_line_on_view	inspection_line;

	inspection_line = *the_line;
	inspection_line.start_dot.x -= view->transrate_x;
	inspection_line.start_dot.y -= view->transrate_y;
	inspection_line.end_dot.x -= view->transrate_x;
	inspection_line.end_dot.y -= view->transrate_y;
	// if (is_dot_within_view(inspection_line.start_dot, view) == TRUE)
	// 	return (FALSE);
	// if (is_dot_within_view(inspection_line.end_dot, view) == TRUE)
	// 	return (FALSE);
	if (is_crossing_view(inspection_line, view) == TRUE)
		return (FALSE);
	return (TRUE);
}
