#include "helper_load_fdf__read_fdf_lines__verify_altitude_format.h"

void	error_case__is_not_numeric(char *z_and_color, int line)
{
	forced_error_exit_CMockExpect(line,
		"Invalid fdf file (invalid altitude value)", CALLER_FILE, CALLER_LINE);
	UNITY_TEST_ASSERT_EQUAL_INT(FALSE, verify_altitude_format(z_and_color,
			CALLER_FILE, CALLER_LINE), line, NULL);
}

void	error_case__has_hex_lowerheader_but_not_hex(char *z_and_color, int line)
{
	forced_error_exit_CMockExpect(line,
		"Invalid fdf file (invalid altitude color value)", EXECUTOR_FILE,
		E_LINE01);
	forced_error_exit_CMockExpect(line,
		"Invalid fdf file (invalid altitude color value)", CALLER_FILE,
		CALLER_LINE);
	UNITY_TEST_ASSERT_EQUAL_INT(FALSE, verify_altitude_format(z_and_color,
			CALLER_FILE, CALLER_LINE), line, NULL);
}

void	error_case__has_hex_upperheader_but_not_hex(char *z_and_color, int line)
{
	forced_error_exit_CMockExpect(line,
		"Invalid fdf file (invalid altitude color value)", EXECUTOR_FILE,
		E_LINE02);
	forced_error_exit_CMockExpect(line,
		"Invalid fdf file (invalid altitude color value)", CALLER_FILE,
		CALLER_LINE);
	UNITY_TEST_ASSERT_EQUAL_INT(FALSE, verify_altitude_format(z_and_color,
			CALLER_FILE, CALLER_LINE), line, NULL);
}

void	error_case__has_lowerletter_but_not_hex(char *z_and_color, int line)
{
	forced_error_exit_CMockExpect(line,
		"Invalid fdf file (invalid altitude color value)", EXECUTOR_FILE,
		E_LINE03);
	forced_error_exit_CMockExpect(line,
		"Invalid fdf file (invalid altitude color value)", CALLER_FILE,
		CALLER_LINE);
	UNITY_TEST_ASSERT_EQUAL_INT(FALSE, verify_altitude_format(z_and_color,
			CALLER_FILE, CALLER_LINE), line, NULL);
}

void	error_case__has_upperletter_but_not_hex(char *z_and_color, int line)
{
	forced_error_exit_CMockExpect(line,
		"Invalid fdf file (invalid altitude color value)", EXECUTOR_FILE,
		E_LINE04);
	forced_error_exit_CMockExpect(line,
		"Invalid fdf file (invalid altitude color value)", CALLER_FILE,
		CALLER_LINE);
	UNITY_TEST_ASSERT_EQUAL_INT(FALSE, verify_altitude_format(z_and_color,
			CALLER_FILE, CALLER_LINE), line, NULL);
}

void	error_case__is_null(char *z_and_color, int line)
{
	forced_error_exit_CMockExpect(line, "Value is NULL", CALLER_FILE,
		CALLER_LINE);
	UNITY_TEST_ASSERT_EQUAL_INT(FALSE, verify_altitude_format(z_and_color,
			CALLER_FILE, CALLER_LINE), line, NULL);
}

void	error_case__is_empty(char *z_and_color, int line)
{
	forced_error_exit_CMockExpect(line,
		"Invalid fdf file (invalid altitude value)", CALLER_FILE, CALLER_LINE);
	UNITY_TEST_ASSERT_EQUAL_INT(FALSE, verify_altitude_format(z_and_color,
			CALLER_FILE, CALLER_LINE), line, NULL);
}

void	error_case__is_too_many_delimiters(char *z_and_color, int line)
{
	forced_error_exit_CMockExpect(line,
		"Invalid fdf file (invalid altitude color value)", CALLER_FILE,
		CALLER_LINE);
	UNITY_TEST_ASSERT_EQUAL_INT(FALSE, verify_altitude_format(z_and_color,
			CALLER_FILE, CALLER_LINE), line, NULL);
}
