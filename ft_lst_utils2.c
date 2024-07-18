/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:01:50 by athonda           #+#    #+#             */
/*   Updated: 2024/07/18 16:40:10 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_box	*ft_lstmin(t_box **lst)
{
	t_box	*ptr;
	t_box	*min_node;
	int		min;

	ptr = *lst;
	min_node = NULL;
	min = 2147483647;
	if (ptr == NULL)
		return (NULL);
	while (1)
	{
		if (min > ptr->value)
		{
			min = ptr->value;
			min_node = ptr;
		}
		ptr = ptr->next;
		if (ptr == *lst)
		{
			return (min_node);
		}
	}
}