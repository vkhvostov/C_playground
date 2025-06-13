#include "../includes/fdf.h"

void	set_defaults(t_fdf *data)
{
	data->projection_type = ISOMETRIC;
	data->zoom = max(30 * 5 / max(data->map_width, data->map_height), 1);
	data->altitude = 1;
	data->offset_x = WIDTH / 2 - data->zoom
		* (sqrt(data->map_height * data->map_height
				+ data->map_width * data->map_width) / 2);
	data->offset_y = HEIGHT / 2;
	data->angle_x = 0;
	data->angle_y = 0;
	data->angle_z = -90;
}

static void	init_image(t_fdf *data)
{
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp,
			&data->img.line_length, &data->img.endian);
}

static void	init_data(char *filename, t_fdf *data)
{
	data->colored = 0;
	parse_map(filename, data);
	init_image(data);
	set_defaults(data);
}

int	main(int argc, char **argv)
{
	t_fdf	data;

	if (argc != 2)
		exit_error("Usage: ./fdf <map.fdf>", -1);
	parse_dimensions(argv[1], &data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "FdF");
	init_data(argv[1], &data);
	render(&data);
	mlx_hook(data.win, 17, 0L, &close_window, &data);
	mlx_key_hook(data.win, handle_key, &data);
	mlx_mouse_hook(data.win, handle_mouse, &data);
	mlx_loop(data.mlx);
}
