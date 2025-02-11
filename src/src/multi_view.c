/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_view.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:45:45 by katakada          #+#    #+#             */
/*   Updated: 2025/02/11 18:45:46 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_multi_view(t_multi_view *multi_view, t_image *image)
{
	draw_view(multi_view->left_up, image);
	draw_view(multi_view->right_up, image);
	draw_view(multi_view->left_down, image);
	draw_view(multi_view->right_down, image);
}
