/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:40:12 by aggrigor          #+#    #+#             */
/*   Updated: 2024/02/26 16:58:06 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif 

typedef struct s_gnl_list
{
	char				*value;
	struct s_gnl_list	*next;
}	t_gnl_list;

char		*get_next_line(int fd);
int			ft_read_line(int fd, t_gnl_list *line);
char		*make_result_line(char *result, t_gnl_list **line, int line_len);
int			count_line_len(t_gnl_list *line);
char		*ft_strcpy(char *dest, char *src);
int			is_end_of_line(char *buf);
t_gnl_list	*ft_gnl_lstnew(void *content);
void		ft_lstdelone(t_gnl_list *lst, void (*del)(void *));

#endif 