#include "helper_load_fdf__read_fdf_lines__validate_altitude_format.h"

void	success_case__valid(char *z_and_color, int line)
{
	UNITY_TEST_ASSERT_EQUAL_INT(TRUE, validate_altitude_format(z_and_color,
			CALLER_FILE, CALLER_LINE), line, NULL);
}

void	error_case__is_not_numeric(char *z_and_color, int line)
{
	forced_error_exit_CMockExpect(line,
		"Invalid fdf file (invalid altitude value)", CALLER_FILE, CALLER_LINE);
	UNITY_TEST_ASSERT_EQUAL_INT(FALSE, validate_altitude_format(z_and_color,
			CALLER_FILE, CALLER_LINE), line, NULL);
}

void	error_case__has_hex_lowerheader_but_not_hex(char *z_and_color, int line)
{
	forced_error_exit_CMockExpect(line,
		"Invalid fdf file (invalid altitude color value)", CALLER_FILE,
		CALLER_LINE);
	UNITY_TEST_ASSERT_EQUAL_INT(FALSE, validate_altitude_format(z_and_color,
			CALLER_FILE, CALLER_LINE), line, NULL);
}

void	error_case__has_hex_upperheader_but_not_hex(char *z_and_color, int line)
{
	forced_error_exit_CMockExpect(line,
		"Invalid fdf file (invalid altitude color value)", CALLER_FILE,
		CALLER_LINE);
	UNITY_TEST_ASSERT_EQUAL_INT(FALSE, validate_altitude_format(z_and_color,
			CALLER_FILE, CALLER_LINE), line, NULL);
}

void	error_case__has_lowerletter_but_not_hex(char *z_and_color, int line)
{
	forced_error_exit_CMockExpect(line,
		"Invalid fdf file (invalid altitude color value)", CALLER_FILE,
		CALLER_LINE);
	UNITY_TEST_ASSERT_EQUAL_INT(FALSE, validate_altitude_format(z_and_color,
			CALLER_FILE, CALLER_LINE), line, NULL);
}

void	error_case__has_upperletter_but_not_hex(char *z_and_color, int line)
{
	forced_error_exit_CMockExpect(line,
		"Invalid fdf file (invalid altitude color value)", CALLER_FILE,
		CALLER_LINE);
	UNITY_TEST_ASSERT_EQUAL_INT(FALSE, validate_altitude_format(z_and_color,
			CALLER_FILE, CALLER_LINE), line, NULL);
}

void	error_case__is_null(char *z_and_color, int line)
{
	forced_error_exit_CMockExpect(line, "Value is NULL", CALLER_FILE,
		CALLER_LINE);
	UNITY_TEST_ASSERT_EQUAL_INT(FALSE, validate_altitude_format(z_and_color,
			CALLER_FILE, CALLER_LINE), line, NULL);
}

void	error_case__is_empty(char *z_and_color, int line)
{
	forced_error_exit_CMockExpect(line,
		"Invalid fdf file (invalid altitude value)", CALLER_FILE, CALLER_LINE);
	UNITY_TEST_ASSERT_EQUAL_INT(FALSE, validate_altitude_format(z_and_color,
			CALLER_FILE, CALLER_LINE), line, NULL);
}

void	error_case__is_too_many_delimiters(char *z_and_color, int line)
{
	forced_error_exit_CMockExpect(line, "Invalid fdf file (too many commas)",
		CALLER_FILE, CALLER_LINE);
	UNITY_TEST_ASSERT_EQUAL_INT(FALSE, validate_altitude_format(z_and_color,
			CALLER_FILE, CALLER_LINE), line, NULL);
}
