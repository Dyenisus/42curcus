#include "pipex.h"

void	chain_cleaner(t_cmd	*cmd_chain, int argc)
{
	t_cmd	*temp;
	int		i;

	i = 2;
	while (i < argc - 1)
	{
		temp = cmd_chain->next;
		multi_cleaner(cmd_chain->args, cmd_chain->envp , args_len(cmd_chain->args));
		cmd_chain = temp;
	}
}

t_cmd	*init_cmd_node(char **argv, char **envp, int index)
{
	t_cmd	*new_node;

	new_node = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new_node)
	{
		return (NULL);
	}
	new_node->args = ft_split(argv[index], " ");
	if (!new_node->args)
	{
		free(new_node);
		return (NULL);
	}
	new_node->envp = find_cmd_path(new_node->args ,envp);
	if (!new_node->envp)
	{
		multi_cleaner(new_node->args, new_node, (args_len(new_node->args)));
		return (NULL);
	}
	new_node->next = NULL;
	return (new_node);
}

void	cmd_lstadd_back(t_cmd **list, t_cmd *new)
{
	t_cmd	*last;

	if (!list || !new)
		return ;
	if (!*list)
	{
		*list = new;
		return ;
	}
	last = *list;
	while (last && last->next)
		last = last->next; 
	last->next = new;
}

t_cmd	*get_cmd_chain(int argc, char **argv, char **envp)
{
	t_cmd	*new_node;
	t_cmd	*head;
	int		i;

	head = NULL;
	i = 2;
	while (i < argc - 1)
	{
		new_node = init_cmd_node(argv, envp, i);
		if (!new_node)
		{
			perror("Command Chain Error");
			chain_cleaner(new_node, argc);
			return (NULL);
		}
		cmd_lstadd_back(&head, new_node);
		i++;
	}
	return (head);
}
