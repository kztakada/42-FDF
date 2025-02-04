#ifndef LOAD_FDF__CALC_MAX_MIN_XYZ_H
# define LOAD_FDF__CALC_MAX_MIN_XYZ_H

# include "fdf.h"
// tester includes
# include "unity.h"
// support includes
# include "common_error_exit.h"
# include "common_make_test_fdf.h"

t_model_fdf	calc_max_min_z(t_model_fdf fdf);
t_model_fdf	calc_max_min_x(t_model_fdf fdf);
t_model_fdf	calc_max_min_y(t_model_fdf fdf);
#endif