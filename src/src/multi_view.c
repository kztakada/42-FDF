/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_view.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:45:45 by katakada          #+#    #+#             */
/*   Updated: 2025/03/11 17:42:06 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_multi_view(t_multi_view *multi_view, t_screen *screen)
{
	draw_view(multi_view->left_up, screen);
	draw_view(multi_view->right_up, screen);
	draw_view(multi_view->left_down, screen);
	draw_view(multi_view->right_down, screen);
}
