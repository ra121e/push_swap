/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 20:52:11 by athonda           #+#    #+#             */
/*   Updated: 2024/07/30 20:46:52 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	turk_algo(t_box **head_a, t_box **head_b)
{
	t_box	*box1;
	t_box	*box2;

	box1 = *head_a;
	box2 = box1->next;
	if (*head_a == NULL || box2 == NULL)
		return ;
	if (box2->next == box1)
	{
		two_case(head_a);
		free_lst(head_a);
		return ;
	}
	else if (box2->next == box1->prev)
	{
		three_case(head_a);
		free_lst(head_a);
		return ;
	}
	preprocess(head_a, head_b);
	push_forward(head_a, head_b);
	three_case(head_a);
	push_back(head_a, head_b);
	last_rotation(head_a);
	free_lst(head_a);
}
