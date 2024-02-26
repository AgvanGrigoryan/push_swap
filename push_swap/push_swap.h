/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <aggrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:17:01 by aggrigor          #+#    #+#             */
/*   Updated: 2024/02/26 15:42:35 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stddef.h>
# include <stdbool.h>

# define MAX_LEN_OF_INT 10
# define PRINT_ACTION true
# define DONT_PRINT_ACTION false

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
void		sa(t_stack *a, bool print_action);
void		sb(t_stack *b, bool print_action);
void		ss(t_stack *a, t_stack *b, bool print_action);

//push.c
void		pa(t_stack *a, t_stack *b, bool print_action);
void		pb(t_stack *a, t_stack *b, bool print_action);

//rotate.c
void		ra(t_stack *a, bool print_action);
void		rb(t_stack *b, bool print_action);
void		rr(t_stack *a, t_stack *b, bool print_action);

//reverse_rotate.c
void		rra(t_stack *a, bool print_action);
void		rrb(t_stack *b, bool print_action);
void		rrr(t_stack *a, t_stack *b, bool print_action);

//input_validation.c
int			parse_input(int argc, char *argv[], t_stack **stack_a);
long long	ft_atoi(const char *str);

//push_swap_utils.c
void		ft_putstr_fd(char *str, int fd);
int			ft_isspace(char c);
size_t		ft_strlen(const char *s);
int			is_stack_sorted(t_stack *stack_a);
void		ft_free_matrix(char **matrix);

//push_swap_utils2.c
char		**ft_split(char const *s);

//push_swap_utils3.c
t_list		*ft_lstnew(int content, t_list *prev);
int			is_duplicate(t_list *list, int curr_ind, int num);
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		set_indexes(t_stack *stack);
int			get_ipos(t_list *list, int index);

//math_utils.c
int			ft_log(int base, int num);
int			ft_sqrt(int nb);

//push_swap_sort.c
void		sort_stack(t_stack	*stack_a);
void		sort_3elem_stack(t_stack *stack_a);
void		sort_5elem_stack(t_stack *stack_a, t_stack *stack_b);
void		sort_big_stack(t_stack *stack_a, t_stack *stack_b);

#endif
