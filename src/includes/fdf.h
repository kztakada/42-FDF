/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:58:01 by katakada          #+#    #+#             */
/*   Updated: 2025/01/31 23:51:21 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include "./mlx.h"
# include <math.h>
# include <stdio.h>

# ifdef TEST
#  define static
# endif

# define TRUE 1
# define FALSE 0

# define IS_DEBUG 1

# define LEFT_UP 0
# define RIGHT_UP 1
# define LEFT_DOWN 2
# define RIGHT_DOWN 3

# define Z_HEIGHT_RATIO 10

// hex base upper and lower
# define HEX_LOWER_PREFIX "0x"
# define HEX_UPPER_PREFIX "0X"
# define HEX_LOWER_BASE "0123456789abcdef"
# define HEX_UPPER_BASE "0123456789ABCDEF"

// model colors are 5 levels
# define COLOR_L0 0x432371
# define COLOR_L1 0x714674
# define COLOR_L2 0x9F6976
# define COLOR_L3 0xCC8B79
# define COLOR_L4 0xFAAE7B

// screen size
# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080

// .fdf format
// Notice ////////////////////////////////////////////////////////////////////
// Raw data in fdf format always has starting x and y values of 0 and		//
// never takes negative values.												//
//																			//
// x and y in t_vertex_fdf are the corrected values of the center origin	//
// from the respective raw data.											//
// z does not need to be corrected.											//
//																			//
// If no color is specified, the color value is -1							//
//////////////////////////////////////////////////////////////////////////////
typedef struct s_vertex_fdf
{
	// inside fdf file
	int				x_raw;
	int				y_raw;
	int				color;
	int				z;
	// balanced Value (Center of Gravity Correction Value)
	int				x;
	int				y;
}					t_vertex_fdf;
typedef struct s_model_fdf
{
	t_vertex_fdf	**yx_matrix;
	int				max_x_raw;
	int				max_y_raw;
	int				max_x;
	int				max_y;
	int				max_z;
	int				min_x;
	int				min_y;
	int				min_z;
}					t_model_fdf;

// for view rendering
typedef struct s_dot_of_view
{
	int				x;
	int				y;
	int				z;
	float			y_f;
	float			z_f;
	int				color;
	int				anti_alias_y;
	int				anti_alias_color;
}					t_dot_of_view;
typedef struct s_line_spec
{
	int				is_steep;
	int				is_in_reverse;
	float			y_gradient;
	float			z_gradient;
}					t_line_spec;
typedef struct s_camera
{
	int				zoom;
	double			x_angle;
	double			y_angle;
	double			z_angle;
	int				x_offset;
	int				y_offset;
	int				z_offset;
}					t_camera;

// for global settings
typedef struct s_settings
{
	int				projection_mode;
	int				z_scale;
}					t_settings;

// for mouse control
typedef struct s_mouse
{
	int				code;
	int				x;
	int				y;
	int				prev_x;
	int				prev_y;
}					t_mouse;

typedef struct s_view
{
	int				width;
	int				height;
	int				offset_x;
	int				offset_y;
	t_model_fdf		*fdf;
	t_camera		*camera;
}					t_view;

typedef struct s_multi_view
{
	t_view			*left_up;
	t_view			*right_up;
	t_view			*left_down;
	t_view			*right_down;
}					t_multi_view;

typedef struct s_image
{
	int				width;
	int				height;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_image;

// The screen is projected onto the window.
// The image is displayed on the screen.
// The image is rendered in one or more views.
// screen size = image size >= view size
typedef struct s_screen
{
	//	MiniLibX instance
	void			*mlx;
	void			*mlx_win;
	//	image data
	t_image			*image;
	//	user interface
	t_mouse			*mouse;
	t_settings		*settings;
}					t_screen;

// init_screen.c
t_screen			*init_screen(const char *fdf_path);

// load_fdf__calc_max_min_xyz.c
t_model_fdf			calc_max_min_xyz(t_model_fdf fdf);
// load_fdf__read_fdf_lines.c
void				read_fdf_lines(t_model_fdf *fdf, int fd);
// load_fdf__util.c
int					open_or_exit(const char *path, const char *file, int line);
// load_fdf.c
t_model_fdf			load_fdf(const char *fdf_path);

// draw_view.c
void				draw_view(t_view *view, t_image *image);

// draw_view_util.c
t_vertex_fdf		computed_deepest_corner(t_view *view);

// draw_line.c
void				draw_line_to_next_x(t_vertex_fdf s_fdf, t_view *view,
						t_image *image);
void				draw_line_to_next_y(t_vertex_fdf s_fdf, t_view *view,
						t_image *image);

// draw_line_util.c
void				put_pixel_to_image(int x, int y, int color, t_image *image);
int					is_out_of_screen(t_dot_of_view start, t_dot_of_view end,
						t_view *view);
t_line_spec			reflect_line_to_smooth(t_dot_of_view *start,
						t_dot_of_view *end);

// convert_fdf_to_view.c
t_dot_of_view		convert_fdf_to_view(t_vertex_fdf v_fdf, t_view *view);

// fdf_util.c
t_vertex_fdf		get_vertex_fdf(int x_raw, int y_raw, t_model_fdf *fdf);

// error.c
void				sys_func_error_exit(const char *err_msg, const char *file,
						int line);
void				forced_error_exit(const char *err_msg, const char *file,
						int line);

// ft_atoi_base.c
unsigned int		ft_atoi_base(const char *str_src, const char *base);

#endif
