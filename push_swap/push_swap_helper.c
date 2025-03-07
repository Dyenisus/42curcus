#include "push_swap_helper.h"

int	is_space(char c)
{
	if (c == ' ' || (c <= '\r' && c >= '\t'))
		return (1);
	return (0);
}

int	is_spc_str(char *argv)
{
	int	j;

	j = 0;
	while (argv[j])
	{
		if (is_space(argv[j]))
			return (1);
		j++;
	}
	return (0);
}

int is_valid(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (j == 0 && (str[i][j] == '-' || str[i][j] == '+'))
				j++;
			if (!str[i][j] ||(str[i][j] && !ft_isdigit(str[i][j])))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	clever_cleaner(char **content1, void *content2)
{
	int	i;

	if (content1)
	{
		i = 0;
		while (content1[i])
			free(content1[i++]);
		free(content1);
		*content1 = NULL;
	}
	if (content2)
	{
		free(content2);
		content2 = NULL;
	}
}

