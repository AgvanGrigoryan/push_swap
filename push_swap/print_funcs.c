#include <stdio.h>
#include "push_swap.h"

void	print_stack(t_stack *stack, int mode)
{
	t_list	*list;

	list = stack->start;
	printf("\n");
	if (mode == 0)
	{
		while (list)
		{
			printf("%d\n", list->num);
			list = list->next;
		}
	}
	else
	{
		printf("\nSTART:\t%p\t\tEND:\t%p\n", stack->start, stack->end);
		printf("\tPTR\t\tNEXT\t\tPREV\t\tVALUE\n");
		while (list)
		{
			printf("%15p : %15p : %15p : %10d\n", list, list->next,
				list->prev, list->num);
			list = list->next;
		}
	}
}

void	print_stacks(t_list *stack_a, t_list *stack_b)
{
	ft_putstr_fd("|a| |b|\n", 1);
	while (stack_a || stack_b)
	{
		if (!stack_a)
			printf("    ");
		else
		{
			printf(" %d ", stack_a->num);
			stack_a = stack_a->next;
		}
		if (!stack_b)
			printf("   \n");
		else
		{
			printf("  %d \n", stack_b->num);
			stack_b = stack_b->next;
		}
	}
}
