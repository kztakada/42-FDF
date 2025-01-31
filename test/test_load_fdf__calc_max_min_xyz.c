#include "load_fdf__calc_max_min_xyz.h"
#include "make_test_fdf.h"
#include "unity.h"

void	setUp(void){};
void	tearDown(void){};

void	test_calc_max_min_z(void)
{
	t_model_fdf	fdf;
	t_model_fdf	result;

	// test 3x3
	fdf = make_test_fdf_for_max_min_xyz(3, 3);
	TEST_ASSERT_EQUAL_INT(1, fdf.yx_matrix[0][0].z);
	result = calc_max_min_z(fdf);
	TEST_ASSERT_EQUAL_INT(1, result.min_z);
	TEST_ASSERT_EQUAL_INT(9, result.max_z);
	for (int i = 0; i < 3; i++)
		free(fdf.yx_matrix[i]);
	free(fdf.yx_matrix);
	// test 4x4
	fdf = make_test_fdf_for_max_min_xyz(4, 4);
	TEST_ASSERT_EQUAL_INT(1, fdf.yx_matrix[0][0].z);
	result = calc_max_min_z(fdf);
	TEST_ASSERT_EQUAL_INT(1, result.min_z);
	TEST_ASSERT_EQUAL_INT(16, result.max_z);
	for (int i = 0; i < 4; i++)
		free(fdf.yx_matrix[i]);
	free(fdf.yx_matrix);
	// test 5x6
	fdf = make_test_fdf_for_max_min_xyz(5, 6);
	TEST_ASSERT_EQUAL_INT(1, fdf.yx_matrix[0][0].z);
	result = calc_max_min_z(fdf);
	TEST_ASSERT_EQUAL_INT(1, result.min_z);
	TEST_ASSERT_EQUAL_INT(30, result.max_z);
	for (int i = 0; i < 6; i++)
		free(fdf.yx_matrix[i]);
	free(fdf.yx_matrix);
}

void	test_calc_max_min_x(void)
{
	t_model_fdf	fdf;
	t_model_fdf	result;

	// test 3x3
	fdf = make_test_fdf_for_max_min_xyz(3, 3);
	TEST_ASSERT_EQUAL_INT(-1, fdf.yx_matrix[0][0].x);
	result = calc_max_min_x(fdf);
	TEST_ASSERT_EQUAL_INT(-1, result.min_x);
	TEST_ASSERT_EQUAL_INT(1, result.max_x);
	for (int i = 0; i < 3; i++)
		free(fdf.yx_matrix[i]);
	free(fdf.yx_matrix);
	// test 4x4
	fdf = make_test_fdf_for_max_min_xyz(4, 4);
	TEST_ASSERT_EQUAL_INT(-1, fdf.yx_matrix[0][0].x);
	result = calc_max_min_x(fdf);
	TEST_ASSERT_EQUAL_INT(-1, result.min_x);
	TEST_ASSERT_EQUAL_INT(2, result.max_x);
	for (int i = 0; i < 4; i++)
		free(fdf.yx_matrix[i]);
	free(fdf.yx_matrix);
	// test 5x6
	fdf = make_test_fdf_for_max_min_xyz(5, 6);
	TEST_ASSERT_EQUAL_INT(-2, fdf.yx_matrix[0][0].x);
	result = calc_max_min_x(fdf);
	TEST_ASSERT_EQUAL_INT(-2, result.min_x);
	TEST_ASSERT_EQUAL_INT(2, result.max_x);
	for (int i = 0; i < 6; i++)
		free(fdf.yx_matrix[i]);
	free(fdf.yx_matrix);
}

void	test_calc_max_min_y(void)
{
	t_model_fdf	fdf;
	t_model_fdf	result;

	// test 3x3
	fdf = make_test_fdf_for_max_min_xyz(3, 3);
	TEST_ASSERT_EQUAL_INT(-1, fdf.yx_matrix[0][0].y);
	result = calc_max_min_y(fdf);
	TEST_ASSERT_EQUAL_INT(-1, result.min_y);
	TEST_ASSERT_EQUAL_INT(1, result.max_y);
	for (int i = 0; i < 3; i++)
		free(fdf.yx_matrix[i]);
	free(fdf.yx_matrix);
	// test 4x4
	fdf = make_test_fdf_for_max_min_xyz(4, 4);
	TEST_ASSERT_EQUAL_INT(-1, fdf.yx_matrix[0][0].y);
	result = calc_max_min_y(fdf);
	TEST_ASSERT_EQUAL_INT(-1, result.min_y);
	TEST_ASSERT_EQUAL_INT(2, result.max_y);
	for (int i = 0; i < 4; i++)
		free(fdf.yx_matrix[i]);
	free(fdf.yx_matrix);
	// test 5x6
	fdf = make_test_fdf_for_max_min_xyz(5, 6);
	TEST_ASSERT_EQUAL_INT(-2, fdf.yx_matrix[0][0].y);
	result = calc_max_min_y(fdf);
	TEST_ASSERT_EQUAL_INT(-2, result.min_y);
	TEST_ASSERT_EQUAL_INT(3, result.max_y);
	for (int i = 0; i < 6; i++)
		free(fdf.yx_matrix[i]);
	free(fdf.yx_matrix);
}
