#ifndef STAB_MAIN_H
# define STAB_MAIN_H

# include "fdf.h"

int			ft_printf(const char *format, ...);
void		forced_error_exit(const char *err_msg, const char *file, int line);
t_model_fdf	load_fdf(const char *fdf_path);

#endif
