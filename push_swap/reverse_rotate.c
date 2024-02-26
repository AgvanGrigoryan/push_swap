/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 21:50:43 by aggrigor          #+#    #+#             */
/*   Updated: 2024/02/25 20:58:43 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a, bool print_action)
{
	t_list	*tmp;

	if (a && a->start && a->end && a->start != a->end)
	{
		tmp = a->end;
		a->end = a->end->prev;
		a->end->next = NULL;
		tmp->prev = NULL;
		a->start->prev = tmp;
		tmp->next = a->start;
		a->start = a->start->prev;
	}
	if (print_action == PRINT_ACTION)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack *b, bool print_action)
{
	t_list	*tmp;

	if (b && b->start && b->end && b->start != b->end)
	{
		tmp = b->end;
		b->end = b->end->prev;
		b->end->next = NULL;
		tmp->prev = NULL;
		b->start->prev = tmp;
		tmp->next = b->start;
		b->start = b->start->prev;
	}
	if (print_action == PRINT_ACTION)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack *a, t_stack *b, bool print_action)
{
	rra(a, DONT_PRINT_ACTION);
	rrb(b, DONT_PRINT_ACTION);
	if (print_action == PRINT_ACTION)
		ft_putstr_fd("rrr]n", 1);
}
