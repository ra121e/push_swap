/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:34:03 by athonda           #+#    #+#             */
/*   Updated: 2024/07/30 21:55:29 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	preprocess(t_box **head_a, t_box **head_b)
{
	int		max;
	int		min;
	int		nbr;
	t_box	*now;

	nbr = 0;
	max = (*head_a)->value;
	min = (*head_a)->value;
	now = *head_a;
	while (1)
	{
		nbr++;
		if (now->value > max)
			max = now->value;
		if (now->value < min)
			min = now->value;
		now = now->next;
		if (now == *head_a)
			break ;
	}
	divide_forward(head_a, head_b, min, max);
}
