/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:50:05 by athonda           #+#    #+#             */
/*   Updated: 2024/07/15 10:57:04 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_cost(t_box **head, t_box *node, int *prevcost, int *nextcost)
{
	int		cost;
	t_box	*now;

	now = node;
	*prevcost = 0;
	*nextcost = 0;
	while (now != *head)
	{
		(*prevcost)++;
		now = now->prev;
	}
	cost = *prevcost;
	now = node;
	while (now != *head)
	{
		(*nextcost)++;
		now = now->next;
	}
	if (cost > *nextcost)
		cost = *nextcost;
	return (cost);
}