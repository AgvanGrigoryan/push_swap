/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:17:01 by aggrigor          #+#    #+#             */
/*   Updated: 2024/02/23 20:50:45 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define MINI_STACK_SIZE 3
# define MAX_LEN_OF_INT 10

typedef struct s_list
{
	int				num;
	int				index;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_stack
{
	t_list	*start;
	t_list	*end;
	int		size;
}	t_stack;

//swap.c
void		sa(t_stack *a);
void		sb(t_stack *b);
void		ss(t_stack *a, t_stack *b);

//push.c
void		pa(t_stack *a, t_stack *b);
void		pb(t_stack *a, t_stack *b);

//rotate.c
void		ra(t_stack *a);
void		rb(t_stack *b);
void		rr(t_stack *a, t_stack *b);

//reverse_rotate.c
void		rra(t_stack *a);
void		rrb(t_stack *b);
void		rrr(t_stack *a, t_stack *b);

//input_validation.c
int			parse_input(int argc, char *argv[], t_stack **stack_a);
long long	ft_atoi(const char *str);

//push_swap_utils.c
void		ft_putstr_fd(char *str, int fd);
int			ft_isspace(char c);
size_t		ft_strlen(const char *s);
int			is_a_sorted(t_stack *stack_a);
void		ft_free_matrix(char **matrix);

//push_swap_utils2.c
char		**ft_split(char const *s);

//push_swap_utils3.c
t_list		*ft_lstnew(int content, t_list *prev);
int			ft_lstsize(t_list *lst);
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		set_indexes(t_stack *stack);
int			get_pos_at_index(t_list *list, int index);

//print_funcs.c
void		print_stack(t_stack *stack, int mode);
void		print_stacks(t_list *stack_a, t_list *stack_b);

#endif
