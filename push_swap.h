/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:58:24 by athonda           #+#    #+#             */
/*   Updated: 2024/07/12 18:06:08 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>

typedef	struct s_box t_box;
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
size_t	ft_count_words(char const *str, char delimiter);
void	ft_cleanmem(unsigned int i, char **word);
int		ft_setstr(char const *s, char c, size_t nbr_words, char **word);
char	**ft_split(char const *s, char c);
int		ft_isspace(char c);
int		ft_isdigit(int c);
int		ft_atoi(const char *nptr);
t_box	*ft_lstnew(int nbr);
t_box	*ft_lstlast(t_box *lst);
void	ft_lstadd_front(t_box **lst, t_box *new);
t_box	*ft_lstcut_front(t_box **lst);
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
#endif // PUSH_SWAP_H
