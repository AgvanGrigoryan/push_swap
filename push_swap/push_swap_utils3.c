/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:47:22 by aggrigor          #+#    #+#             */
/*   Updated: 2024/02/25 17:17:29 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content, t_list *prev)
{
	t_list	*new_lst;

	new_lst = (t_list *)malloc(sizeof(t_list) * 1);
	if (new_lst == NULL)
		return (NULL);
	new_lst->num = content;
	new_lst->next = NULL;
	new_lst->prev = prev;
	return (new_lst);
}

int	is_duplicate(t_list *list, int curr_ind, int num)
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

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		next = (*lst)->next;
		free(*lst);
		*lst = next;
	}
	*lst = NULL;
}

void	set_indexes(t_stack *stack)
{
	t_list	*list_ptr;
	t_list	*ptr2;

	list_ptr = stack->start;
	while (list_ptr)
	{
		list_ptr->index = 0;
		list_ptr = list_ptr->next;
	}
	list_ptr = stack->start;
	while (list_ptr)
	{
		ptr2 = stack->start;
		while (ptr2)
		{
			if (list_ptr != ptr2 && list_ptr->num > ptr2->num)
				list_ptr->index += 1;
			ptr2 = ptr2->next;
		}
		list_ptr = list_ptr->next;
	}
}

int	get_ipos(t_list *list, int index)
{
	int	pos;

	pos = 0;
	while (list)
	{
		if (list->index == index)
			return (pos);
		list = list->next;
		pos++;
	}
	return (-1);
}
