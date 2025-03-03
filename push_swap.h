/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:31:56 by ymouchta          #+#    #+#             */
/*   Updated: 2025/03/03 15:51:14 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	int				data;
	int				index;
	int				position;
	int				cost;
	int				value;
	struct s_list	*target;
	struct s_list	*next;
}	t_list;

//freee
void	ft_free_str(char **str);
void	ft_free_tab_str(char ***str);
void	ft_free_int(int ***tab);
void	ft_free_stack(t_list **lst);
void	ft_error(void);

//operations
void	sa(t_list **lst);
void	sb(t_list **lst);
void	pa(t_list **lst_a, t_list **lst_b);
void	pb(t_list **lst_a, t_list **lst_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	ra(t_list **lst);
void	rb(t_list **lst);
void	rrr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **lst);
void	rrb(t_list **lst);

//libft
int		ft_atoi(const char *str, int *check);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);

//linked_list
t_list	*ft_create_stack(int **input, int count);
t_list	*ft_lstnew(int content, int index);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
int		ft_lstsize(t_list *lst);

//utils_sort
int		**ft_sort_int_tab(int **tab, int count);
int		ft_get_cost(t_list *stack_a, t_list *stack_b, t_list *tar);

//sort
void	ft_sort_if_three(t_list **lst_a, t_list **lst_b, int count);
void	ft_sort_tow(t_list **lst);
void	ft_sort_three(t_list **lst);
t_list	*get_min_cost(t_list *stack);

//set_struct
void	set_target(t_list *stack_a, t_list *stack_b);
void	set_index(t_list *stack_a, t_list *stack_b);
void	set_cost(t_list *stack_a, t_list *stack_b);
void	set_position(t_list *stack_a, t_list *stack_b);

//utils_push
void	move_a_to_top(t_list **stack_a, t_list *tmp);
void	push(t_list **stack_a, t_list **stack_b);
t_list	*get_min_data(t_list *stack);

//input 
int		**get_int_arg(int argc, char **argv, int *count);

#endif