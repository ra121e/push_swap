/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:58:24 by athonda           #+#    #+#             */
/*   Updated: 2024/08/06 17:17:17 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define DIVF 3
# define DIVB 2
# define BLOCK_NUM_NO_MOVE 1
# define SAMPLESIZE 100

typedef struct s_box	t_box;
struct s_box
{
	int		value;
	t_box	*prev;
	t_box	*next;
};
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
long	ft_atol(const char *nptr);
size_t	ft_count_words(char const *str, char delimiter);
void	ft_cleanmem(unsigned int i, char **word);
int		ft_setstr(char const *s, char c, size_t nbr_words, char **word);
char	**ft_split(char const *s, char c);
int		check_digit(char **str, int *count, int argc);
int		check_dup(long *nbrs, int count, int argc, char **str);
int		check_sort(long	*nbrs, int count, int argc, char **str);
int		check_arg(char **str, int argc);
void	free_split(char **str);
void	free_array_l(long *nbrs);
void	free_array_i(int *nbrs);
void	free_lst(t_box **head);
int		ft_isspace(char c);
int		ft_isdigit(int c);
int		ft_atoi(const char *nptr);
t_box	*ft_lstnew(int nbr);
t_box	*ft_lstlast(t_box *lst);
void	ft_lstadd_front(t_box **lst, t_box *new);
void	ft_lstadd_back(t_box **lst, t_box *new);
t_box	*ft_lstcut_front(t_box **lst);
t_box	*ft_lstmin(t_box **lst);
t_box	*ft_lstmax(t_box **lst);
int		ft_lstsize(t_box **lst);
int		ft_lstminvalue(t_box **lst);
int		ft_lstmaxvalue(t_box **lst);
int		ft_stackmin(t_box **head_a, t_box **head_b);
int		ft_stackmax(t_box **head_a, t_box **head_b);
t_box	*make_list(t_box *head, char **nbrs);
void	sa(t_box **head_a);
void	sb(t_box **head_b);
void	ss(t_box **head_a, t_box **head_b);
void	ra(t_box **head_a);
void	rb(t_box **head_b);
void	rr(t_box **head_a, t_box **head_b);
void	rra(t_box **head_a);
void	rrb(t_box **head_b);
void	rrr(t_box **head_a, t_box **head_b);
void	pa(t_box **head_a, t_box **head_b);
void	pb(t_box **head_a, t_box **head_b);
void	repeat_ra(t_box **head, int count);
void	repeat_rb(t_box **head, int count);
void	repeat_rr(t_box **head_a, t_box **head_b, int count);
void	repeat_rra(t_box **head, int count);
void	repeat_rrb(t_box **head, int count);
void	repeat_rrr(t_box **head_a, t_box **head_b, int count);
void	turk_algo(t_box **head_a, t_box **head_b);
int		divide_a_r(t_box **head_a, t_box **head_b, int nbr, long long quantile);
int		divide_b_r(t_box **head_a, t_box **head_b, int nbr, long long *quantile);
int		divide_b_rr(t_box **head_a, t_box **head_b, int nbr, long long *quantile);
void	divide_back(t_box **head_a, t_box **head_b, int nbr, long long *quatile);
void	divide_conquer(t_box **head_a, t_box **head_b, long long *quatile);
void	preprocess(t_box **head_a, t_box **head_b);
void	push_forward(t_box **head_a, t_box **head_b);
void	push_back(t_box **head_a, t_box **head_b);
t_box	*find_target_largest_smaller(t_box *node, t_box **head_to);
t_box	*find_target_smallest_larger(t_box *node, t_box **head_to);
void	three_case(t_box **head_a);
void	two_case(t_box **head_a);
int		calc_cost(t_box **head, t_box *node, int *prevcost, int *nextcost);
int		calc_cost_min(t_box **head, t_box *node);
t_box	*find_base(t_box **head_base, t_box **head_target);
void	revolver(t_box **head_a, t_box **head_b, t_box *base, t_box *target);
void	double_prev(t_box **head_a, t_box **head_b, int prev_a, int prev_b);
void	double_next(t_box **head_a, t_box **head_b, int next_a, int next_b);
void	preva_nextb(t_box **head_a, t_box **head_b, int prev_a, int next_b);
void	nexta_prevb(t_box **head_a, t_box **head_b, int next_a, int prev_b);
void	rev_single(t_box **head_a, t_box **head_b, t_box *base, t_box *target);
void	last_rotation(t_box **head);
#endif // PUSH_SWAP_H
