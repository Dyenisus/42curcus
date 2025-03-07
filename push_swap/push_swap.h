#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include "push_swap_helper.h"
#include "push_swap_arg.h"
#include <unistd.h>

void	push_to(t_stack *from, t_stack *to);
void	swap(t_stack *stack);
void	rotate(t_stack *stack);
void	rev_rotate(t_stack *stack);


#endif