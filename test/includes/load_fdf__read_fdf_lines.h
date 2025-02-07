#ifndef LOAD_FDF__READ_FDF_LINES_H
# define LOAD_FDF__READ_FDF_LINES_H

# include "fdf.h"
// tester
# include "unity.h"

int		convert_hex_str_to_int(const char *hex_str);
char	*skip_z(char *z_and_color);
int		read_color(char *verified_altitude);

#endif