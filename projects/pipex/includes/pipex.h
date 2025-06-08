#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/src/libft.h"
// For open()
# include <fcntl.h>
// For close(), read(), write(), access(), dup(), dup2(), execve(), fork()
// pipe(), unlink()
# include <unistd.h>
// For malloc(), free(), exit()
# include <stdlib.h>
// For perror()
# include <stdio.h>
// For strerror()
# include <string.h>
// For wait(), waitpid()
# include <sys/wait.h>
// For errno
# include <errno.h>

typedef struct s_pipex
{
	char	*app_name;
	int		infile;
	int		outfile;
	int		cmd_count;
	int		**pipe_fds;
	pid_t	*pids;
}	t_pipex;

int		open_input_file(char *filename, char *app_name);
int		open_output_file(char *filename, char *app_name);

char	*find_executable(char *cmd, char **envp, char *app_name);
char	**split_command(char *cmd);

void	child_process(t_pipex *pipex, char *cmd, char **envp, int is_first);
void	parent_process(t_pipex *pipex);

void	free_str_array(char **arr);
void	error_exit(char *app_name, char *msg, char *cause, int exit_code);

#endif
