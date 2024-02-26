/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:07:41 by aggrigor          #+#    #+#             */
/*   Updated: 2024/02/25 21:24:56 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a, bool print_action)
{
	t_list	*tmp_node;

	if (a && a->start && a->end && a->start != a->end)
	{
		tmp_node = a->start;
		a->start = a->start->next;
		a->start->prev = NULL;
		tmp_node->prev = a->end;
		a->end->next = tmp_node;
		a->end = a->end->next;
		a->end->next = NULL;
		if (print_action == PRINT_ACTION)
			ft_putstr_fd("ra\n", 1);
	}
}

void	rb(t_stack *b, bool print_action)
{
	t_list	*tmp_node;

	if (b && b->start && b->end && b->start != b->end)
	{
		tmp_node = b->start;
		b->start = b->start->next;
		b->start->prev = NULL;
		tmp_node->prev = b->end;
		b->end->next = tmp_node;
		b->end = b->end->next;
		b->end->next = NULL;
		if (print_action == PRINT_ACTION)
			ft_putstr_fd("rb\n", 1);
	}
}

void	rr(t_stack *a, t_stack *b, bool print_action)
{
	ra(a, DONT_PRINT_ACTION);
	rb(b, DONT_PRINT_ACTION);
	if (print_action == PRINT_ACTION)
		ft_putstr_fd("rr\n", 1);
}
