/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:07:58 by aggrigor          #+#    #+#             */
/*   Updated: 2024/02/25 17:23:34 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int	ft_log(int base, int num)
{
	int	i;

	i = 0;
	while (num > 1)
	{
		num /= base;
		i++;
	}
	return (i);
}

int	ft_sqrt(int nb)
{
	long long	i;

	i = 1;
	if (nb == 1)
		return (1);
	else if (nb < 0)
		return (0);
	while (i * i < nb)
	{
		if (i >= 46341)
			return (0);
		i++;
	}
	return (i - 1);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;

	stack_a = (t_stack *)malloc(sizeof(t_stack));
	if (stack_a == NULL)
		return (0);
	if (!parse_input(argc - 1, argv + 1, &stack_a))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	set_indexes(stack_a);
	sort_stack(stack_a);
	// ft_lstclear(&stack_a->start, free);
	// free(stack_a);
	return (0);
}
