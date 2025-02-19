#ifndef PIPEX_H
# define PIPEX_H

typedef	struct s_cmd
{
	char			**args;
	char			*envp;
	struct s_cmd	*next;
}					t_cmd;

typedef	struct s_pipex
{
	int		infile;
	int		outfile;
	int		cmd_count;
	int		pipe_count;
	int		**pipe_fd;
	pid_t	*pid;
	t_cmd	*cmd_list;
}			t_pipex;

#include "libft/libft.h"
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

// don't forget to save all non-static functions
void	multi_cleaner(void **content1, void *content2, int count);
int	args_len(char **args);
char	*get_env_path(char **envp);
char	*path_searcher(char *cmd, char **paths);
char	*find_cmd_path(char *cmd, char **envp);
void	chain_cleaner(t_cmd	*cmd_chain, int argc);
t_cmd	*init_cmd_node(char **argv, char **envp, int index);
void	cmd_lstadd_back(t_cmd **list, t_cmd *new);
t_cmd	*get_cmd_chain(int argc, char **argv, char **envp);
void	pipex_cleaner(t_pipex *pipex);
int	**init_pipe_fd(t_pipex *pipex);
pid_t	*init_pid(t_pipex *pipex);
t_pipex	*init_pipex(t_cmd *cmd_chain, int argc, char **argv);
void	close_n_wait(t_pipex *pipex, int i);
void	file_dup2(t_pipex *pipex, t_cmd *cmd_node, int i);
void	process_handler(t_pipex *pipex);

#endif