#include "helper_load_fdf.h"

// #define OOE 22
// #define FEE 25
#define OOE 60
#define FEE 63

void	setup_calc_max_x_raw(char *fdf_path, char *first_line)
{
	char	*run_file;
	int		fd;

	run_file = "src/src/load_fdf.c";
	fd = 3;
	open_or_exit_ExpectAndReturn(fdf_path, run_file, OOE, fd);
	custom_get_next_line_ExpectAndReturn(fd, first_line);
	flush_get_next_line_Expect(fd);
	close_ExpectAndReturn(fd, 0);
}

void	setup_calc_max_x_raw_with_error(char *fdf_path, char *first_line)
{
	char	*run_file;
	int		fd;

	run_file = "src/src/load_fdf.c";
	fd = 3;
	open_or_exit_ExpectAndReturn(fdf_path, run_file, OOE, fd);
	custom_get_next_line_ExpectAndReturn(fd, first_line);
	forced_error_exit_Expect("Invalid fdf file (empty file)", run_file, FEE);
	forced_error_exit_AddCallback(forced_error_exit_ABORT);
	// flush_get_next_line_Expect(fd);
	// close_ExpectAndReturn(fd, 0);
}
