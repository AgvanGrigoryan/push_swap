/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:03:15 by aggrigor          #+#    #+#             */
/*   Updated: 2024/02/26 20:42:47 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_butterfly(t_stack *stack_a, t_stack *stack_b)
{
	int	counter;
	int	offset;

	counter = 0;
	offset = ft_log(2, stack_a->size) + ft_sqrt(stack_a->size);
	while (stack_a->size > 0)
	{
		if (stack_a->start->index <= counter)
		{
			pb(stack_a, stack_b, PRINT_ACTION);
			rb(stack_b, PRINT_ACTION);
			counter++;
		}
		else if (stack_a->start->index <= counter + offset)
		{
			pb(stack_a, stack_b, PRINT_ACTION);
			counter++;
		}
		else
			ra(stack_a, PRINT_ACTION);
	}
}

// sort 3 items
void	sort_3elem_stack(t_stack *stack_a)
{
	if (is_stack_sorted(stack_a))
		return ;
	if (stack_a->start->num < stack_a->start->next->num)
		rra(stack_a, PRINT_ACTION);
	if (is_stack_sorted(stack_a))
		return ;
	if (stack_a->start->num > stack_a->start->next->num
		&& (stack_a->start->num < stack_a->end->num
			|| stack_a->start->next->num > stack_a->end->num))
		sa(stack_a, PRINT_ACTION);
	else
		ra(stack_a, PRINT_ACTION);
	if (stack_a->end->num < stack_a->start->num)
		rra(stack_a, PRINT_ACTION);
}

// sort less than 5 items
void	sort_5elem_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	a_min_ind;

	if (is_stack_sorted(stack_a))
		return ;
	a_min_ind = 0;
	while (stack_a->size > 3 && stack_b->size < 2)
	{
		if (stack_a->start->index == a_min_ind)
		{
			pb(stack_a, stack_b, PRINT_ACTION);
			a_min_ind++;
		}
		else if (get_ipos(stack_a->start, a_min_ind) >= 1 + (stack_a->size / 2))
			rra(stack_a, PRINT_ACTION);
		else if (get_ipos(stack_a->start, a_min_ind) < 1 + (stack_a->size / 2))
			ra(stack_a, PRINT_ACTION);
	}
	sort_3elem_stack(stack_a);
	while (stack_b->size > 0)
		pa(stack_a, stack_b, PRINT_ACTION);
}
#include <stdio.h>
// Sort grather than 5 items
void	sort_big_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	b_max_ind;

	if (is_stack_sorted(stack_a))
		return ;
	ft_butterfly(stack_a, stack_b);
	b_max_ind = stack_b->size - 1;
	while (stack_b->size > 0)
	{
		if (stack_b->start->index == b_max_ind)
		{
			pa(stack_a, stack_b, PRINT_ACTION);
			b_max_ind--;
		}
		else if (get_ipos(stack_b->start, b_max_ind) >= 1 + (stack_b->size / 2))
			rrb(stack_b, PRINT_ACTION);
		else if (get_ipos(stack_b->start, b_max_ind) < 1 + (stack_b->size / 2))
			rb(stack_b, PRINT_ACTION);
	}
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
		sa(stack_a, PRINT_ACTION);
	else if (stack_a->size == 3)
		sort_3elem_stack(stack_a);
	else if (stack_a->size <= 5)
		sort_5elem_stack(stack_a, stack_b);
	else
		sort_big_stack(stack_a, stack_b);
	ft_lstclear(&stack_a->start, free);
	free(stack_a);
}
