/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:31:52 by athonda           #+#    #+#             */
/*   Updated: 2024/07/12 17:54:22 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_box **head_a)
{
	t_box	*box1;
	t_box	*box2;

	write(1, "ra\n", 3);
	box1 = *head_a;
	if (box1 == NULL || box1->next == NULL)
		return;
	box2 = box1->next;
	*head_a = box2;
}

void	rb(t_box **head_b)
{
	t_box	*box1;
	t_box	*box2;

	write(1, "rb\n", 3);
	box1 = *head_b;
	if (box1 == NULL || box1->next == NULL)
		return;
	box2 = box1->next;
	*head_b = box2;
}

void	rr(t_box **head_a, t_box **head_b)
{
	ra(head_a);
	rb(head_b);
}