#include "../includes/pipex.h"

static char	*ft_getenv(const char *name, char **envp)
{
	size_t	i;
	size_t	j;

	if (!name || !envp)
		return (NULL);
	i = 0;
	while (envp[i])
	{
		j = 0;
		while (name[j] && envp[i][j] == name[j])
			j++;
		if (name[j] == '\0' && envp[i][j] == '=')
			return (&envp[i][j + 1]);
		i++;
	}
	return (NULL);
}

static char	*exit_and_free(char **paths, char *full_cmd)
{
	free_str_array(paths);
	return (full_cmd);
}

static void	build_command_path(char *full_cmd, char *path, char *cmd)
{
	if (!full_cmd || !path || !cmd)
		return ;
	ft_strlcpy(full_cmd, path, 256);
	ft_strlcat(full_cmd, "/", 256);
	ft_strlcat(full_cmd, cmd, 256);
}

char	*find_executable(char *cmd, char **envp, char *app_name)
{
	char	*path_env;
	char	**paths;
	char	*full_cmd;
	int		i;

	path_env = ft_getenv("PATH", envp);
	if (!path_env)
		return (NULL);
	paths = ft_split(path_env, ':');
	i = 0;
	while (paths[i])
	{
		full_cmd = malloc(ft_strlen(paths[i]) + ft_strlen(cmd) + 2);
		if (!full_cmd)
			error_exit(app_name, "Malloc failed", NULL, EXIT_FAILURE);
		build_command_path(full_cmd, paths[i], cmd);
		if (access(full_cmd, X_OK) == 0)
			return (exit_and_free(paths, full_cmd));
		free(full_cmd);
		i++;
	}
	return (exit_and_free(paths, NULL));
}

char	**split_command(char *cmd)
{
	return (ft_split(cmd, ' '));
}
