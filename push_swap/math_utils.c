/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 19:55:24 by aggrigor          #+#    #+#             */
/*   Updated: 2024/02/25 21:24:38 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
