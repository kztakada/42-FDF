#ifndef STAB_LOAD_FDF__READ_FDF_LINES_H
# define STAB_LOAD_FDF__READ_FDF_LINES_H

void	forced_error_exit(const char *err_msg, const char *file, int line);
void	sys_func_error_exit(const char *err_msg, const char *file, int line);

int		validate_altitude_format(char *z_and_color, const char *file, int line);

char	*custom_get_next_line(int fd);

int		ft_printf(const char *format, ...);

#endif