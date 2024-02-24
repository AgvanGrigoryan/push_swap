/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:08:35 by aggrigor          #+#    #+#             */
/*   Updated: 2024/02/23 20:17:34 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	t_list	*tmp;

	if (a && b && b->start)
	{
		tmp = b->start;
		b->start = b->start->next;
		if (b->start)
			b->start->prev = NULL;
		tmp->next = a->start;
		if (a->start)
			a->start->prev = tmp;
		a->start = tmp;
		if (a->end == NULL)
			a->end = a->start;
		if (b->start == NULL)
			b->end = NULL;
		a->size++;
		b->size--;
	}
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack *a, t_stack *b)
{
	t_list	*tmp;

	if (b && a && a->start)
	{
		tmp = a->start;
		a->start = a->start->next;
		if (a->start)
			a->start->prev = NULL;
		tmp->next = b->start;
		if (b->start)
			b->start->prev = tmp;
		b->start = tmp;
		if (b->end == NULL)
			b->end = b->start;
		if (a->start == NULL)
			a->end = NULL;
		b->size++;
		a->size--;
	}
	ft_putstr_fd("pb\n", 1);
}
