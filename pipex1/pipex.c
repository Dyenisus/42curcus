#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_cmd	*cmd_lst_head;
	t_pipex	*my_pipex;

	cmd_lst_head = get_cmd_chain(argc, argv, envp);
	if (!cmd_lst_head)
	{
		chain_cleaner(cmd_lst_head, argc);
		exit(1);
	}
	my_pipex = init_pipex(cmd_lst_head, argc, argv);
	if (!my_pipex)
	{
		pipex_cleaner(my_pipex);
		exit(1);
	}
	process_handler(my_pipex);
	pipex_cleaner(my_pipex);
	return (0);
}
