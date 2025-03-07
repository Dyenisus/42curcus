#include "stack.h"

void	push(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	new_node->value = value;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
}

int	pop(t_stack *stack, int *error)
{
	t_node	*temp;
	int		value;

	if (!stack->top)
	{
		*error = 1;
		return (0);
	}
	*error = 0;
	temp = stack->top;
	value = temp->value;
	stack->top = temp->next;
	free(temp);
	stack->size--;
	return (value); 
}

int	peek(t_stack *stack, int *error)
{
	if (!stack->top)
	{
		*error = 1;
		return (0);
	}
	*error = 0;
	return (stack->top->value);
}

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

void	clear_stack(t_stack *stack)
{
	t_node *temp;

	if (!stack)
		return ;
	while (stack->top)
	{
		temp = stack->top->next;
		free(stack->top);
		stack->top = temp;
	}
	free(stack);
}
