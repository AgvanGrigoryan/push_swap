/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:08:12 by aggrigor          #+#    #+#             */
/*   Updated: 2024/02/25 21:00:22 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a, bool print_action)
{
	int	tmp;

	if (a && a->start && a->start->next)
	{
		tmp = a->start->num;
		a->start->num = a->start->next->num;
		a->start->next->num = tmp;
		if (print_action == PRINT_ACTION)
			ft_putstr_fd("sa\n", 1);
	}
}

void	sb(t_stack *b, bool print_action)
{
	int	tmp;

	if (b && b->start && b->start->next)
	{
		tmp = b->start->num;
		b->start->num = b->start->next->num;
		b->start->next->num = tmp;
		if (print_action == PRINT_ACTION)
			ft_putstr_fd("sb\n", 1);
	}
}

void	ss(t_stack *a, t_stack *b, bool print_action)
{
	sa(a, DONT_PRINT_ACTION);
	sb(b, DONT_PRINT_ACTION);
	if (print_action == PRINT_ACTION)
		ft_putstr_fd("ss\n", 1);
}
