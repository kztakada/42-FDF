/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:58:01 by katakada          #+#    #+#             */
/*   Updated: 2025/03/14 01:40:04 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include "./for_test.h"
# include "./mlx.h"
# include <math.h>
# include <stdio.h>
# include <time.h>

# define TRUE 1
# define FALSE 0

# define IS_DEBUG 1

# define LOWER_CASE 0
# define UPPER_CASE 1
# define NO_CASE -1

# define LEFT_UP 0
# define RIGHT_UP 1
# define LEFT_DOWN 2
# define RIGHT_DOWN 3

# define SIDE_TOP 0
# define SIDE_BOTTOM 1
# define SIDE_LEFT 2
# define SIDE_RIGHT 3

# define Z_SCALE_DEFAULT 10
# define Z_HEIGHT_RATIO 10

// hex base upper and lower
# define HEX_LOWER_PREFIX "0x"
# define HEX_UPPER_PREFIX "0X"
# define HEX_LOWER_BASE "0123456789abcdef"
# define HEX_UPPER_BASE "0123456789ABCDEF"

// shift bit color
# define RED_SHIFT 16
# define GREEN_SHIFT 8
# define BLUE_SHIFT 0

// model colors are 5 levels
# define COLOR_L0 0x432371
# define COLOR_L1 0x714674
# define COLOR_L2 0x9F6976
# define COLOR_L3 0xCC8B79
# define COLOR_L4 0xFAAE7B

// screen size
# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080

// screen background color
# define SCREEN_BG 0x040404
# define CONSOLE_BG 0x222222
# define NAMEPLATE_BG 0x161616

// screen text color
# define TXT_C0 0xFFFFFF

// info text line settings
# define INFO_BASE_OFFSET_Y 20
# define LINE_SPACE 18
# define BOL 5 // beginning of line
# define G_L01 20
# define G_M01 60
# define G_M02 78
# define G_M03 96

# define M_M01 126
# define M_M02 144
# define M_M03 162
# define M_M04 180

# define G_K01 220
# define G_K02 238
# define G_K03 256
# define G_K04 274
# define G_K05 292
# define G_K06 310
# define G_K07 336
# define G_K08 354
# define G_K09 380
# define G_K10 398
# define G_K11 416
# define G_K12 442
# define G_K13 460
# define G_K14 486

// info text
# define G_INFO_L01 "OPERATION EXPLANATION"

# define G_INFO_M01 "MOUSE WHEEL"
# define G_INFO_M02 "Up:     Zoom in"
# define G_INFO_M03 "Down:   Zoom out"

# define G_INFO_K01 "KEYBOARD"
# define G_INFO_K02 "Space:  Switch view mode"
# define G_INFO_K03 "Left:   Move camera to left"
# define G_INFO_K04 "Right:  Move camera to right"
# define G_INFO_K05 "Up:     Move camera to up"
# define G_INFO_K06 "Down:   Move camera to down"

# define G_INFO_K07 "+:      increment model z scale"
# define G_INFO_K08 "-:      decrement model z scale"

# define G_INFO_K09 "X:      Toggle auto rotate x"
# define G_INFO_K10 "Y:      Toggle auto rotate y"
# define G_INFO_K11 "Z:      Toggle auto rotate z"

# define G_INFO_K12 "C:      Reset camera position"
# define G_INFO_K13 "D:      Switch debug mode"

# define G_INFO_K14 "Esc:    Close window"

# define MAIN_INFO_M01 "MOUSE DRAG"
# define MAIN_INFO_M02 "Left:   Translate camera xy"
# define MAIN_INFO_M03 "Middle: Rotate camera xy"
# define MAIN_INFO_M04 "Right:  Rotate camera z"

# define MULTI_INFO_M01 "MOUSE CLICK"
# define MULTI_INFO_M02 "Left:   Select projection"

// view size
# define CONSOLE_WIDTH 200
# define NAMEPLATE_WIDTH 100
# define NAMEPLATE_HEIGHT 32
# define NAMEPLATE_OFFSET_X 16

// camera projection mode
# define FREE -1
# define ISOMETRIC 0
# define FRONT_VIEW 1
# define TOP_VIEW 2
# define SIDE_VIEW 3

// screen mode
# define MAIN_SCREEN 0
# define MULTI_SCREEN 1

// auto rotate z
# define STOP 0
# define ROTATE_L 1
# define ROTATE_R 2

// frame time
# define FRAME_RATE 120
# define PER_MILLI_SEC 1000

// key code
# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_PLUS 61
# define KEY_MINUS 45
# define KEY_SPACE 32
# define KEY_R 114
# define KEY_C 99
# define KEY_D 100
# define KEY_X 120
# define KEY_Y 121
# define KEY_Z 122

// mouse code
# define MOUSE_LEFT 1
# define MOUSE_MIDDLE 2
# define MOUSE_RIGHT 3
# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5

// mouse scale factor
# define MOUSE_SCALE 0.002

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
	int				size_x_raw;
	int				size_y_raw;
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
typedef struct s_anti_aliased_dot
{
	int				x;
	int				y;
	int				z;
	float			y_f;
	float			z_f;
	int				top_color;
	int				bottom_color;
}					t_anti_aliased_dot;
typedef struct s_dot_on_view
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_dot_on_view;
typedef struct s_line_on_view
{
	t_dot_on_view	start_dot;
	t_dot_on_view	end_dot;
	int				is_steep;
	int				is_reversed;
	float			y_gradient;
	float			z_gradient;
}					t_line_on_view;
typedef struct s_camera
{
	int				zoom;
	double			x_angle;
	double			y_angle;
	double			z_angle;
	int				x_offset;
	int				y_offset;
}					t_camera;

// for global settings
typedef struct s_settings
{
	int				projection_mode;
	int				is_moved;
	int				screen_mode;
	int				auto_rotate_x;
	int				auto_rotate_y;
	int				auto_rotate_z;
	int				is_debug;
}					t_settings;

// for mouse control
typedef struct s_mouse
{
	int				button;
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

typedef struct s_screen_views
{
	t_view			*main_view;
	t_multi_view	*multi_view;
}					t_screen_views;

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
	// views
	t_screen_views	*views;
	int				z_scale;
	//	user interface
	t_mouse			*mouse;
	t_settings		*settings;
}					t_screen;

typedef struct s_rectangle
{
	int				width;
	int				height;
	int				color;
}					t_rectangle;

// draw_view__draw_line__calc_dot_color.c
void				calc_anti_alias_dots(t_anti_aliased_dot *drawing_dot,
						t_line_on_view *line);

// draw_view__draw_line__draw_dot_line.c
void				draw_dot_line(t_line_on_view *line, t_view *view,
						t_image *image);
// draw_view__draw_line__is_out_of_view__util.c
int					is_dot_within_view(t_dot_on_view dot, t_view *view);
int					is_crossing_view(t_line_on_view the_line, t_view *view);
// draw_view__draw_line__is_out_of_view.c
int					is_out_of_view(t_line_on_view *the_line, t_view *view);
// draw_view__draw_line__util.c
void				swap_xy_to_less_steep(t_line_on_view *line);
void				swap_start_end_xyz(t_line_on_view *line);
void				swap_xy_to_restore_steep(t_anti_aliased_dot *dot);
void				calc_yz_gradient(t_line_on_view *line);
// draw_view__draw_line.c
void				draw_line_to_next_x(t_vertex_fdf start_raws, t_view *view,
						t_screen *screen);
void				draw_line_to_next_y(t_vertex_fdf start_raws, t_view *view,
						t_screen *screen);
// draw_view__util.c
t_vertex_fdf		computed_deepest_corner(t_view *view, int z_scale);
t_line_on_view		make_line_on_view(t_dot_on_view start_dot,
						t_dot_on_view end_dot);
// draw_view.c
void				draw_view(t_view *view, t_screen *screen);

// error_exit.c
void				sys_func_error_exit(const char *err_msg, const char *file,
						int line);
void				forced_error_exit(const char *err_msg, const char *file,
						int line);

// ft_atoi_base.c
unsigned int		ft_atoi_base(const char *str_src, const char *base);

// init_camera__camera_assets.c
t_camera			get_isometric_camera(void);
t_camera			get_front_view_camera(void);
t_camera			get_top_view_camera(void);
t_camera			get_side_view_camera(void);

// init_camera.c
void				setup_camera_zoom_to_fit_view_whole(t_camera *camera,
						int view_width, int view_height, t_model_fdf *fdf);
t_camera			*init_camera(int projection_mode, const char *file,
						int line);
// init_screen.c
t_screen			*init_screen(const char *fdf_path);
// init_views.c
t_screen_views		*init_screen_views(t_model_fdf *fdf);

// interface__keyboard__reset_displayed_view.c
void				reset_displayed_view(t_screen *screen);
// nterface__keyboard__toggle_auto_rotate.c
void				toggle_auto_rotate(t_screen *screen, int keycode);
// interface__keyboard__translate_camera_pos.c
void				translate_camera_pos(int keycode, t_screen *screen);
// interface__keyboard.c
int					key_hook(int keycode, void *param);
// interface__mouse__mouse_down.c
int					mouse_down(int button, int x, int y, void *param);
// interface__mouse__mouse_move__rotate_camera_angle.c
void				rotate_camera_angle_xy_by_mouse(int mouse_x, int mouse_y,
						t_screen *screen);
void				rotate_camera_angle_z_by_mouse(int mouse_x, int mouse_y,
						t_screen *screen);
// interface__mouse__mouse_move.c
int					mouse_move(int x, int y, void *param);
// interface__mouse__mouse_up.c
int					mouse_up(int button, int x, int y, void *param);
// interface__util.c
int					close_window(void *param);
void				rotate_angle(double *angle, double delta);

// load_fdf__calc_max_min_xyz.c
t_model_fdf			calc_max_min_xyz(t_model_fdf fdf);
// load_fdf__read_fdf_lines__is_hex_str.c
int					convert_hex_str_to_int(const char *hex_str);
int					is_hex_str(const char *str);
// load_fdf__read_fdf_lines__is_int_str.c
int					has_invalid_sign(const char *str);
int					is_int_str(const char *str);

// load_fdf__read_fdf_lines__validate_altitude_format.c
int					validate_altitude_format(char *z_and_color,
						const char *file, int line);
// load_fdf__read_fdf_lines.c
void				read_fdf_lines(t_model_fdf *fdf, int fd);
// load_fdf__util.c
int					open_or_exit(const char *path, const char *file, int line);
// load_fdf.c
t_model_fdf			load_fdf(const char *fdf_path);

// malti_view.c
void				draw_multi_view(t_multi_view *multi_view, t_screen *screen);

// projection_exec__auto_rotate_camera_angle.c
void				auto_rotate_camera_angle(t_screen *screen);
// projection_exec__draw_debag.c
void				draw_debag(t_screen *screen);
// projection_exec__draw_info__util.c
int					np_offset_x(t_view *view);
int					np_offset_y(t_view *view);
void				draw_mouse_drug_info(t_screen *screen);
void				draw_mouse_click_info(t_screen *screen);
// projection_exec__draw_info.c
void				draw_info(t_screen *screen);
// projection_exec__draw_screen__util.c
void				put_rectangle(t_image *image, t_rectangle *rectangle,
						int start_x, int start_y);
int					v_offset_x(t_view *view);
int					v_offset_y(t_view *view);
// projection_exec__draw_screen.c
void				draw_screen(t_screen *screen);
// projection_exec.c
void				projection_exec(t_screen *screen);

// setup_mlx_hooks.c
void				setup_loop_exec_hook(t_screen *screen);
void				setup_user_action_hooks(t_screen *screen);

// util__convert_fdf_to_view_dot.c
t_dot_on_view		convert_fdf_to_view_dot(t_vertex_fdf v_fdf, t_view *view,
						int z_scale);

// util__custom_get_next_line.c
char				*custom_get_next_line(int fd);

// util.c
t_vertex_fdf		*get_vertex_fdf(int x_raw, int y_raw, t_model_fdf *fdf);
int					get_int_abs(int n);
void				flush_get_next_line(int fd);
void				free_all(char **str_collection);

#endif
