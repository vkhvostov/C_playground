#include "../includes/fdf.h"

void	draw_wireframe(t_fdf *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			if (x < data->map_width - 1)
				draw_line(data,
					project_point(data->map[y][x], data),
					project_point(data->map[y][x + 1], data));
			if (y < data->map_height - 1)
				draw_line(data,
					project_point(data->map[y][x], data),
					project_point(data->map[y + 1][x], data));
			x++;
		}
		y++;
	}
}

void	render(t_fdf *data)
{
	mlx_clear_window(data->mlx, data->win);
	ft_bzero(data->img.addr, WIDTH * HEIGHT * (data->img.bpp / 8));
	draw_wireframe(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}
