#include "pipex.h"

char	*get_env_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

char	*path_searcher(char *cmd, char **paths)
{
	int		i;
	char	*full_path;

	i = 0;
	while (paths[i])
	{
		full_path = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(full_path, cmd);
		if (access(full_path, X_OK) == 0)
		{
			multi_cleaner(paths, NULL, args_len(paths));
			return (full_path);
		}
		free(full_path);
		i++;
	}
	return (NULL);
}

char	*find_cmd_path(char *cmd, char **envp)
{
	char	*envs;
	char	**paths;
	char	*cmd_path;

	envs = get_env_path(**envp);
	if (!envs)
	{
		perror("PATH Error");
		return (NULL);
	}
	paths = ft_split(envs, ":");
	if (!paths)
	{
		perror("PATHS Error");
		return (NULL);
	}
	cmd_path = path_searcher(cmd, paths);
	multi_cleaner(paths, NULL, args_len(paths));
	if (!cmd_path)
	{
		perror("CMD PATH Error");
		exit(1);
	}
	return (cmd_path);
}
