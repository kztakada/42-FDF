/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util__fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 00:10:17 by katakada          #+#    #+#             */
/*   Updated: 2025/02/01 01:31:58 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vertex_fdf	*get_vertex_fdf(int x_raw, int y_raw, t_model_fdf *fdf)
{
	if (&(fdf->yx_matrix[y_raw][x_raw]) == NULL)
		return (NULL);
	else
		return (&(fdf->yx_matrix[y_raw][x_raw]));
}
