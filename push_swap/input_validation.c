/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 22:24:01 by aggrigor          #+#    #+#             */
/*   Updated: 2024/02/24 19:30:47 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	is_duplicate(t_list *list, int curr_ind, int num)
{
	int	i;

	i = 0;
	while (i < curr_ind)
	{
		if (list->num == num)
			return (1);
		list = list->next;
		i++;
	}
	return (0);
}

long long	ft_atoi(const char *nptr)
{
	long long	num;
	int			int_start;
	int			sign;
	int			i;

	sign = 1;
	num = 0;
	i = 0;
	while (nptr[i] && ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] && nptr[i] == '0')
		i++;
	int_start = i;
	while (nptr[i] && '0' <= nptr[i] && nptr[i] <= '9')
		num = num * 10 + (nptr[i++] - 48);
	if (nptr[i] != '\0' || i - int_start > MAX_LEN_OF_INT)
		return (LONG_MAX);
	return (num * sign);
}

int	process_one_arg(char *arg, t_list *dummy, t_stack *stack, int total_index)
{
	long long	num;

	if (arg[0] == '-' || arg[0] == '+')
	{
		if (arg[1] == '\0')
			return (0);
	}
	num = ft_atoi(arg);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	if (is_duplicate(dummy->next, total_index, (int)num))
		return (0);
	stack->start->next = ft_lstnew((int)num, stack->start);
	if (stack->start->next == NULL)
		return (0);
	stack->start = stack->start->next;
	return (1);
}

int	process_sub_args(char *arg, t_list *dummy, t_stack *stack, int *total_index)
{
	char		**sub_args;
	int			i;

	i = 0;
	sub_args = ft_split(arg);
	if (sub_args == NULL || sub_args[0] == NULL)
		return (0);
	while (sub_args[i])
	{
		if (!process_one_arg(sub_args[i], dummy, stack, *total_index))
		{
			ft_free_matrix(sub_args);
			return (0);
		}
		i++;
		(*total_index)++;
	}
	ft_free_matrix(sub_args);
	return (1);
}

int	parse_input(int argc, char *argv[], t_stack **stack_a)
{
	t_stack		*stack;
	t_list		dummy;
	int			total_index;
	int			i;

	stack = *stack_a;
	dummy.next = NULL;
	stack->start = &dummy;
	i = 0;
	total_index = 0;
	while (i < argc && argv[i])
	{
		if (!process_sub_args(argv[i++], &dummy, stack, &total_index))
		{
			ft_lstclear(&(dummy.next), free);
			free(stack);
			return (0);
		}
	}
	(*stack_a)->start = dummy.next;
	if ((*stack_a)->start)
		(*stack_a)->start->prev = NULL;
	(*stack_a)->end = (*stack_a)->start;
	while ((*stack_a)->end && (*stack_a)->end->next)
		(*stack_a)->end = (*stack_a)->end->next;
	(*stack_a)->size = ft_lstsize((*stack_a)->start);
	return (1);
}
