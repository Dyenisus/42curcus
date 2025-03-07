#ifndef PUSH_SWAP_ARG_H
# define PUSH_SWAP_ARG_H

#include "stack.h"
#include <stddef.h>

t_stack	*one_str_arg_push(t_stack *stack, char *str);
t_stack	*default_arg_push(t_stack *stack, char *str);
t_stack	*arg_parse(int argc, char **argv);
int dup_check(t_stack *stack);

#endif