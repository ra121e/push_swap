/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 22:22:01 by athonda           #+#    #+#             */
/*   Updated: 2024/08/07 15:43:33 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file turk_algo_utils.c
 * @brief functions to complete basically turk sort
 */

#include "push_swap.h"

/**
 * @fn t_box *find_target_largest_smaller
 * @brief to find the place in stack_b to insert the node in stack_a
 * @param[in] node address of the node to be inserted
 * @param[in] head_to the address of the pointer to the top node of insert
 * @param[out] target address of the node on which the node to be insert
 * @attention calculting int numbers should be cast in long long type
 * @note in push_forward process, pile the number like reverse pyramid
 */

t_box	*find_target_largest_smaller(t_box *node, t_box **head_to)
{
	t_box		*now;
	long long	def;
	t_box		*node_max;
	t_box		*target;

	now = *head_to;
	def = LLONG_MAX;
	target = NULL;
	node_max = ft_lstmax(head_to);
	while (1)
	{
		if (now->value < node->value && ((long long)node->value - \
			(long long)now->value) < def)
		{
			def = (long long)node->value - (long long)now->value;
			target = now;
		}
		now = now->next;
		if (now == *head_to)
		{
			if (target == NULL)
				target = node_max;
			return (target);
		}
	}
}

/**
 * @fn t_box *find_target_smallest_larger
 * @brief to find the place in stack_a to insert the node in stack_b
 * @param[in] node address of the node to be inserted
 * @param[in] head_to the address of the pointer to the top node of insert
 * @retval target address of the node on which the node to be insert
 * @attention calculting int numbers should be cast in long long type
 * @note in push_back process, pile the number like pyramid.
 */

t_box	*find_target_smallest_larger(t_box *node, t_box **head_to)
{
	t_box		*now;
	long long	def;
	t_box		*node_min;
	t_box		*target;

	now = *head_to;
	def = LLONG_MAX;
	target = NULL;
	node_min = ft_lstmin(head_to);
	while (1)
	{
		if (now->value > node->value && (long long)now->value - \
			(long long)node->value < def)
		{
			def = (long long)now->value - (long long)node->value;
			target = now;
		}
		now = now->next;
		if (now == *head_to)
		{
			if (target == NULL)
				target = node_min;
			return (target);
		}
	}
}

/**
 * @fn void push_forward
 * @brief move numbers from stack_a to stack_b
 * @param[in] head_a linked list of numbers
 * @param[in] head_b empty
 * @note
	- to find base node which is in stack_a and lowest cost to move
	- to find target of the base
	- to revolve the stacks to make the target and base be at top
 */

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
			pb(head_a, head_b);
			if ((*head_b)->next != NULL && \
				(*head_b)->value < ((*head_b)->next)->value)
				sb(head_b);
		}
		else
		{
			target = NULL;
			base = find_base(head_a, head_b);
			target = find_target_largest_smaller(base, head_b);
			revolver(head_a, head_b, base, target);
			pb(head_a, head_b);
			last_box = (*head_a)->prev;
		}
	}
}

/**
 * @fn void push_back
 * @brief move numbers from stack_b to stack_a
 * @param[in] head_a 3 numbers are left
 * @param[in] head_b most numbers are sorted
 * @note
	- to find target of the top node
	- to revolve the stack_a to make the target node comes to top
 */

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
				ra(head_a);
			else
				rra(head_a);
		}
		pa(head_b, head_a);
	}
}

/**
 * @fn void last_rotation
 * @brief to rotate stack_a to order numbers from smallest to largest
 * @param[in] head address of the pointer to top node in stack_a
 */

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
