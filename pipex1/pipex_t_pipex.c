#include "pipex.h"

void	pipex_cleaner(t_pipex *pipex)
{
	if (pipex->infile < 0)
	{
		perror("Infile Error");
		close(pipex->infile);
	}
	if (pipex->outfile < 0)
	{
		perror("Infile Error");
		close(pipex->outfile);
	}
	if (pipex->pipe_fd)
		multi_cleaner(pipex->pipe_fd, NULL, pipex->pipe_count);
	if (pipex->pid)
		multi_cleaner(NULL, pipex->pid, pipex->cmd_count);
	if (pipex->cmd_list)
		chain_cleaner(pipex->cmd_list, pipex->cmd_count);
	if (pipex)
		free(pipex);
}

int	**init_pipe_fd(t_pipex *pipex)
{
	int	i;

	pipex->pipe_fd = (int **)malloc(sizeof(int *) * (pipex->pipe_count));
	if (!pipex->pipe_fd)
		pipex_cleaner(pipex);
	i = 0;
	while (i < pipex->pipe_count)
	{
		pipex->pipe_fd[i] = (int *)malloc(sizeof(int) * 2);
		if (!pipex->pipe_fd[i] || pipe(pipex->pipe_fd[i]) == -1)
			pipex_cleaner(pipex);
		i++;
	}
	return (pipex->pipe_fd);
}

pid_t	*init_pid(t_pipex *pipex)
{
	int	i;

	pipex->pid = (pid_t *)malloc(sizeof(pid_t) * pipex->cmd_count);
	if (!pipex->pid)
		pipex_cleaner(pipex);
	i = 0;
	while (i < pipex->cmd_count)
		pipex->pid[i++] = -1;
	return (pipex->pid);
}

t_pipex	*init_pipex(t_cmd *cmd_chain, int argc, char **argv)
{
	t_pipex	*pipex;

	pipex = (t_pipex *)malloc(sizeof(t_pipex));
	if (!cmd_chain || !pipex)
		pipex_cleaner(pipex);
	pipex->cmd_count = argc - 3;
	pipex->pipe_count = argc - 4;
	pipex->cmd_list = cmd_chain;
	pipex->infile = open(argv[1], O_RDONLY);
	pipex->outfile = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (pipex->infile < 0 || pipex->outfile < 0)
		pipex_cleaner(pipex);
	pipex->pipe_fd = init_pipe_fd(pipex);
	if (!pipex->pipe_fd)
		pipex_cleaner(pipex);
	pipex->pid = init_pid(pipex);
	if (!pipex->pid)
		pipex_cleaner(pipex);
	return (pipex);
}
