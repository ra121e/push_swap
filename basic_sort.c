/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:35:02 by athonda           #+#    #+#             */
/*   Updated: 2024/07/20 10:49:44 by athonda          ###   ########.fr       */
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
	return ;
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
	t_box	*min;
	t_box	*max;

	min = ft_lstmin(head);
	max = ft_lstmax(head);
	if (*head == min && ((*head)->next) == max)
	{
		sa(head);
		ra(head);
	}
	else if (*head == max)
	{
		if ((*head)->next == min)
			ra(head);
		else
		{
			sa(head);
			rra(head);
		}
	}
	else if (*head != min && (*head)->next == min)
		sa(head);
	else if (*head != min && (*head)->prev == min)
		rra(head);
}
