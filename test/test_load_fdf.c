#include "load_fdf.h"
#include "make_test_fdf.h"
#include "mock_fdf_stabs.h"
#include "mock_get_next_line_bonus.h"
#include "unity.h"

void	setUp(void){};
void	tearDown(void){};

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
