#ifndef LOAD_FDF_H
# define LOAD_FDF_H

// tester
# include "unity.h"
// support
# include "common_error_exit.h"
# include "common_make_test_fdf.h"

int			verify_not_empty_and_calc_max_x_raw(const char *fdf_path);
t_model_fdf	calc_balanced_x_y(t_model_fdf fdf);

#endif
