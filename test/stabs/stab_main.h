#ifndef STAB_MAIN_H
# define STAB_MAIN_H

# include "fdf.h"

int			ft_printf(const char *format, ...);
t_model_fdf	load_fdf(const char *fdf_path);

#endif
