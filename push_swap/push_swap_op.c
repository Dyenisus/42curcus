#include "push_swap.h"

static	int	error_check(t_stack *stack)
{
	if (!stack || !stack->top || !stack->top->next)
		return (1);
	return (0);
}

void	push_to(t_stack *from, t_stack *to)
{
	int	value;
	int	error;

	if (error_check(from) == 1)
		return ;
	value = pop(from, &error);
	if (error)
	{
		write(2,"Error\n", 6);
		return ;
	}
	push(to, value);
}

void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (error_check(stack) == 1)
		return ;
	first = stack->top;
	second = stack->top->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
}

void	rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (error_check(stack) == 1)
		return ;
	first = stack->top;
	stack->top = first->next;
	first->next = NULL;
	last = stack->top;
	while (last->next)
		last = last->next;
	last->next = first;
}

void	rev_rotate(t_stack *stack)
{
	t_node	*prev;
	t_node	*last;

	if (error_check(stack) == 1)
		return ;
	prev = NULL;
	last = stack->top;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	if (prev)
		prev->next = NULL;
	last->next = stack->top;
	stack->top = last;
}
