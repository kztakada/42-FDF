#include "helper_load_fdf__read_fdf_lines__validate_altitude_format.h"
#include "load_fdf__read_fdf_lines__validate_altitude_format.h"

// stub
#include "mock_stab_load_fdf__read_fdf_lines__validate_altitude_format.h"

// using source file
TEST_SOURCE_FILE("ft_strlen.c")
TEST_SOURCE_FILE("ft_split.c")
TEST_SOURCE_FILE("ft_substr.c")
TEST_SOURCE_FILE("ft_memcpy.c")
TEST_SOURCE_FILE("ft_strdup.c")
TEST_SOURCE_FILE("ft_strncmp.c")
TEST_SOURCE_FILE("util.c")
TEST_SOURCE_FILE("load_fdf__read_fdf_lines__is_int_str.c")
TEST_SOURCE_FILE("load_fdf__read_fdf_lines__is_hex_str.c")

void	setUp(void){};
void	tearDown(void){};

void	test_validate_altitude_format__valid(void)
{
	SUCCESS_CASE__valid("1,0xffffff");
	SUCCESS_CASE__valid("0,0xffffff");
	SUCCESS_CASE__valid("-1,0xffffff");
	SUCCESS_CASE__valid("1,0x0");
	SUCCESS_CASE__valid("0,0x0");
	SUCCESS_CASE__valid("-1,0x0");
	SUCCESS_CASE__valid("1,0x000000");
	SUCCESS_CASE__valid("0,0x000000");
	SUCCESS_CASE__valid("-1,0x000000");
	SUCCESS_CASE__valid("1,0x00000000");
	SUCCESS_CASE__valid("0,0x00000000");
	SUCCESS_CASE__valid("-1,0x00000000");
	SUCCESS_CASE__valid("2147483647,0x00000000");
	SUCCESS_CASE__valid("-2147483648,0x00000000");
	SUCCESS_CASE__valid("1,ABCDEF");
	SUCCESS_CASE__valid("1,abcdef");
	SUCCESS_CASE__valid("1,0XABCDEF");
	SUCCESS_CASE__valid("1,0X00000");
	SUCCESS_CASE__valid("1,0xffffffff");
	SUCCESS_CASE__valid("1,0XFFFFFFFF");
	SUCCESS_CASE__valid("1,ffffffff");
	SUCCESS_CASE__valid("1,FFFFFFFF");
}

void	test_validate_altitude_format__with_error__invalid_z(void)
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
	ERROR_CASE__has_hex_lowerheader_but_not_hex("1,0x100000000");
	//
	ERROR_CASE__has_hex_upperheader_but_not_hex("1,0Xgffffff");
	ERROR_CASE__has_hex_upperheader_but_not_hex("1,0X0gffffff");
	ERROR_CASE__has_hex_upperheader_but_not_hex("1,0X00000g");
	ERROR_CASE__has_hex_upperheader_but_not_hex("1,0X000000g");
	ERROR_CASE__has_hex_upperheader_but_not_hex("1,0X0000000g");
	ERROR_CASE__has_hex_lowerheader_but_not_hex("1,0X100000000");
	//
	ERROR_CASE__has_lowerletter_but_not_hex("1,a0xffffff");
	ERROR_CASE__has_lowerletter_but_not_hex("1,a00000000");
	//
	ERROR_CASE__has_upperletter_but_not_hex("1,A0xffffff");
	ERROR_CASE__has_upperletter_but_not_hex("1,A00000000");
	//
	ERROR_CASE__is_null(NULL);
	//
	ERROR_CASE__is_empty("");
	//
	ERROR_CASE__is_too_many_delimiters("1,0xffffff,0");
}
