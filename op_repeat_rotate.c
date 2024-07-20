/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_repeat_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:51:51 by athonda           #+#    #+#             */
/*   Updated: 2024/07/20 13:24:25 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	repeat_ra(t_box **head, int count)
{
	int	i;

	i = 1;
	while (i <= count)
	{
		ra(head);
		i++;
	}
}

void	repeat_rb(t_box **head, int count)
{
	int	i;

	i = 1;
	while (i <= count)
	{
		rb(head);
		i++;
	}
}

void	repeat_rr(t_box **head_a, t_box **head_b, int count)
{
	int	i;

	i = 1;
	while (i <= count)
	{
		rr(head_a, head_b);
		i++;
	}
}
