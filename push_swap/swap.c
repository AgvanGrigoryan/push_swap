/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:08:12 by aggrigor          #+#    #+#             */
/*   Updated: 2024/02/23 15:31:59 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	int	tmp;

	if (a && a->start && a->start->next)
	{
		tmp = a->start->num;
		a->start->num = a->start->next->num;
		a->start->next->num = tmp;
		ft_putstr_fd("sa\n", 1);
	}
}

void	sb(t_stack *b)
{
	int	tmp;

	if (b && b->start && b->start->next)
	{
		tmp = b->start->num;
		b->start->num = b->start->next->num;
		b->start->next->num = tmp;
		ft_putstr_fd("sb\n", 1);
	}
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}
