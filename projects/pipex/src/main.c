#include "../includes/pipex.h"

static void	free_memory(t_pipex pipex)
{
	int	index;

	index = 0;
	while (index < pipex.cmd_count - 1)
	{
		free(pipex.pipe_fds[index]);
		index++;
	}
	free(pipex.pipe_fds);
	free(pipex.pids);
}

static t_pipex	init(int argc, char **argv)
{
	t_pipex	pipex;
	int		index;

	pipex.app_name = argv[0];
	pipex.infile = open_input_file(argv[1], pipex.app_name);
	pipex.outfile = open_output_file(argv[argc - 1], pipex.app_name);
	pipex.cmd_count = argc - 3;
	pipex.pids = malloc(sizeof(pid_t) * (pipex.cmd_count));
	if (!pipex.pids)
		error_exit(argv[0], "Malloc failed", NULL, EXIT_FAILURE);
	pipex.pipe_fds = malloc(sizeof(int *) * (pipex.cmd_count));
	index = 0;
	while (index < pipex.cmd_count - 1)
	{
		pipex.pipe_fds[index] = malloc(sizeof(int) * 2);
		if (pipe(pipex.pipe_fds[index]) == -1)
			error_exit(argv[0], "Pipe failed", NULL, EXIT_FAILURE);
		index++;
	}
	pipex.pipe_fds[index] = NULL;
	return (pipex);
}

static int	fork_processes(t_pipex *pipex, char **argv, char **envp)
{
	int	index;

	index = 0;
	while (index < pipex->cmd_count)
	{
		pipex->pids[index] = fork();
		if (pipex->pids[index] == 0)
			child_process(pipex, argv[index + 2], envp, index);
		index++;
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc < 5)
	{
		ft_putendl_fd("Usage: file1 cmd1 cmd2 ... file2", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	pipex = init(argc, argv);
	fork_processes(&pipex, argv, envp);
	parent_process(&pipex);
	close(pipex.infile);
	close(pipex.outfile);
	free_memory(pipex);
	return (EXIT_SUCCESS);
}
