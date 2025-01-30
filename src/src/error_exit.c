/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 23:41:28 by katakada          #+#    #+#             */
/*   Updated: 2025/01/29 14:04:43 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	print_debugging(const char *file, int line)
{
	if (IS_DEBUG)
		ft_dprintf(STDERR_FILENO, "Error: File: %s, Line: %d\n", file, line);
}

void	sys_func_error_exit(const char *err_msg, const char *file, int line)
{
	perror(err_msg);
	print_debugging(file, line);
	exit(1);
}

void	forced_error_exit(const char *err_msg, const char *file, int line)
{
	ft_dprintf(STDERR_FILENO, "Error: %s\n", err_msg);
	print_debugging(file, line);
	exit(1);
}
