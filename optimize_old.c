/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_old.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 12:15:29 by athonda           #+#    #+#             */
/*   Updated: 2024/07/27 12:16:52 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	rev_single(t_box **head_a, t_box **head_b, t_box *base, t_box *target)
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
