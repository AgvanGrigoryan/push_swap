/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:02:10 by aggrigor          #+#    #+#             */
/*   Updated: 2024/02/26 17:08:40 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

int	do_rotates(char *action, t_stack *stack_a, t_stack *stack_b)
{
	if (action[1] == 'a' && action[2] == '\n' && action[3] == '\0')
		ra(stack_a, DONT_PRINT_ACTION);
	else if (action[1] == 'b' && action[2] == '\n' && action[3] == '\0')
		rb(stack_b, DONT_PRINT_ACTION);
	else if (action[1] == 'r' && action[2] == '\n' && action[3] == '\0')
		rr(stack_a, stack_b, DONT_PRINT_ACTION);
	else if (action[1] == 'r' && action[2] == 'a' && action[3] == '\n'
		&& action[4] == '\0')
		rra(stack_a, DONT_PRINT_ACTION);
	else if (action[1] == 'r' && action[2] == 'b' && action[3] == '\n'
		&& action[4] == '\0')
		rrb(stack_a, DONT_PRINT_ACTION);
	else if (action[1] == 'r' && action[2] == 'r' && action[3] == '\n'
		&& action[4] == '\0')
		rrr(stack_a, stack_b, DONT_PRINT_ACTION);
	else
		return (-1);
	return (1);
}

int	do_pushs(char *action, t_stack *stack_a, t_stack *stack_b)
{
	if (action[1] == 'a' && action[2] == '\n' && action[3] == '\0')
		pa(stack_a, stack_b, DONT_PRINT_ACTION);
	else if (action[1] == 'b' && action[2] == '\n' && action[3] == '\0')
		pb(stack_a, stack_b, DONT_PRINT_ACTION);
	else
		return (-1);
	return (1);
}

int	do_swaps(char *action, t_stack *stack_a, t_stack *stack_b)
{
	if (action[1] == 'a' && action[2] == '\n' && action[3] == '\0')
		sa(stack_a, PRINT_ACTION);
	else if (action[1] == 'b' && action[2] == '\n' && action[3] == '\0')
		sb(stack_b, PRINT_ACTION);
	else if (action[1] == 's' && action[2] == '\n' && action[3] == '\0')
		ss(stack_a, stack_b, PRINT_ACTION);
	else
		return (-1);
	return (1);
}

int	try_to_sort(t_stack *stack_a, t_stack *stack_b)
{
	char	*action;
	int		res;

	res = 1;
	action = get_next_line(0);
	while (action != NULL)
	{
		if (action[0] == 'r')
			res = do_rotates(action, stack_a, stack_b);
		else if (action[0] == 's')
			res = do_swaps(action, stack_a, stack_b);
		else if (action[0] == 'p')
			res = do_pushs(action, stack_a, stack_b);
		else
			res = -1;
		if (res == -1)
			return (-1);
		free(action);
		action = get_next_line(0);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	tmp_stack;

	stack_b = &tmp_stack;
	stack_b->start = NULL;
	stack_b->end = NULL;
	stack_b->size = 0;
	stack_a = (t_stack *)malloc(sizeof(t_stack));
	if (stack_a == NULL)
		return (0);
	if (!parse_input(argc - 1, argv + 1, &stack_a))
		return (!write(2, "Error\n", 6));
	set_indexes(stack_a);
	if (try_to_sort(stack_a, stack_b) == -1)
		return (!write(2, "Error\n", 6));
	if (stack_b->size == 0 && is_stack_sorted(stack_a))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_lstclear(&stack_a->start, free);
	free(stack_a);
	return (0);
}
