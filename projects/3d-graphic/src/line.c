#include "../includes/fdf.h"

/**
 * Puts a pixel at (x, y) with the given color in the image buffer
 * (instead of putting it directly in the window).
 */
static void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

static t_line	init_line_data(t_point p1, t_point p2)
{
	t_line	line_data;

	line_data.dx = p2.x - p1.x;
	line_data.dy = p2.y - p1.y;
	line_data.steps = fmax(fabs(line_data.dx), fabs(line_data.dy));
	line_data.x_inc = line_data.dx / line_data.steps;
	line_data.y_inc = line_data.dy / line_data.steps;
	line_data.x = p1.x;
	line_data.y = p1.y;
	return (line_data);
}

/**
 * Draws a line between two points using DDA algorithm.
 */
void	draw_line(t_fdf *data, t_point p1, t_point p2)
{
	t_line	line_data;
	int		index;

	line_data = init_line_data(p1, p2);
	index = 0;
	while (index <= line_data.steps)
	{
		put_pixel(&data->img, (int)round(line_data.x), (int)round(line_data.y),
			interpolate_color(p1.color, p2.color, index / line_data.steps));
		line_data.x += line_data.x_inc;
		line_data.y += line_data.y_inc;
		index++;
	}
}
