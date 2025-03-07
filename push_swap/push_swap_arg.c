#include "push_swap.h"

t_stack	*one_str_arg_push(t_stack *stack, char *str)
{
	char	**one_str;
	char	**temp;
	int		result;

	if (!stack || !str)
		return (NULL);
	one_str = ft_split(str, ' ');  // ["1","5","7","2","-1","8","10"] or ["1","5","7","2"]
	if (!one_str)
		return (NULL);
	if (!is_valid(one_str))
	{
		clever_cleaner(one_str, NULL);
		clear_stack(stack);
		return (NULL);
	}
	temp = one_str;
	while (*one_str)
	{
		push(stack, ft_atoi(*one_str));
		one_str++;
	}
	clever_cleaner(temp, NULL);
	return (stack);
}

t_stack	*default_arg_push(t_stack *stack, char *str)
{
	if (!is_valid(&str))
	{
		clear_stack(stack);
		return (NULL);
	}
	push(stack, ft_atoi(str));
	return (stack);
}

t_stack	*arg_parse(int argc, char **argv)
{
	int		i;
	t_stack	*stack;

	stack = init_stack();
	if (!stack)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		if (is_spc_str(argv[i])) // case: ./push_swap "1 5 7 2 -1 8 10"
			stack = one_str_arg_push(stack, argv[i]);
		else // case: ./push_swap 1 5 7 2 -1 8 10
			stack = default_arg_push(stack, argv[i]);
		if (!stack || dup_check(stack))
		{
			clear_stack(stack);
			return (NULL);
		}
		i++;
	}
	return (stack);
}

int dup_check(t_stack *stack)
{
	t_node	*current;
	t_node	*checker;

	current = stack->top;
	while (current)
	{
		checker = current->next;
		while (checker)
		{
			if (checker->value == current->value)
			{
				write(2, "Error\n", 6);
				return (1);
			}
			checker = checker->next;
		}
		current = current->next;
	}
	return (0);
}
