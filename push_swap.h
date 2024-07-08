/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:58:24 by athonda           #+#    #+#             */
/*   Updated: 2024/07/08 20:53:27 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>

typedef	struct s_box t_box;
struct s_box
{
	int		value;
	t_box	*previous;
	t_box	*next;
};
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_count_words(char const *str, char delimiter);
void	ft_cleanmem(unsigned int i, char **word);
int	ft_setstr(char const *s, char c, size_t nbr_words, char **word);
char	**ft_split(char const *s, char c);
#endif // PUSH_SWAP_H
