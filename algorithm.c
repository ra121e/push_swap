/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 20:52:11 by athonda           #+#    #+#             */
/*   Updated: 2024/07/18 18:09:03 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_box	*find_target_largest_smaller(t_box *node, t_box **head_to)
{
	t_box	*now;
	int		def;
	t_box	*node_max;
	t_box	*target;

	now = *head_to;
	def	= 2147483647;
	target = NULL;
	node_max = ft_lstmax(head_to);
	while (1)
	{
		if (now->value < node->value && (node->value - now->value) < def)
		{
			def = node->value - now->value;
			target = now;
		}
		now = now->next;
		if (now == *head_to)
		{
			if (target == NULL)
				target = node_max;
			return(target);
		}
	}
}

t_box	*find_target_smallest_larger(t_box *node, t_box **head_to)
{
	t_box	*now;
	int		def;
	t_box	*node_min;
	t_box	*target;

	now = *head_to;
	def	= 2147483647;
	target = NULL;
	node_min = ft_lstmin(head_to);
	while (1)
	{
		if (now->value > node->value && now->value - node->value < def)
		{
			def = now->value - node->value;
			target = now;
		}
		now = now->next;
		if (now == *head_to)
		{
			if (target == NULL)
				target = node_min;
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

void	last_rotation(t_box **head)
{
	t_box	*node_min;
	int		prevcost;
	int		nextcost;

	node_min = ft_lstmin(head);
	calc_cost(head, node_min, &prevcost, &nextcost);
	while (node_min != *head)
	{
		if (prevcost < nextcost)
			ra(head);
		else
			rra(head);
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
	last_rotation(head_a);
}