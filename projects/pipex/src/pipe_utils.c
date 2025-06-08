#include "../includes/pipex.h"

void	free_str_array(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	error_exit(char *app_name, char *msg, char *cause, int exit_code)
{
	ft_putstr_fd(app_name, STDERR_FILENO);
	if (msg)
	{
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd(msg, STDERR_FILENO);
	}
	if (cause)
	{
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd(cause, STDERR_FILENO);
	}
	ft_putendl_fd("", STDERR_FILENO);
	if (exit_code != -1)
		exit(exit_code);
}
