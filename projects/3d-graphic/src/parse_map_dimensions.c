#include "../includes/fdf.h"

static int	parse_width(char *line)
{
	int		width;
	char	**split;

	split = ft_split(line, ' ');
	width = 0;
	while (split[width])
	{
		free(split[width]);
		width++;
	}
	free(split);
	return (width);
}

void	parse_dimensions(char *filename, t_fdf *data)
{
	int		fd;
	char	*line;
	int		width;
	int		hight;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_error("Failed to open file", -1);
	line = get_next_line(fd);
	hight = 0;
	while (line)
	{
		width = parse_width(line);
		free(line);
		hight++;
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	data->map_width = width;
	data->map_height = hight;
}
