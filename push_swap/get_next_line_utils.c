/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:36:42 by aggrigor          #+#    #+#             */
/*   Updated: 2024/02/26 17:00:21 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl_list	*ft_gnl_lstnew(void *content)
{
	t_gnl_list	*new_lst;

	new_lst = (t_gnl_list *)malloc(sizeof(t_gnl_list) * 1);
	if (new_lst == NULL)
		return (NULL);
	new_lst->value = content;
	new_lst->next = NULL;
	return (new_lst);
}

void	ft_lstdelone(t_gnl_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->value);
	free(lst);
}

int	is_end_of_line(char *buf)
{
	if (buf == NULL)
		return (0);
	while (*buf)
	{
		if (*buf == '\n')
			return (1);
		buf++;
	}
	return (0);
}

int	count_line_len(t_gnl_list *line)
{
	int	line_len;
	int	i;

	line_len = 0;
	while (line && line->value)
	{
		i = 0;
		while (line->value[i] && line->value[i] != '\n')
		{
			line_len++;
			i++;
		}
		if (line->value[i] == '\n')
		{
			line_len++;
			break ;
		}
		line = line->next;
	}
	return (line_len);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
