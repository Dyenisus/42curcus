#ifndef STACK_H
# define STACK_H

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}			t_stack;

#include <stdlib.h>

void	push(t_stack *stack, int value);
int	pop(t_stack *stack, int *error);
int	peek(t_stack *stack, int *error);
t_stack	*init_stack(void);
void	clear_stack(t_stack *stack);

#endif