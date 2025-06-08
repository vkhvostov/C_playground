#include "../includes/pipex.h"

static void	close_pipe(int **pipe_fds)
{
	int	index;

	index = 0;
	while (pipe_fds[index])
	{
		close(pipe_fds[index][0]);
		close(pipe_fds[index][1]);
		index++;
	}
}

static void	create_pipes(t_pipex *pipex, int index)
{
	if (index == 0)
	{
		dup2(pipex->infile, STDIN_FILENO);
		dup2(pipex->pipe_fds[index][1], STDOUT_FILENO);
	}
	else if (index == pipex->cmd_count - 1)
	{
		dup2(pipex->pipe_fds[index - 1][0], STDIN_FILENO);
		dup2(pipex->outfile, STDOUT_FILENO);
	}
	else
	{
		dup2(pipex->pipe_fds[index - 1][0], STDIN_FILENO);
		dup2(pipex->pipe_fds[index][1], STDOUT_FILENO);
	}
}

void	child_process(t_pipex *pipex, char *cmd, char **envp, int index)
{
	char	**args;
	char	*exec_path;

	args = split_command(cmd);
	exec_path = find_executable(args[0], envp, pipex->app_name);
	if (!exec_path)
	{
		free_str_array(args);
		error_exit(pipex->app_name, "command not found", cmd, 127);
	}
	create_pipes(pipex, index);
	close_pipe(pipex->pipe_fds);
	execve(exec_path, args, envp);
	free(exec_path);
	free_str_array(args);
	exit(EXIT_SUCCESS);
}

void	parent_process(t_pipex *pipex)
{
	int	status;
	int	index;

	close_pipe(pipex->pipe_fds);
	index = 0;
	while (index < pipex->cmd_count)
	{
		waitpid(pipex->pids[index], &status, 0);
		index++;
	}
	if (WIFEXITED(status))
		exit(WEXITSTATUS(status));
	else
		exit(EXIT_FAILURE);
}
