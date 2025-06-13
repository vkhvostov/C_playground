#include "../includes/fdf.h"

static int	find_max_height(t_point *line, int width)
{
	int	max_height;
	int	index;

	max_height = line[0].z;
	index = 1;
	while (index < width)
	{
		if (line[index].z > max_height)
			max_height = line[index].z;
		index++;
	}
	return (max_height);
}

static t_point	parse_point(int x, int y, char *str)
{
	t_point	point;
	char	**split;

	split = ft_split(str, ',');
	point.x = x;
	point.y = y;
	point.z = ft_atoi(split[0]);
	if (split[1])
		point.color = hex_to_int(split[1] + 2);
	else
		point.color = -1;
	free(split[0]);
	free(split[1]);
	free(split);
	return (point);
}

static t_point	*parse_line(char *line, t_fdf *data, int row_index, int fd)
{
	t_point	*row;
	char	**split;
	int		index;

	row = malloc(sizeof(t_point) * (data->map_width));
	if (!row)
		exit_error("Failed to allocate memory", fd);
	split = ft_split(line, ' ');
	index = 0;
	while (split[index])
	{
		row[index] = parse_point(index, row_index, split[index]);
		if (row[index].color != -1)
			data->colored = 1;
		free(split[index]);
		index++;
	}
	free(split);
	return (row);
}

void	parse_map(char *filename, t_fdf *data)
{
	int		fd;
	char	*line;
	int		index;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_error("Failed to open file", -1);
	data->map = malloc(sizeof(int *) * (data->map_height + 1));
	if (!data->map)
		exit_error("Failed to allocate memory", fd);
	line = get_next_line(fd);
	index = 0;
	data->map_max = 0;
	while (line)
	{
		data->map[index] = parse_line(line, data, index, fd);
		data->map_max = max(data->map_max,
				find_max_height(data->map[index], data->map_width));
		free(line);
		line = get_next_line(fd);
		index++;
	}
	data->map[index] = NULL;
	free(line);
	close(fd);
}
