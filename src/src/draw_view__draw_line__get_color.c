#include "fdf.h"

static int	ft_lerp(int first, int second, double p)
{
	if (first == second)
		return (first);
	return ((int)((double)first + (second - first) * p));
}

int	ft_get_color(int x, float factor, t_line_on_view *line)
{
	int		r;
	int		g;
	int		b;
	float	percent;

	percent = (float)get_int_abs(x - line->start_dot.x)
		/ (float)get_int_abs(line->end_dot.x - line->start_dot.x);
	if (line->is_reversed)
	{
		r = ft_lerp((line->end_dot.color >> 16) & 0xFF,
				(line->start_dot.color >> 16) & 0xFF, percent);
		g = ft_lerp((line->end_dot.color >> 8) & 0xFF,
				(line->start_dot.color >> 8) & 0xFF, percent);
		b = ft_lerp(line->end_dot.color & 0xFF, line->start_dot.color & 0xFF,
				percent);
	}
	else
	{
		r = ft_lerp((line->start_dot.color >> 16) & 0xFF,
				(line->end_dot.color >> 16) & 0xFF, percent);
		g = ft_lerp((line->start_dot.color >> 8) & 0xFF,
				(line->end_dot.color >> 8) & 0xFF, percent);
		b = ft_lerp(line->start_dot.color & 0xFF, line->end_dot.color & 0xFF,
				percent);
	}
	r *= factor;
	g *= factor;
	b *= factor;
	return ((r << 16) | (g << 8) | b);
}
