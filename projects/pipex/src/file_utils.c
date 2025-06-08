#include "../includes/pipex.h"

static int	open_file(char *filename, int flags, int mode)
{
	int	fd;

	if (mode)
		fd = open(filename, flags, mode);
	else
		fd = open(filename, flags);
	return (fd);
}

int	open_input_file(char *filename, char *app_name)
{
	int	fd;

	fd = open_file(filename, O_RDONLY, 0);
	if (fd == -1)
	{
		error_exit(app_name, strerror(errno), filename, -1);
		fd = open("/dev/null", O_RDONLY);
	}
	return (fd);
}

int	open_output_file(char *filename, char *app_name)
{
	int	fd;

	fd = open_file(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		error_exit(app_name, strerror(errno), filename, EXIT_FAILURE);
	return (fd);
}
