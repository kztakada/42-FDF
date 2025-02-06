#ifndef HELPER_LOAD_FDF__READ_FDF_LINES__VERIFY_ALTITUDE_FORMAT_H
# define HELPER_LOAD_FDF__READ_FDF_LINES__VERIFY_ALTITUDE_FORMAT_H

#include "fdf.h"

#include "mock_stab_load_fdf__read_fdf_lines__verify_altitude_format.h"
// support
# include "common_error_exit.h"

#define SUCCESS_CASE__valid(z_a_color) success_case__valid((z_a_color),(__LINE__))
#define ERROR_CASE__is_not_numeric(z_a_color) error_case__is_not_numeric((z_a_color),(__LINE__))
#define ERROR_CASE__has_hex_lowerheader_but_not_hex(z_a_color) error_case__has_hex_lowerheader_but_not_hex((z_a_color),(__LINE__))
#define ERROR_CASE__has_hex_upperheader_but_not_hex(z_a_color) error_case__has_hex_upperheader_but_not_hex((z_a_color),(__LINE__))
#define ERROR_CASE__has_lowerletter_but_not_hex(z_a_color) error_case__has_lowerletter_but_not_hex((z_a_color),(__LINE__))
#define ERROR_CASE__has_upperletter_but_not_hex(z_a_color) error_case__has_upperletter_but_not_hex((z_a_color),(__LINE__))
#define ERROR_CASE__is_null(z_a_color) error_case__is_null((z_a_color),(__LINE__))
#define ERROR_CASE__is_empty(z_a_color) error_case__is_empty((z_a_color),(__LINE__))
#define ERROR_CASE__is_too_many_delimiters(z_a_color) error_case__is_too_many_delimiters((z_a_color),(__LINE__))

// error functions
#define E_LINE01 46 // is_hex_base_str(str, HEX_LOWER_BASE, ...)
#define E_LINE02 (E_LINE01 + 5) // is_hex_base_str(str, HEX_UPPER_BASE, ...)
#define E_LINE03 (E_LINE01 + 13) // is_hex_base_str(str, HEX_LOWER_BASE, ...)
#define E_LINE04 (E_LINE01 + 15) // is_hex_base_str(str, HEX_UPPER_BASE, ...)

#define CALLER_FILE "src/src/load_fdf__read_fdf_lines.c"
#define CALLER_LINE 74

#define EXECUTOR_FILE "src/src/load_fdf__read_fdf_lines__verify_altitude_format.c"

void	success_case__valid(char *z_and_color, int line);
void	error_case__is_not_numeric(char *z_and_color, int line);
void	error_case__has_hex_lowerheader_but_not_hex(char *z_and_color, int line);
void	error_case__has_hex_upperheader_but_not_hex(char *z_and_color, int line);
void	error_case__has_lowerletter_but_not_hex(char *z_and_color, int line);
void	error_case__has_upperletter_but_not_hex(char *z_and_color, int line);
void	error_case__is_null(char *z_and_color, int line);
void	error_case__is_empty(char *z_and_color, int line);
void	error_case__is_too_many_delimiters(char *z_and_color, int line);

#endif