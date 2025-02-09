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
TEST_SOURCE_FILE("ft_atoi_base.c")
TEST_SOURCE_FILE("ft_isdigit.c")
TEST_SOURCE_FILE("ft_atoi.c")
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
	SUCCESS_CASE__valid("1,0x7fffffff");
	SUCCESS_CASE__valid("1,0X7FFFFFFF");
	SUCCESS_CASE__valid("1,7fffffff");
	SUCCESS_CASE__valid("1,7FFFFFFF");
	SUCCESS_CASE__valid("1,+0x7fffffff");
	SUCCESS_CASE__valid("1,+0X7FFFFFFF");
	SUCCESS_CASE__valid("1,+7fffffff");
	SUCCESS_CASE__valid("1,+7FFFFFFF");
	SUCCESS_CASE__valid("1,-0");
	SUCCESS_CASE__valid("-0,-0");
	SUCCESS_CASE__valid("1,0xFFFFFF");
	SUCCESS_CASE__valid("1,0Xffffff");
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
	ERROR_CASE__has_hex_lowerheader_but_not_hex("1,0x80000000");
	ERROR_CASE__has_hex_lowerheader_but_not_hex("1,0x0XFF");
	ERROR_CASE__has_hex_lowerheader_but_not_hex("1,0x0Xff");
	ERROR_CASE__has_hex_lowerheader_but_not_hex("1,-0xFF");
	ERROR_CASE__has_hex_lowerheader_but_not_hex("1,--0xFF");
	ERROR_CASE__has_hex_lowerheader_but_not_hex("1,0x-ff");
	ERROR_CASE__has_hex_lowerheader_but_not_hex("1,0x+ff");
	ERROR_CASE__has_hex_lowerheader_but_not_hex("1,++0xFF");
	//
	ERROR_CASE__has_hex_upperheader_but_not_hex("1,0Xgffffff");
	ERROR_CASE__has_hex_upperheader_but_not_hex("1,0X0gffffff");
	ERROR_CASE__has_hex_upperheader_but_not_hex("1,0X00000g");
	ERROR_CASE__has_hex_upperheader_but_not_hex("1,0X000000g");
	ERROR_CASE__has_hex_upperheader_but_not_hex("1,0X0000000g");
	ERROR_CASE__has_hex_upperheader_but_not_hex("1,0X100000000");
	ERROR_CASE__has_hex_upperheader_but_not_hex("1,0X80000000");
	ERROR_CASE__has_hex_upperheader_but_not_hex("1,0X0xFF");
	ERROR_CASE__has_hex_upperheader_but_not_hex("1,0X0xff");
	ERROR_CASE__has_hex_upperheader_but_not_hex("1,-0XFF");
	ERROR_CASE__has_hex_upperheader_but_not_hex("1,--0XFF");
	ERROR_CASE__has_hex_upperheader_but_not_hex("1,++0XFF");
	//
	ERROR_CASE__has_lowerletter_but_not_hex("1,a0xffffff");
	ERROR_CASE__has_lowerletter_but_not_hex("1,a0XFFFFFF");
	ERROR_CASE__has_lowerletter_but_not_hex("1,a00000000");
	ERROR_CASE__has_lowerletter_but_not_hex("1,8000000a");
	ERROR_CASE__has_lowerletter_but_not_hex("1,aBcdEf");
	ERROR_CASE__has_lowerletter_but_not_hex("1,-ff");
	ERROR_CASE__has_lowerletter_but_not_hex("1,--ff");
	ERROR_CASE__has_lowerletter_but_not_hex("1,++ff");
	//
	ERROR_CASE__has_upperletter_but_not_hex("1,A0xffffff");
	ERROR_CASE__has_upperletter_but_not_hex("1,A0XFFFFFF");
	ERROR_CASE__has_upperletter_but_not_hex("1,A00000000");
	ERROR_CASE__has_upperletter_but_not_hex("1,8000000A");
	ERROR_CASE__has_upperletter_but_not_hex("1,AbCdEf");
	ERROR_CASE__has_upperletter_but_not_hex("1,-FF");
	ERROR_CASE__has_upperletter_but_not_hex("1,--FF");
	ERROR_CASE__has_upperletter_but_not_hex("1,++FF");
	//
	ERROR_CASE__is_null(NULL);
	//
	ERROR_CASE__is_empty("");
	//
	ERROR_CASE__is_too_many_delimiters("1,0xffffff,0");
}
