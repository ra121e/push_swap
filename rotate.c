/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:31:52 by athonda           #+#    #+#             */
/*   Updated: 2024/07/12 17:18:06 by athonda          ###   ########.fr       */
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

void	rb(void)
{

}

void	rr(void)
{

}