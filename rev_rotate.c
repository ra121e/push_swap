/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:33:13 by athonda           #+#    #+#             */
/*   Updated: 2024/07/12 17:19:36 by athonda          ###   ########.fr       */
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

void	rrb(void)
{

}

void	rrr(void)
{

}