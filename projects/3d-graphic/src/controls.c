#include "../includes/fdf.h"

#define ESC_KEY 65307
#define UP_ARROW 65362
#define DOWN_ARROW 65364
#define LEFT_ARROW 65361
#define RIGHT_ARROW 65363
#define PLUS 65451
#define MINUS 65453
#define PAGE_UP 65365
#define PAGE_DOWN 65366
#define P_KEY 112
#define R_KEY 114
#define T_KEY 116
#define Q_KEY 113
#define W_KEY 119
#define E_KEY 101
#define A_KEY 97
#define S_KEY 115
#define D_KEY 100

#define MOUSE_SCROLL_UP 4
#define MOUSE_SCROLL_DOWN 5

static void	handle_perspective(t_fdf *data)
{
	if (data->projection_type == ISOMETRIC)
	{
		data->projection_type = PERSPECTIVE;
		data->offset_x = WIDTH / 2 - data->map_width * data->zoom / 2;
		data->offset_y = HEIGHT / 2 - data->map_height * data->zoom / 2;
	}
	else if (data->projection_type == PERSPECTIVE)
	{
		data->projection_type = SIDEWAYS;
		data->offset_x = WIDTH / 2 - (data->map_width - data->map_height)
			* cos(degrees_to_radians(30)) * data->zoom / 2;
		data->offset_y = HEIGHT / 2;
	}
	else if (data->projection_type == SIDEWAYS)
	{
		data->projection_type = ISOMETRIC;
		data->offset_x = WIDTH / 2 - (data->map_width - data->map_height)
			* cos(degrees_to_radians(30)) * data->zoom / 2;
		data->offset_y = HEIGHT / 2 - ((data->map_width + data->map_height)
				* sin(degrees_to_radians(30)) * data->zoom / 2);
	}
	data->angle_x = 0;
	data->angle_y = 0;
	data->angle_z = 0;
}

static void	handle_reset(t_fdf *data)
{
	set_defaults(data);
}

static void	handle_rotations(t_fdf *data, int key)
{
	if (data->projection_type == ISOMETRIC)
	{
		if (key == Q_KEY)
			data->angle_z -= 10;
		if (key == E_KEY)
			data->angle_z += 10;
		if (key == S_KEY)
			data->angle_x -= 10;
		if (key == W_KEY)
			data->angle_x += 10;
		if (key == A_KEY)
			data->angle_y -= 10;
		if (key == D_KEY)
			data->angle_y += 10;
	}
}

int	handle_key(int key, t_fdf *data)
{
	if (key == ESC_KEY)
		close_window(data);
	if (key == UP_ARROW)
		data->offset_y = max(data->offset_y - 10, -HEIGHT / 2);
	if (key == DOWN_ARROW)
		data->offset_y = min(data->offset_y + 10, HEIGHT + HEIGHT / 2);
	if (key == LEFT_ARROW)
		data->offset_x = max(data->offset_x - 10, -WIDTH / 2);
	if (key == RIGHT_ARROW)
		data->offset_x = min(data->offset_x + 10, WIDTH + WIDTH / 2);
	if (key == PLUS)
		data->zoom = min(data->zoom + 1, 30);
	if (key == MINUS)
		data->zoom = max(data->zoom - 1, 1);
	if (key == PAGE_UP)
		data->altitude = min(data->altitude + 1, 1000 / data->map_max);
	if (key == PAGE_DOWN)
		data->altitude = max(data->altitude - 1, -1000 / data->map_max);
	if (key == P_KEY)
		handle_perspective(data);
	if (key == R_KEY)
		handle_reset(data);
	handle_rotations(data, key);
	render(data);
	return (0);
}

int	handle_mouse(int button, int x, int y, t_fdf *data)
{
	(void)x;
	(void)y;
	if (button == MOUSE_SCROLL_UP)
		data->zoom = min(data->zoom + 2, 30);
	if (button == MOUSE_SCROLL_DOWN)
		data->zoom = max(data->zoom - 2, 1);
	render(data);
	return (0);
}
