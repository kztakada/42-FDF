#ifndef STAB_LOAD_FDF__READ_FDF_LINES__VERIFY_ALTITUDE_FORMAT_H
# define STAB_LOAD_FDF__READ_FDF_LINES__VERIFY_ALTITUDE_FORMAT_H

void	forced_error_exit(const char *err_msg, const char *file, int line);

char	*custom_get_next_line(int fd);
#endif