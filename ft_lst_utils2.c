/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:01:50 by athonda           #+#    #+#             */
/*   Updated: 2024/07/31 11:41:18 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_box	*ft_lstmin(t_box **lst)
{
	t_box	*ptr;
	t_box	*node_min;
	int		min;

	ptr = *lst;
	node_min = NULL;
	min = 2147483647;
	if (ptr == NULL)
		return (NULL);
	while (1)
	{
		if (min > ptr->value)
		{
			min = ptr->value;
			node_min = ptr;
		}
		ptr = ptr->next;
		if (ptr == *lst)
		{
			return (node_min);
		}
	}
}

t_box	*ft_lstmax(t_box **lst)
{
	t_box	*ptr;
	t_box	*node_max;
	int		max;

	ptr = *lst;
	node_max = NULL;
	max = -2147483648;
	if (ptr == NULL)
		return (NULL);
	while (1)
	{
		if (max < ptr->value)
		{
			max = ptr->value;
			node_max = ptr;
		}
		ptr = ptr->next;
		if (ptr == *lst)
		{
			return (node_max);
		}
	}
}

int	ft_lstsize(t_box **lst)
{
	int		nbr;
	t_box	*now;

	now = *lst;
	nbr = 0;
	if (now == NULL)
		return (0);
	while (1)
	{
		nbr++;
		now = now->next;
		if (now == *lst)
			return (nbr);
	}
}

int	ft_lstminvalue(t_box **lst)
{
	int		min;
	t_box	*now;

	now = *lst;
	min = now->value;
	while (1)
	{
		if (now->value < min)
			min = now->value;
		now = now->next;
		if (now == *lst)
			return (min);
	}
}

int	ft_lstmaxvalue(t_box **lst)
{
	int		max;
	t_box	*now;

	now = *lst;
	max = now->value;
	while (1)
	{
		if (now->value > max)
			max = now->value;
		now = now->next;
		if (now == *lst)
			return (max);
	}
}
