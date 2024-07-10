/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:33:13 by athonda           #+#    #+#             */
/*   Updated: 2024/07/10 22:17:53 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_box **head_a)
{
	t_box	*box1;
	t_box	*last_box;

	box1 = *head_a;
	last_box = box1->prev;
	*head_a = last_box;
}

void	rrb(void)
{

}

void	rrr(void)
{

}