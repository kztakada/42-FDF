#ifndef FDF_STABS_H
# define FDF_STABS_H
# include "../includes/fdf.h"

void	forced_error_exit(const char *err_msg, const char *file, int line);
void	load_lines(t_model_fdf *fdf, int fd);
int		open_or_exit(const char *path, const char *file, int line);
void	sys_func_error_exit(const char *err_msg, const char *file, int line);

#endif