/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 18:30:07 by athonda           #+#    #+#             */
/*   Updated: 2024/07/20 13:52:25 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_prev(t_box **head_a, t_box **head_b, int prev_a, int prev_b)
{
	if (prev_a > prev_b)
	{
		repeat_rr(head_a, head_b, prev_b);
		repeat_ra(head_a, prev_a - prev_b);
	}
	else
	{
		repeat_rr(head_a, head_b, prev_a);
		repeat_rb(head_b, prev_b - prev_a);
	}
}

void	double_next(t_box **head_a, t_box **head_b, int next_a, int next_b)
{
	if (next_a > next_b)
	{
		repeat_rrr(head_a, head_b, next_b);
		repeat_rra(head_a, next_a - next_b);
	}
	else
	{
		repeat_rrr(head_a, head_b, next_a);
		repeat_rrb(head_b, next_b - next_a);
	}
}

void	preva_nextb(t_box **head_a, t_box **head_b, int prev_a, int next_b)
{
	repeat_ra(head_a, prev_a);
	repeat_rrb(head_b, next_b);
}

void	nexta_prevb(t_box **head_a, t_box **head_b, int next_a, int prev_b)
{
	repeat_rra(head_a, next_a);
	repeat_rb(head_b, prev_b);
}

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