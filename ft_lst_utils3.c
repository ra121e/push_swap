/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:43:53 by athonda           #+#    #+#             */
/*   Updated: 2024/07/31 18:47:00 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stackmin(t_box **head_a, t_box **head_b)
{
	int		min;
	t_box	*now;

	now = *head_b;
	min = now->value;
	while (1)
	{
		if (now->value < min)
			min = now->value;
		now = now->next;
		if (now == *head_b && *head_a != NULL)
			now = (*head_a)->next;
		else if (now == *head_b)
			return (min);
		if (now == *head_a)
			return (min);
	}
}

int	ft_stackmax(t_box **head_a, t_box **head_b)
{
	int		max;
	t_box	*now;

	now = *head_b;
	max = now->value;
	while (1)
	{
		if (now->value > max)
			max = now->value;
		now = now->next;
		if (now == *head_b && *head_a != NULL)
			now = (*head_a)->next;
		else if (now == *head_b)
			return (max);
		if (now == *head_a)
			return (max);
	}
}
