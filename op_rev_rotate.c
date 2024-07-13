/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:33:13 by athonda           #+#    #+#             */
/*   Updated: 2024/07/13 12:54:57 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_box **head_a)
{
	t_box	*box1;
	t_box	*last_box;

	write(1, "rra\n", 4);
	box1 = *head_a;
	if (box1 == NULL || box1->next == NULL)
		return;
	last_box = box1->prev;
	*head_a = last_box;
}

void	rrb(t_box **head_b)
{
	t_box	*box1;
	t_box	*last_box;

	write(1, "rrb\n", 4);
	box1 = *head_b;
	if (box1 == NULL || box1->next == NULL)
		return;
	last_box = box1->prev;
	*head_b = last_box;
}

void	rrr(t_box **head_a, t_box **head_b)
{
	rra(head_a);
	rrb(head_b);
}