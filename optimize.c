/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:50:05 by athonda           #+#    #+#             */
/*   Updated: 2024/07/15 21:01:57 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @fn int	calc_cost()
 * @brief calcurate how many steps to be the top of the list
 * @param[in] head address of the head node of the list
 * @param[in] node	to be calcurated
 * @param[in,out] prevcost steps by the previous direction
 * @param[in,out] nextcost steps by the next direction
 * @return lower cost in prevcost or nextcost
 */

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

/**
 * @fn
 */

t_box	*find_base(t_box **head_base, t_box **head_target)
{
	t_box	*node;
	t_box	*target;
	t_box	*base;
	int		prevcost;
	int		nextcost;
	int		cost_total_min;
	int		cost_total;
	int		cost_target;
	int		cost_base;
	int		i;

	i = 0;
	cost_total_min = 2147483647;
	node = *head_base;
	while (cost_total_min > i)
	{
		target = find_target_largest_smaller(node, head_target);
		cost_target = calc_cost(head_target, target, &prevcost, &nextcost);
		cost_base = calc_cost(head_base, node, &prevcost, &nextcost);
		cost_total = cost_target + cost_base;
		if (cost_total < cost_total_min)
		{
			cost_total_min = cost_total;
			base = node;
		}
		i++;
		node = node->next;
	}
	return (base);
}

/**
 * @fn void	revolver(t_box **head_a, t_box **head_b, t_box *base, t_box *target)
 * @brief calculate the cost for base node and target node, rotate them efficiently
 *
 */

void	revolver(t_box **head_a, t_box **head_b, t_box *base, t_box *target)
{
	int	prevcost;
	int	nextcost;

	calc_cost(head_b, target, &prevcost, &nextcost);
	while (target != *head_b)
	{
		if (prevcost < nextcost)
			rb(head_b);
		else
			rrb(head_b);
	}
	calc_cost(head_a, base, &prevcost, &nextcost);
	while (base != *head_a)
	{
		if (prevcost < nextcost)
			ra(head_a);
		else
			rra(head_a);
	}
}