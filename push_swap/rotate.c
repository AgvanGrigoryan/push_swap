/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:07:41 by aggrigor          #+#    #+#             */
/*   Updated: 2024/02/20 11:33:55 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
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
	}
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack *b)
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
	}
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}
