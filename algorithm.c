/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 20:52:11 by athonda           #+#    #+#             */
/*   Updated: 2024/07/13 15:51:26 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


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
		if (box2->value < last_box->value)
			return;
		else
		{
			sa(head_a);
			ra(head_a);
			return;
		}
	}
	else if(box1->value > box2->value && box1->value > last_box->value)
	{
		if (box2->value < last_box->value)
		{
			ra(head_a);
			return;
		}
		else
		{
			sa(head_a);
			rra(head_a);
			return;
		}
	}
	else
	{
		if (box2->value < last_box->value)
		{
			sa(head_a);
			return;
		}
		else
		{
			rra(head_a);
			return;
		}
	}
}

void	find_target_b(t_box **head_from, t_box **head_to, int *max, int *min, t_box **target)
{
	t_box	*now;
	int		def;

	if (*head_to == NULL || (*head_to)->next == NULL)
		pa(head_from, head_to);
	else
	{
		now = *head_to;
		*max = (*head_from)->value;
		*min = (*head_from)->value;
		def	= 2147483647;
		while (1)
		{
			if (now->value > *max)
				*max = now->value;
			if (now->value < *min)
				*min = now->value;
			if (now->value < (*head_from)->value && ((*head_from)->value - now->value) < def)
			{
				def = (*head_from)->value - now->value;
				*target = now;
			}
			now = now->next;
			if (now == *head_to)
				break;
		}
	}
}

void	find_target_a(t_box **head_from, t_box **head_to, int *max, int *min, t_box **target)
{
	t_box	*now;
	int		def;

	if (*head_to == NULL || (*head_to)->next == NULL)
		pa(head_from, head_to);
	else
	{
		now = *head_to;
		*max = (*head_from)->value;
		*min = (*head_from)->value;
		def	= 2147483647;
		*target = NULL;
		while (1)
		{
			if (now->value > *max)
				*max = now->value;
			if (now->value < *min)
				*min = now->value;
			if (now->value > (*head_from)->value && now->value - (*head_from)->value < def)
			{
				def = now->value - (*head_from)->value;
				*target = now;
			}
			now = now->next;
			if (now == *head_to)
				break;
		}
	}
}
void	turk_algo(t_box **head_a, t_box **head_b)
{
	t_box	*box1;
	t_box	*box2;
	t_box	*last_box;
	t_box	*target;
	int		max;
	int		min;

	box1 = *head_a;
	box2 = box1->next;
	last_box = box1->prev;

	if (*head_a == NULL || box2 == NULL)
		return;
	if (box2->next == box1)
	{
		if (box2->value < box1->value)
		{
			sa(head_a);
			write_stack(*head_a, *head_b);
			return;
		}
		return;
	}
	if (box2->next == last_box)
	{
		three_case(head_a);
		write_stack(*head_a, *head_b);
		return;
	}
	while ((last_box->prev)->prev != *head_a)
	{
		if (*head_b == NULL || (*head_b)->next == NULL)
		{
			pa(head_a, head_b);
			write_stack(*head_a, *head_b);
			if ((*head_b)->next != NULL && (*head_b)->value < ((*head_b)->next)->value)
			{
				sb(head_b);
				write_stack(*head_a, *head_b);
			}
		}
		else
		{
			find_target_b(head_a, head_b, &max, &min, &target);
			if ((*head_a)->value == max || (*head_a)->value == min)
			{
				pa(head_a, head_b);
				write_stack(*head_a, *head_b);
				if ((*head_b)->value == min)
				{
					rb(head_b);
					write_stack(*head_a, *head_b);
				}
			}
			else
			{
				while (target != *head_b)
				{
					rb(head_b);
					write_stack(*head_a, *head_b);
				}
				pa(head_a, head_b);
				write_stack(*head_a, *head_b);
				while ((*head_b)->value != max)
				{
					rrb(head_b);
					write_stack(*head_a, *head_b);
				}
			}
		}
	}
	three_case(head_a);
	write_stack(*head_a, *head_b);
	while (*head_b != NULL)
	{
		find_target_a(head_b, head_a, &max, &min, &target);
		if ((*head_b)->value == max || (*head_b)->value == min)
		{
			pb(head_b, head_a);
			write_stack(*head_a, *head_b);
			if ((*head_a)->value == max)
			{
				ra(head_a);
				write_stack(*head_a, *head_b);
			}
		}
		else
		{
			while (target != *head_a)
			{
				ra(head_a);
				write_stack(*head_a, *head_b);
			}
			pb(head_b, head_a);
			write_stack(*head_a, *head_b);
			while ((*head_a)->value != min)
			{
				rra(head_a);
				write_stack(*head_a, *head_b);
			}
		}
	}
}