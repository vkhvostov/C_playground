#include "../includes/fdf.h"

void	exit_error(char *message, int fd)
{
	ft_putendl_fd(message, 2);
	if (fd >= 0)
		close(fd);
	exit(EXIT_FAILURE);
}

int	close_window(t_fdf *data)
{
	int	index;

	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img.img);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	index = 0;
	while (data->map[index])
	{
		free(data->map[index]);
		index++;
	}
	free(data->map);
	exit(0);
	return (0);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

double	degrees_to_radians(double degrees)
{
	return (degrees * (M_PI / 180.0));
}
