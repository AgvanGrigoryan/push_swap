/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:07:58 by aggrigor          #+#    #+#             */
/*   Updated: 2024/02/24 19:56:45 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

// Sort grather than 5 items
void sort_big_stack(t_stack * stack_a, t_stack *stack_b)
{
	int	counter = 0;
	int	b_max_ind;
	int offset = 16; //ft_log2(stack_a->size) + ft_sqrt(stack_a->size);

	while (stack_a->size > 0)
	{
		if (stack_a->start->index <= counter)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			counter++;
		}
		else if (stack_a->start->index <= counter + offset)
		{
			pb(stack_a, stack_b);
			counter++;
		}
		else
			ra(stack_a);
	}
	b_max_ind = stack_b->size - 1;
	while (stack_b->size > 0)
	{
		if (stack_b->start->index == b_max_ind)
		{
			pa(stack_a, stack_b);
			b_max_ind--;
		}
		else if (get_pos_at_index(stack_b->start, b_max_ind) > 1 + (stack_b->size / 2))
			rrb(stack_b);
		else if (get_pos_at_index(stack_b->start, b_max_ind) <= 1 + (stack_b->size / 2))
			rb(stack_b);
	}
}

// sort 3 items
void	sort_3elem_stack(t_stack *stack_a)
{
	if (is_a_sorted(stack_a))
		return ;
	if (stack_a->start->num < stack_a->start->next->num)
		rra(stack_a);
	if (is_a_sorted(stack_a))
		return ;
	if (stack_a->start->num > stack_a->start->next->num
		&& (stack_a->start->num < stack_a->end->num
			|| stack_a->start->next->num > stack_a->end->num))
		sa(stack_a);
	else
		ra(stack_a);
	if (stack_a->end->num < stack_a->start->num)
		rra(stack_a);
}

// sort less than 5 items
void	sort_5elem_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	a_min_ind;

	if (is_a_sorted(stack_a))
		return ;
	a_min_ind = 0;
	while (stack_a->size > 3 && stack_b->size < 2)
	{
		if (stack_a->start->index == a_min_ind)
		{
			pb(stack_a, stack_b);
			a_min_ind++;
		}
		else if (get_pos_at_index(stack_a->start, a_min_ind) > 1 + (stack_a->size / 2))
			rra(stack_a);
		else if (get_pos_at_index(stack_a->start, a_min_ind) <= 1 + (stack_a->size / 2))
			ra(stack_a);
	}
	sort_3elem_stack(stack_a);
	while (ft_lstsize(stack_b->start) != 0)
		pa(stack_a, stack_b);
}

void	sort_stack(t_stack	*stack_a)
{
	t_stack	*stack_b;
	t_stack	tmp_stack;

	stack_b = &tmp_stack;
	stack_b->start = NULL;
	stack_b->end = NULL;
	stack_b->size = 0;

	if (stack_a->size == 2 && stack_a->start->num > stack_a->start->next->num)
		sa(stack_a);
	else if (stack_a->size == 3)
		sort_3elem_stack(stack_a);
	else if (stack_a->size <= 5)
		sort_5elem_stack(stack_a, stack_b);
	else
	{
		sort_big_stack(stack_a, stack_b);
		// printf("SORTING BIG STACK\n");
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;

	stack_a = (t_stack *)malloc(sizeof(t_stack));
	if (stack_a == NULL)
		return (0);
	if (!parse_input(argc - 1, argv + 1, &stack_a))
	{
		ft_putstr_fd("\a\a\aINVALID INPUT AAAAAA!\n", 2);
		return (0);
	}
	set_indexes(stack_a);
	sort_stack(stack_a);
	// print_stack(stack_a, 0);
	ft_lstclear(&stack_a->start, free);
	free(stack_a);
	return (0);
}
