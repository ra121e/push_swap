/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:30:48 by athonda           #+#    #+#             */
/*   Updated: 2024/07/12 18:04:56 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_box **head_a)
{
	t_box	*box1;
	t_box	*box2;
	t_box	*box3;
	t_box	*last_box;

	write(1, "sa\n", 3);
	box1 = *head_a;
	if (box1 == NULL || box1->next == NULL)
		return;
	box2 = box1->next;
	if (box2->next == box1)
	{
		*head_a = box2;
		return;
	}
	box3 = box2->next;
	last_box = box1->prev;
	box1->next = box3;
	box2->next = box1;
	last_box->next = box2;
	*head_a = box2;
	box1->prev = box2;
	box2->prev = last_box;
	box3->prev = box1;
}

void	sb(t_box **head_b)
{
	t_box	*box1;
	t_box	*box2;
	t_box	*box3;
	t_box	*last_box;

	write(1, "sb\n", 3);
	box1 = *head_b;
	if (box1 == NULL || box1->next == NULL)
		return;
	box2 = box1->next;
	if (box2->next == box1)
	{
		*head_b = box2;
		return;
	}
	box3 = box2->next;
	last_box = box1->prev;
	box1->next = box3;
	box2->next = box1;
	last_box->next = box2;
	*head_b = box2;
	box1->prev = box2;
	box2->prev = last_box;
	box3->prev = box1;
}

void	ss(t_box **head_a, t_box **head_b)
{
	sa(head_a);
	sb(head_b);
}