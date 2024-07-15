/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 20:52:11 by athonda           #+#    #+#             */
/*   Updated: 2024/07/15 09:54:28 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @fn void	two_case(t_box **head_a)
 * @brief 2 node in stack a
 * @param[in] head_a is stack a link list
 */

void	two_case(t_box **head_a)
{
	t_box	*box1;
	t_box	*box2;

	box1 = *head_a;
	box2 = box1->next;
	if (box2->value < box1->value)
	{
		sa(head_a);
	}
	return;
}

/**
 * @fn void	three_case(t_box **head_a)
 * @brief sort 3 numbers
 * @param[in] head address of linked list
 * @return no
 * @note readable or norm
 */

void	three_case(t_box **head_a)
{
	t_box	*box1;
	t_box	*box2;
	t_box	*last_box;

	box1 = *head_a;
	box2 = box1->next;
	last_box = box1->prev;
	if (box1->value < box2->value && box1->value < last_box->value)
	{
		if (box2->value > last_box->value)
		{
			sa(head_a);
			ra(head_a);
		}
	}
	else if(box1->value > box2->value && box1->value > last_box->value)
	{
		if (box2->value < last_box->value)
			ra(head_a);
		else
		{
			sa(head_a);
			rra(head_a);
		}
	}
	else
	{
		if (box2->value < last_box->value)
			sa(head_a);
		else
			rra(head_a);
	}
}

void	find_target_b(t_box **head_from, t_box **head_to, t_box **target)
{
	t_box	*now;
	int		def;
	int		max;
	int		min;
	t_box	*max_node;

	if (*head_to == NULL || (*head_to)->next == NULL)
		pa(head_from, head_to);
	else
	{
		now = *head_to;
		max = (*head_from)->value;
		min = (*head_from)->value;
		def	= 2147483647;
		while (1)
		{
			if (now->value > max)
			{
				max = now->value;
				max_node = now;
			}
			if (now->value < min)
				min = now->value;
			if (now->value < (*head_from)->value && ((*head_from)->value - now->value) < def)
			{
				def = (*head_from)->value - now->value;
				*target = now;
			}
			now = now->next;
			if (now == *head_to)
			{
				if (*target == NULL)
					*target = max_node;
				break;
			}
		}
	}
}

void	find_target_a(t_box **head_from, t_box **head_to, t_box **target)
{
	t_box	*now;
	int		def;
	int		max;
	int		min;
	t_box	*min_node;

	if (*head_to == NULL || (*head_to)->next == NULL)
		pa(head_from, head_to);
	else
	{
		now = *head_to;
		max = (*head_from)->value;
		min = (*head_from)->value;
		def	= 2147483647;
		*target = NULL;
		while (1)
		{
			if (now->value > max)
				max = now->value;
			if (now->value < min)
			{
				min = now->value;
				min_node = now;
			}
			if (now->value > (*head_from)->value && now->value - (*head_from)->value < def)
			{
				def = now->value - (*head_from)->value;
				*target = now;
			}
			now = now->next;
			if (now == *head_to)
			{
				if (*target == NULL)
					*target = min_node;
				break;
			}
		}
	}
}

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

void	push_forward(t_box **head_a, t_box **head_b)
{
	t_box	*last_box;
	t_box	*target;
	int		prevcost;
	int		nextcost;

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
			find_target_b(head_a, head_b, &target);
			calc_cost(head_b, target, &prevcost, &nextcost);
			while (target != *head_b)
			{
				if (prevcost < nextcost)
					rb(head_b);
				else
					rrb(head_b);
			}
			pa(head_a, head_b);
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
		find_target_a(head_b, head_a, &target);
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