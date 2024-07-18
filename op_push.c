/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:26:05 by athonda           #+#    #+#             */
/*   Updated: 2024/07/18 22:13:17 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_box **head_a, t_box **head_b)
{
	t_box	*box1;

	write(1, "pb\n", 3);
	if (*head_a == NULL)
		return;
	box1 = ft_lstcut_front(head_a);
	if (box1 == NULL)
		return;
	ft_lstadd_front(head_b, box1);
}

void	pa(t_box **head_b, t_box **head_a)
{
	t_box	*box1;

	write(1, "pa\n", 3);
	if (*head_b == NULL)
		return;
	box1 = ft_lstcut_front(head_b);
	if (box1 == NULL)
		return;
	ft_lstadd_front(head_a, box1);
}
