/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 20:52:11 by athonda           #+#    #+#             */
/*   Updated: 2024/07/16 09:47:42 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_box	*find_target_largest_smaller(t_box *node, t_box **head_to)
{
	t_box	*now;
	int		def;
	int		max;
	t_box	*max_node;
	t_box	*target;

	now = *head_to;
	max = node->value;
	def	= 2147483647;
	target = NULL;
	while (1)
	{
		if (now->value > max)
		{
			max = now->value;
			max_node = now;
		}
		if (now->value < node->value && (node->value - now->value) < def)
		{
			def = node->value - now->value;
			target = now;
		}
		now = now->next;
		if (now == *head_to)
		{
			if (target == NULL)
				target = max_node;
			return(target);
		}
	}
}

t_box	*find_target_smallest_larger(t_box *node, t_box **head_to)
{
	t_box	*now;
	int		def;
	int		min;
	t_box	*min_node;
	t_box	*target;

	now = *head_to;
	min = node->value;
	def	= 2147483647;
	target = NULL;
	while (1)
	{
		if (now->value < min)
		{
			min = now->value;
			min_node = now;
		}
		if (now->value > node->value && now->value - node->value < def)
		{
			def = now->value - node->value;
			target = now;
		}
		now = now->next;
		if (now == *head_to)
		{
			if (target == NULL)
				target = min_node;
			return(target);
		}
	}
}

void	push_forward(t_box **head_a, t_box **head_b)
{
	t_box	*last_box;
	t_box	*target;
	t_box	*base;

	last_box = (*head_a)->prev;
	while ((last_box->prev)->prev != *head_a)
	{
		if (*head_b == NULL || (*head_b)->next == NULL)
		{
			pa(head_a, head_b);
			if ((*head_b)->next != NULL && (*head_b)->value < ((*head_b)->next)->value)
				sb(head_b);
		}
		else
		{
			target = NULL;
			base = find_base(head_a, head_b);
			target = find_target_largest_smaller(base, head_b);
			revolver(head_a, head_b, base, target);
			pa(head_a, head_b);
			last_box = (*head_a)->prev;
		}
	}
}

void	push_back(t_box **head_a, t_box **head_b)
{
	int		prevcost;
	int		nextcost;
	t_box	*target;

	while (*head_b != NULL)
	{
		target = find_target_smallest_larger(*head_b, head_a);
		calc_cost(head_a, target, &prevcost, &nextcost);
		while (target != *head_a)
		{
			if (prevcost < nextcost)
				rb(head_a);
			else
				rrb(head_a);
		}
		pb(head_b, head_a);
	}
}

void	turk_algo(t_box **head_a, t_box **head_b)
{
	t_box	*box1;
	t_box	*box2;
	t_box	*last_box;

	box1 = *head_a;
	box2 = box1->next;
	last_box = box1->prev;
	if (*head_a == NULL || box2 == NULL)
		return;
	if (box2->next == box1)
	{
		two_case(head_a);
		return;
	}
	else if (box2->next == last_box)
	{
		three_case(head_a);
		return;
	}
	push_forward(head_a, head_b);
	three_case(head_a);
	push_back(head_a, head_b);
}