/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:35:02 by athonda           #+#    #+#             */
/*   Updated: 2024/07/16 09:45:52 by athonda          ###   ########.fr       */
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
 * @sa two_case
 * @note readable or norm -> I found the way takes both!!
 */

void	three_case(t_box **head_a)
{
	t_box	*box1;
	t_box	*box2;
	t_box	*last_box;

	box1 = *head_a;
	box2 = box1->next;
	last_box = box1->prev;
	two_case(head_a);
	if (box1->value > last_box->value)
		rra(head_a);
	if (box2->value > last_box->value)
		{
			ra(head_a);
			sa(head_a);
			rra(head_a);
		}
}