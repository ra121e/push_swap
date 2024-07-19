/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:22:20 by athonda           #+#    #+#             */
/*   Updated: 2024/07/19 12:27:32 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file make_list.c
 * @brief make new node, store numbers in node, connect nodes, point head node
 */

#include "push_swap.h"

/**
 * @fn int ft_atoi(const char *nptr)
 * @brief combine the number characters into number value
 * @param[in] nptr
 * @return the value or 0 in case error
 * @sa ft_isdigit ft_isspace:inside the file
 * @note get string by pointer and check each char by 3 stage rocket
	- 1st stage ignore space
	- 2nd stage check + or -
	- 3rd stage get number and convert into a variable
	- finally put negative
*/

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n' || \
		c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	nbr;
	int	sign;
	int	i;

	sign = 1;
	nbr = 0;
	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		nbr = nbr * 10 + (nptr[i] - '0');
		i++;
	}
	return (nbr * sign);
}

/**
 * @fn t_box	*make_list(t_box *head, char **nbrs)
 * @brief get numbers array and complete link list
 * @sa ft_lst_utils.c
 * @note How to initialize head node
	- lst functions check list existance by NULL of head node.
	- **head declare and NULL init hit NULL check in lst handles
	- *head declare and NULL init means &head itself is not NULL
 */

t_box	*make_list(t_box *head_a, char **nbrs)
{
	int		nbr;
	t_box	*node;

	head_a = NULL;
	while (*nbrs)
	{
		nbr = ft_atoi(*nbrs);
		node = ft_lstnew(nbr);
		ft_lstadd_back(&head_a, node);
		nbrs++;
	}
	return (head_a);
}
