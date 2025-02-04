#include "common_make_test_fdf.h"

t_model_fdf	make_test_fdf_xy_raw(int size_x_raw, int size_y_raw)
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

t_model_fdf	make_test_fdf_for_max_min_xyz(int size_x_raw, int size_y_raw)
{
	t_model_fdf	fdf;
	int			first_x;
	int			first_y;
	int			z_i;

	fdf = make_test_fdf_xy_raw(size_x_raw, size_y_raw);
	first_x = 0 - fdf.max_x_raw / 2;
	first_y = 0 - fdf.max_y_raw / 2;
	z_i = 1;
	for (int y = 0; y < size_y_raw; y++)
	{
		for (int x = 0; x < size_x_raw; x++)
		{
			fdf.yx_matrix[y][x].x = first_x + x;
			fdf.yx_matrix[y][x].y = first_y + y;
			fdf.yx_matrix[y][x].z = z_i;
			z_i++;
		}
	}
	return (fdf);
}
