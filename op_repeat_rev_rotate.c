/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_repeat_rev_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 18:01:08 by athonda           #+#    #+#             */
/*   Updated: 2024/07/19 18:05:05 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	repeat_rra(t_box **head, int count)
{
	int	i;

	i = 1;
	while (i <= count)
	{
		rra(head);
		i++;
	}
}

void	repeat_rrb(t_box **head, int count)
{
	int	i;

	i = 1;
	while (i <= count)
	{
		rrb(head);
		i++;
	}
}

void	repeat_rrr(t_box **head_a, t_box **head_b, int count)
{
	int	i;

	i = 1;
	while (i <= count)
	{
		rrr(head_a, head_b);
		i++;
	}
}
