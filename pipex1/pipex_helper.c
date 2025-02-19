#include "pipex.h"

void	multi_cleaner(void **content1, void *content2, int count)
{
	int	i;

	i = 0;
	if (content1[i])
	{
		while (i < count)
			free(content1[i++]);
	}
	if (content1)
		free(content1);
	if (content2)
		free(content2);
}

int	args_len(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

void	close_n_wait(t_pipex *pipex, int i)
{
	while (i < pipex->pipe_count)
	{
		close(pipex->pipe_fd[i][0]);
		close(pipex->pipe_fd[i][1]);
		i++;
	}
	i = 0;
	while (i < pipex->cmd_count)
	{
		waitpid(pipex->pid[i], NULL, 0);
		i++;
	}
}

void	file_dup2(t_pipex *pipex, t_cmd *cmd_node, int i)
{
	int	j;

	if (i == 0)
		dup2(pipex->infile, STDIN_FILENO);
	else
		dup2(pipex->pipe_fd[i - 1][0], STDIN_FILENO);
	if (i == pipex->cmd_count - 1)
		dup2(pipex->outfile, STDOUT_FILENO);
	else
		dup2(pipex->pipe_fd[i][1], STDOUT_FILENO);
	j = 0;
	while (j < pipex->pipe_count)
	{
		close(pipex->pipe_fd[j][0]);
		close(pipex->pipe_fd[j][1]);
		j++;
	}
	execve(cmd_node->envp, cmd_node->args, NULL);
	perror("Execve Error");
	exit(1);
}

void	process_handler(t_pipex *pipex)
{
	int		i;
	t_cmd	*cmd_node;

	cmd_node = pipex->cmd_list;
	i = 0;
	while (i < pipex->cmd_count)
	{
		pipex->pid[i] = fork();
		if (pipex->pid[i] == -1)
		{
			perror("Fork Error");
			pipex_cleaner(pipex);
		}
		if (pipex->pid[i] == 0)
			file_dup2(pipex, cmd_node, i);
		cmd_node = cmd_node->next;
		i++;
	}
	close_n_wait(pipex, 0);
}
