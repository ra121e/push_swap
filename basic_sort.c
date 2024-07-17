/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:35:02 by athonda           #+#    #+#             */
/*   Updated: 2024/07/17 21:14:58 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file basic_sort.c
 * @brief common sort functions
 * @note maybe bubble should be added in the future?
 */

#include "push_swap.h"

/**
 * @fn void	two_case(t_box **head_a)
 * @brief 2 node in stack a
 * @param[in] head_a is stack a link list
 */

void	two_case(t_box **head)
{
	t_box	*box1;
	t_box	*box2;

	box1 = *head;
	box2 = box1->next;
	if (box2->value < box1->value)
	{
		sa(head);
	}
	return;
}

/**
 * @fn void	three_case(t_box **head_a)
 * @brief sort 3 numbers
 * @param[in] head address of linked list
 * @return no
 * @note readable or norm -> I found the way takes both!!
 */

void	three_case(t_box **head)
{
	t_box	*box1;
	t_box	*box2;
	t_box	*last_box;

	box1 = *head;
	box2 = box1->next;
	last_box = box1->prev;
	two_case(head);
	box1 = *head;
	box2 = box1->next;
	last_box = box1->prev;
	if (box1->value > last_box->value)
		rra(head);
	if (box2->value > last_box->value)
		{
			ra(head);
			sa(head);
			rra(head);
		}
}
