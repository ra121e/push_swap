/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 20:52:11 by athonda           #+#    #+#             */
/*   Updated: 2024/07/19 19:24:16 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	turk_algo(t_box **head_a, t_box **head_b)
{
	t_box	*box1;
	t_box	*box2;
	t_box	*last_box;

	box1 = *head_a;
	box2 = box1->next;
	last_box = box1->prev;
	if (*head_a == NULL || box2 == NULL)
		return ;
	if (box2->next == box1)
	{
		two_case(head_a);
		return ;
	}
	else if (box2->next == last_box)
	{
		three_case(head_a);
		return ;
	}
	push_forward(head_a, head_b);
	three_case(head_a);
	push_back(head_a, head_b);
	last_rotation(head_a);
	write_stack(*head_a, *head_b);
	free_lst(head_a);
}
