/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:57:01 by katakada          #+#    #+#             */
/*   Updated: 2025/01/22 01:18:18 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vertex_fdf	get_vertex_fdf(int x_raw, int y_raw, t_model_fdf *fdf)
{
	if (x_raw < 0 || y_raw < 0)
		return ((t_vertex_fdf){x_raw, y_raw, NULL, NULL, NULL, NULL});
	if (x_raw > fdf->max_x_raw || y_raw > fdf->max_y_raw)
		return ((t_vertex_fdf){x_raw, y_raw, NULL, NULL, NULL, NULL});
	return (fdf->yx_matrix[y_raw][x_raw]);
}
