#include "helper_load_fdf.h"
#include "load_fdf.h"

// stub
#include "mock_stab_load_fdf.h"

// using source file
TEST_SOURCE_FILE("ft_strlen.c")
TEST_SOURCE_FILE("ft_split.c")
TEST_SOURCE_FILE("ft_substr.c")
TEST_SOURCE_FILE("ft_memcpy.c")
TEST_SOURCE_FILE("ft_strdup.c")

void	setUp(void){};
void	tearDown(void){};

// calc_max_x_raw()
void	test_calc_max_x_raw(void)
{
	char	*fdf_path;

	fdf_path = "test.fdf";
	setup_calc_max_x_raw(fdf_path, "1 2 3");
	TEST_ASSERT_EQUAL_INT(2, calc_max_x_raw(fdf_path));
	setup_calc_max_x_raw(fdf_path, "1 2 3 ");
	TEST_ASSERT_EQUAL_INT(2, calc_max_x_raw(fdf_path));
	setup_calc_max_x_raw(fdf_path, "1 2 3 4 ");
	TEST_ASSERT_EQUAL_INT(3, calc_max_x_raw(fdf_path));
	setup_calc_max_x_raw(fdf_path, "    1       2  3     4        ");
	TEST_ASSERT_EQUAL_INT(3, calc_max_x_raw(fdf_path));
	setup_calc_max_x_raw(fdf_path, "-6 -67 -61 -38 9 -16 -16 32 56 16 ");
	TEST_ASSERT_EQUAL_INT(9, calc_max_x_raw(fdf_path));
	setup_calc_max_x_raw(fdf_path, "1,0xffffff");
	TEST_ASSERT_EQUAL_INT(0, calc_max_x_raw(fdf_path));
	setup_calc_max_x_raw(fdf_path, "1,0xff 1,0xff 0,0xff");
	TEST_ASSERT_EQUAL_INT(2, calc_max_x_raw(fdf_path));
	setup_calc_max_x_raw(fdf_path,
		" 1,0xff 1,0xff 0,0xff 0,0xff 0,0xff0 6,0xff00 10,0xff00 19,0xff00 21,0xff00 25,0xff00 28,0xff00 35,0xff00 39,0xff00 39,0xff00 40,0x802020 51,0x802020 50,0x802020 52,0x802020 56,0x802020 47,0x802020 51,0x802020 45,0x802020 57,0x802020 63,0x802020 70,0xffffff 99,0xffffff 94,0xffffff 77,0xffffff 133,0xffffff 121,0xffffff 83,0xffffff 86,0xffffff 74,0xffffff 68,0x802020 62,0x802020 55,0x802020 91,0xffffff 84,0xffffff 81,0xffffff 83,0xffffff 53,0x802020 61,0x802020");
	TEST_ASSERT_EQUAL_INT(41, calc_max_x_raw(fdf_path));
}

void	test_calc_max_x_raw_with_error__NULL(void)
{
	char	*fdf_path;

	fdf_path = "test.fdf";
	setup_calc_max_x_raw_with_error(fdf_path, NULL);
	if (TEST_PROTECT())
		calc_max_x_raw(fdf_path);
}

void	test_calc_max_x_raw_with_error__EMPTY(void)
{
	char	*fdf_path;

	fdf_path = "test.fdf";
	setup_calc_max_x_raw_with_error(fdf_path, "");
	if (TEST_PROTECT())
		calc_max_x_raw(fdf_path);
}

// calc_balanced_x_y()
void	test_calc_balanced_x_y(void)
{
	t_model_fdf	fdf;
	t_model_fdf	result;

	fdf = make_test_fdf_xy_raw(3, 3);
	result = calc_balanced_x_y(fdf);
	TEST_ASSERT_EQUAL_INT(-1, result.yx_matrix[0][0].x);
	TEST_ASSERT_EQUAL_INT(0, result.yx_matrix[0][1].x);
	TEST_ASSERT_EQUAL_INT(1, result.yx_matrix[0][2].x);
	TEST_ASSERT_EQUAL_INT(-1, result.yx_matrix[1][0].x);
	TEST_ASSERT_EQUAL_INT(0, result.yx_matrix[1][1].x);
	TEST_ASSERT_EQUAL_INT(1, result.yx_matrix[1][2].x);
	TEST_ASSERT_EQUAL_INT(-1, result.yx_matrix[2][0].x);
	TEST_ASSERT_EQUAL_INT(0, result.yx_matrix[2][1].x);
	TEST_ASSERT_EQUAL_INT(1, result.yx_matrix[2][2].x);
	TEST_ASSERT_EQUAL_INT(-1, result.yx_matrix[0][0].y);
	TEST_ASSERT_EQUAL_INT(-1, result.yx_matrix[0][1].y);
	TEST_ASSERT_EQUAL_INT(-1, result.yx_matrix[0][2].y);
	TEST_ASSERT_EQUAL_INT(0, result.yx_matrix[1][0].y);
	TEST_ASSERT_EQUAL_INT(0, result.yx_matrix[1][1].y);
	TEST_ASSERT_EQUAL_INT(0, result.yx_matrix[1][2].y);
	TEST_ASSERT_EQUAL_INT(1, result.yx_matrix[2][0].y);
	TEST_ASSERT_EQUAL_INT(1, result.yx_matrix[2][1].y);
	TEST_ASSERT_EQUAL_INT(1, result.yx_matrix[2][2].y);
	for (int i = 0; i < 3; i++)
		free(fdf.yx_matrix[i]);
	free(fdf.yx_matrix);
}
