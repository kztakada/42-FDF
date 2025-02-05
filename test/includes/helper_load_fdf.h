#ifndef HELPER_LOAD_FDF_H
# define HELPER_LOAD_FDF_H

# include "mock_stab_load_fdf.h"
// support
# include "common_error_exit.h"

void	setup_for_calc_max_x_raw(char *fdf_path, char *first_line);
void	setup_verify_not_empty_with_error(char *fdf_path, char *first_line);

#endif
