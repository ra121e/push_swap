/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 15:01:50 by athonda           #+#    #+#             */
/*   Updated: 2024/07/29 20:54:52 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_cut_back(t_box **head_a, t_box **head_b)
{
	int		max;
	int		nbr;
	int		i;
	int		j;
	int		k;
	t_box	*now;

	i = 0;
	max = (*head_a)->value;
	now = *head_a;
	while (1)
	{
		i++;
		if (now->value > max)
			max = now->value;
		now = now->next;
		if (now == *head_a)
			break;
	}
	nbr = i;
	j = nbr * 2 / 3 + 1;
	while (i > 0)
	{
		if ((*head_a)->value < (max / 3))
			pb(head_a, head_b);
		else
			ra(head_a);
		i--;
	}
	while (j > 1)
	{
		if ((*head_a)->value < (max * 2 / 3 ))
			pb(head_a, head_b);
		else
			ra(head_a);
		j--;
	}
	while ((*head_a) != NULL)
	{
		pb(head_a, head_b);
	}
	i = (nbr / 3) + 1;
	j = (nbr / 3) + 1;
	k = (nbr / 9) + 1;
	while (i > 0)
	{
		if ((*head_b)->value > (max * 8 / 9))
			pa(head_b, head_a);
		else
			rb(head_b);
		i--;
	}
	while (j > 0)
	{
		if ((*head_b)->value > (max * 7 / 9 ))
			pa(head_b, head_a);
		else
			rrb(head_b);
		j--;
	}
	while (k > 0)
	{
		pa(head_b, head_a);
		k--;
	}
	i = nbr / 3;
	j = nbr / 3;
	k = nbr / 9;
	while (i > 0)
	{
		if ((*head_b)->value > (max * 5 / 9))
			pa(head_b, head_a);
		else
			rb(head_b);
		i--;
	}
	while (j > 0)
	{
		if ((*head_b)->value > (max * 4 / 9 ))
			pa(head_b, head_a);
		else
			rrb(head_b);
		j--;
	}
	while (k > 0)
	{
		pa(head_b, head_a);
		k--;
	}
	i = nbr / 3;
	j = nbr / 3;
	k = nbr / 9;
	while (i > 0)
	{
		if ((*head_b)->value > (max * 2 / 9))
			pa(head_b, head_a);
		else
			rb(head_b);
		i--;
	}
	while (j > 0)
	{
		if ((*head_b)->value > (max * 1 / 9 ))
			pa(head_b, head_a);
		else
			rb(head_b);
		j--;
	}
	while ((*head_b) != NULL)
	{
		pa(head_b, head_a);
	}
}