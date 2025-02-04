#ifndef STAB_LOAD_FDF_H
# define STAB_LOAD_FDF_H

# include "fdf.h"
# include <unistd.h>

void		forced_error_exit(const char *err_msg, const char *file, int line);
void		read_fdf_lines(t_model_fdf *fdf, int fd);
int			open_or_exit(const char *path, const char *file, int line);
void		sys_func_error_exit(const char *err_msg, const char *file,
				int line);
char		*custom_get_next_line(int fd);
void		flush_get_next_line(int fd);

int			close(int fd);

t_model_fdf	calc_max_min_xyz(t_model_fdf fdf);

#endif