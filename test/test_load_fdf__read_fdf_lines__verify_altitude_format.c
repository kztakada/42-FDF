#include "helper_load_fdf__read_fdf_lines__verify_altitude_format.h"
#include "load_fdf__read_fdf_lines__verify_altitude_format.h"

// stub
#include "mock_stab_load_fdf__read_fdf_lines__verify_altitude_format.h"

// using source file
TEST_SOURCE_FILE("ft_strlen.c")
TEST_SOURCE_FILE("ft_split.c")
TEST_SOURCE_FILE("ft_substr.c")
TEST_SOURCE_FILE("ft_memcpy.c")
TEST_SOURCE_FILE("ft_strdup.c")
TEST_SOURCE_FILE("ft_strncmp.c")
TEST_SOURCE_FILE("util.c")
TEST_SOURCE_FILE("load_fdf__read_fdf_lines__util.c")

void	setUp(void){};
void	tearDown(void){};

void	test_verify_altitude_format__valid(void)
{
	char	*z_and_color;
	char	*file;
	int		line;

	z_and_color = "1,0xffffff";
	file = "src/src/load_fdf__read_fdf_lines__verify_altitude_format.c";
	line = 52;
	TEST_ASSERT_EQUAL_INT(TRUE, verify_altitude_format(z_and_color, file,
			line));
	z_and_color = "0,0xffffff";
	TEST_ASSERT_EQUAL_INT(TRUE, verify_altitude_format(z_and_color, file,
			line));
	z_and_color = "-1,0xffffff";
	TEST_ASSERT_EQUAL_INT(TRUE, verify_altitude_format(z_and_color, file,
			line));
	z_and_color = "1,0x0";
	TEST_ASSERT_EQUAL_INT(TRUE, verify_altitude_format(z_and_color, file,
			line));
	z_and_color = "0,0x0";
	TEST_ASSERT_EQUAL_INT(TRUE, verify_altitude_format(z_and_color, file,
			line));
	z_and_color = "-1,0x0";
	TEST_ASSERT_EQUAL_INT(TRUE, verify_altitude_format(z_and_color, file,
			line));
	z_and_color = "1,0x000000";
	TEST_ASSERT_EQUAL_INT(TRUE, verify_altitude_format(z_and_color, file,
			line));
	z_and_color = "0,0x000000";
	TEST_ASSERT_EQUAL_INT(TRUE, verify_altitude_format(z_and_color, file,
			line));
	z_and_color = "-1,0x000000";
	TEST_ASSERT_EQUAL_INT(TRUE, verify_altitude_format(z_and_color, file,
			line));
	z_and_color = "1,0x00000000";
	TEST_ASSERT_EQUAL_INT(TRUE, verify_altitude_format(z_and_color, file,
			line));
	z_and_color = "0,0x00000000";
	TEST_ASSERT_EQUAL_INT(TRUE, verify_altitude_format(z_and_color, file,
			line));
	z_and_color = "-1,0x00000000";
	TEST_ASSERT_EQUAL_INT(TRUE, verify_altitude_format(z_and_color, file,
			line));
}

void	test_verify_altitude_format__with_error__invalid_z(void)
{
	//
	ERROR_CASE__is_not_numeric("a,0xffffff");
	ERROR_CASE__is_not_numeric("--1,0xffffff");
	ERROR_CASE__is_not_numeric("1a,0xffffff");
	ERROR_CASE__is_not_numeric("1-,0xffffff");
	ERROR_CASE__is_not_numeric("1000000000000000000000000000000,0xffffff");
	ERROR_CASE__is_not_numeric("-1000000000000000000000000000000,0xffffff");
	//
	ERROR_CASE__has_hex_lowerheader_but_not_hex("1,0xgffffff");
	ERROR_CASE__has_hex_lowerheader_but_not_hex("1,0x0gffffff");
	ERROR_CASE__has_hex_lowerheader_but_not_hex("1,0x00000g");
	ERROR_CASE__has_hex_lowerheader_but_not_hex("1,0x000000g");
	ERROR_CASE__has_hex_lowerheader_but_not_hex("1,0x0000000g");
	//
	ERROR_CASE__has_hex_upperheader_but_not_hex("1,0Xgffffff");
	ERROR_CASE__has_hex_upperheader_but_not_hex("1,0X0gffffff");
	ERROR_CASE__has_hex_upperheader_but_not_hex("1,0X00000g");
	ERROR_CASE__has_hex_upperheader_but_not_hex("1,0X000000g");
	ERROR_CASE__has_hex_upperheader_but_not_hex("1,0X0000000g");
	//
	ERROR_CASE__has_lowerletter_but_not_hex("1,a0xffffff");
	//
	ERROR_CASE__has_upperletter_but_not_hex("1,A0xffffff");
	//
	ERROR_CASE__is_null(NULL);
	//
	ERROR_CASE__is_empty("");
	//
	ERROR_CASE__is_too_many_delimiters("1,0xffffff,0");
}
