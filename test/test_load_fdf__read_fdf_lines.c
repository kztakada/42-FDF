#include "load_fdf__read_fdf_lines.h"

// stab
#include "mock_stab_load_fdf__read_fdf_lines.h"

TEST_SOURCE_FILE("ft_isdigit.c")
TEST_SOURCE_FILE("ft_strlen.c")
TEST_SOURCE_FILE("ft_split.c")
TEST_SOURCE_FILE("ft_substr.c")
TEST_SOURCE_FILE("ft_memcpy.c")
TEST_SOURCE_FILE("ft_strdup.c")
TEST_SOURCE_FILE("ft_strncmp.c")
TEST_SOURCE_FILE("ft_atoi.c")
TEST_SOURCE_FILE("ft_atoi_base.c")
TEST_SOURCE_FILE("load_fdf__read_fdf_lines__is_int_str.c")
TEST_SOURCE_FILE("load_fdf__read_fdf_lines__is_hex_str.c")

void	setUp(void){};
void	tearDown(void){};

void	test_convert_hex_str_to_int__valid(void)
{
	TEST_ASSERT_EQUAL_INT(0xffffff, convert_hex_str_to_int("0xffffff"));
	TEST_ASSERT_EQUAL_INT(0xffffff, convert_hex_str_to_int("0XFFFFFF"));
	TEST_ASSERT_EQUAL_INT(0xffffff, convert_hex_str_to_int("ffffff"));
	TEST_ASSERT_EQUAL_INT(0xffffff, convert_hex_str_to_int("FFFFFF"));
	TEST_ASSERT_EQUAL_INT(INT_MAX, convert_hex_str_to_int("0x7fffffff"));
	TEST_ASSERT_EQUAL_INT(INT_MAX, convert_hex_str_to_int("0X7FFFFFFF"));
	TEST_ASSERT_EQUAL_INT(INT_MAX, convert_hex_str_to_int("7fffffff"));
	TEST_ASSERT_EQUAL_INT(INT_MAX, convert_hex_str_to_int("7FFFFFFF"));
}

void	test_skip_z__valid(void)
{
	TEST_ASSERT_EQUAL_STRING(",0xffffff", skip_z("1,0xffffff"));
	TEST_ASSERT_EQUAL_STRING(",0xffffff", skip_z("0,0xffffff"));
	TEST_ASSERT_EQUAL_STRING(",0xffffff", skip_z("-1,0xffffff"));
	TEST_ASSERT_EQUAL_STRING(",0x0", skip_z("1,0x0"));
	TEST_ASSERT_EQUAL_STRING(",0x0", skip_z("0,0x0"));
	TEST_ASSERT_EQUAL_STRING(",0x0", skip_z("-1,0x0"));
	TEST_ASSERT_EQUAL_STRING(",0x000000", skip_z("1,0x000000"));
	TEST_ASSERT_EQUAL_STRING(",0x000000", skip_z("0,0x000000"));
	TEST_ASSERT_EQUAL_STRING(",0x000000", skip_z("-1,0x000000"));
	TEST_ASSERT_EQUAL_STRING(",0x00000000", skip_z("1,0x00000000"));
	TEST_ASSERT_EQUAL_STRING(",0x00000000", skip_z("0,0x00000000"));
	TEST_ASSERT_EQUAL_STRING(",0x00000000", skip_z("-1,0x00000000"));
}

void	test_read_color__valid(void)
{
	TEST_ASSERT_EQUAL_INT(0xffffff, read_color("1,0xffffff"));
	TEST_ASSERT_EQUAL_INT(0xffffff, read_color("0,0xffffff"));
	TEST_ASSERT_EQUAL_INT(0xffffff, read_color("-1,0xffffff"));
	TEST_ASSERT_EQUAL_INT(0x0, read_color("1,0x0"));
	TEST_ASSERT_EQUAL_INT(0x0, read_color("0,0x0"));
	TEST_ASSERT_EQUAL_INT(0x0, read_color("-1,0x0"));
	TEST_ASSERT_EQUAL_INT(0x0, read_color("1,0x000000"));
	TEST_ASSERT_EQUAL_INT(0x0, read_color("0,0x000000"));
	TEST_ASSERT_EQUAL_INT(0x0, read_color("-1,0x000000"));
	TEST_ASSERT_EQUAL_INT(0x0, read_color("2147483647,0x00000000"));
	TEST_ASSERT_EQUAL_INT(0x0, read_color("-2147483648,0x00000000"));
	TEST_ASSERT_EQUAL_INT(0xabcdef, read_color("1,0xabcdef"));
	TEST_ASSERT_EQUAL_INT(0xabcdef, read_color("1,abcdef"));
	TEST_ASSERT_EQUAL_INT(0xabcdef, read_color("1,0XABCDEF"));
	TEST_ASSERT_EQUAL_INT(0x0, read_color("1,0X00000"));
	TEST_ASSERT_EQUAL_INT(INT_MAX, read_color("1,0x7fffffff"));
	TEST_ASSERT_EQUAL_INT(INT_MAX, read_color("1,0X7FFFFFFF"));
	TEST_ASSERT_EQUAL_INT(INT_MAX, read_color("1,7fffffff"));
	TEST_ASSERT_EQUAL_INT(INT_MAX, read_color("1,7FFFFFFF"));
	TEST_ASSERT_EQUAL_INT(INT_MAX, read_color("1,+0x7fffffff"));
	TEST_ASSERT_EQUAL_INT(INT_MAX, read_color("1,+0X7FFFFFFF"));
	TEST_ASSERT_EQUAL_INT(INT_MAX, read_color("1,+7fffffff"));
	TEST_ASSERT_EQUAL_INT(INT_MAX, read_color("1,+7FFFFFFF"));
	TEST_ASSERT_EQUAL_INT(0, read_color("1,-0"));
	TEST_ASSERT_EQUAL_INT(0, read_color("-0,-0"));
}
