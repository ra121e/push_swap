/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:31:52 by athonda           #+#    #+#             */
/*   Updated: 2024/07/10 22:08:32 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_box **head_a)
{
	t_box	*box1;
	t_box	*box2;

	box1 = *head_a;
	box2 = box1->next;
	*head_a = box2;
}

void	rb(void)
{

}

void	rr(void)
{

}