/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:26:05 by athonda           #+#    #+#             */
/*   Updated: 2024/07/12 13:02:21 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_box **head_a, t_box **head_b)
{
	t_box	*box1;

	box1 = ft_lstcut_front(head_a);
	if (box1 == NULL)
		return;
	ft_lstadd_front(head_b, box1);
}

void	pb(void)
{

}
