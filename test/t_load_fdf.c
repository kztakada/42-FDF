#include "load_fdf.h"
#include "unity.h"

void		setUp(void){};
void		tearDown(void){};

t_model_fdf	make_test_fdf(int size_x_raw, int size_y_raw)
{
	t_model_fdf	fdf;

	fdf.max_x_raw = size_x_raw - 1;
	fdf.max_y_raw = size_y_raw - 1;
	fdf.yx_matrix = (t_vertex_fdf **)malloc(sizeof(t_vertex_fdf *)
			* size_y_raw);
	for (int i = 0; i < size_y_raw; i++)
		fdf.yx_matrix[i] = (t_vertex_fdf *)malloc(sizeof(t_vertex_fdf)
				* size_x_raw);
	for (int y = 0; y < size_y_raw; y++)
	{
		for (int x = 0; x < size_x_raw; x++)
		{
			fdf.yx_matrix[y][x].x_raw = x;
			fdf.yx_matrix[y][x].y_raw = y;
		}
	}
	return (fdf);
}



void	test_add_balanced_x_y(void)
{
	t_model_fdf	fdf;
	t_model_fdf	result;

	fdf = make_test_fdf(3, 3);
	result = add_balanced_x_y(fdf);
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
