/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 10:50:05 by athonda           #+#    #+#             */
/*   Updated: 2024/08/07 14:18:32 by athonda          ###   ########.fr       */
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
 * @fn int	calc_cost_min()
 * @brief calcurate how many steps to be the top of the list
 * @param[in] head address of the head node of the list
 * @param[in] node	to be calcurated
 * @return lower cost in prevcost or nextcost
 */

int	calc_min(t_box **head, t_box *node)
{
	int		cost;
	t_box	*now;
	int		prevcost;
	int		nextcost;

	now = node;
	prevcost = 0;
	nextcost = 0;
	while (now != *head)
	{
		prevcost++;
		now = now->prev;
	}
	cost = prevcost;
	now = node;
	while (now != *head)
	{
		nextcost++;
		now = now->next;
	}
	if (cost > nextcost)
		cost = nextcost;
	return (cost);
}

/**
 * @fn t_box	*find_base(t_box **head_base, t_box **head_target)
 * @brief find the lowest cost node in base stack
 * @param[in] head_base head of the list from, basically stack_a
 * @param[in] head_target head of the list to, basically stack_b
 * @return base which is the lowest cost node to push out
 */

t_box	*find_base(t_box **head_base, t_box **head_target)
{
	t_box	*target;
	t_box	*base;
	t_box	*now;
	int		cost_min;
	int		cost;

	now = *head_base;
	base = now;
	cost_min = 2147483647;
	while (1)
	{
		target = find_target_largest_smaller(now, head_target);
		cost = calc_min(head_target, target) + calc_min(head_base, now);
		if (cost < cost_min || (cost == cost_min && now->value < base->value))
		{
			cost_min = cost;
			base = now;
		}
		now = now->next;
		if (now == *head_base)
			return (base);
	}
	return (base);
}

/**
 * @fn void	revolver(t_box **head_a, t_box **head_b, t_box *base, t_box *target)
 * @brief calculate the cost for base and target node, rotate them efficiently
 * @param[in] head_a list of the base node
 * @param[in] head_b list of the target node
 * @param[in] base node the lowest cost to push out
 * @param[in] target node the target to push the base node on
 * @sa calc_cost, rb, rrb, ra, rra
 * @note get cost to pick the node up to surface by 2 direction
 */

void	revolver(t_box **head_a, t_box **head_b, t_box *base, t_box *target)
{
	int	prev_a;
	int	next_a;
	int	prev_b;
	int	next_b;

	calc_cost(head_b, target, &prev_b, &next_b);
	calc_cost(head_a, base, &prev_a, &next_a);
	if (prev_a < next_a)
	{
		if (prev_b - prev_a < next_b)
			double_prev(head_a, head_b, prev_a, prev_b);
		else
			preva_nextb(head_a, head_b, prev_a, next_b);
	}
	else
	{
		if (next_b - next_a < prev_b)
			double_next(head_a, head_b, next_a, next_b);
		else
			nexta_prevb(head_a, head_b, next_a, prev_b);
	}
}
