/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 15:01:50 by athonda           #+#    #+#             */
/*   Updated: 2024/07/31 15:24:19 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	divide_a_r(t_box **head_a, t_box **head_b, int nbr, int quantile)
{
	int	i;
	int	nbr_push;

	i = 0;
	nbr_push = 0;
	while (i < nbr)
	{
		if ((*head_a)->value <= quantile)
		{
			pb(head_a, head_b);
			nbr_push++;
		}
		else
			ra(head_a);
		i++;
	}
	return (nbr_push);
}

int	divide_b_r(t_box **head_a, t_box **head_b, int nbr, int quantile)
{
	int	i;
	int	nbr_push;

	i = 0;
	nbr_push = 0;
	while (i < nbr)
	{
		if ((*head_b)->value > quantile)
		{
			pa(head_b, head_a);
			nbr_push++;
		}
		else
			rb(head_b);
		i++;
	}
	return (nbr_push);
}

int	divide_b_rr(t_box **head_a, t_box **head_b, int nbr, int quantile)
{
	int	i;
	int	nbr_push;

	i = 0;
	nbr_push = 0;
	while (i < nbr)
	{
		if ((*head_b)->value > quantile)
		{
			pa(head_b, head_a);
			rrb(head_b);
			nbr_push++;
		}
		else
			rrb(head_b);
		i++;
	}
	return (nbr_push);
}

void	divide_forward(t_box **head_a, t_box **head_b, int min, int max)
{
	int		nb_f[DIVF];
	int		nbr;
	int		i;

	nbr = ft_lstsize(head_a);
	i = 0;
	while (i < DIVF - 1)
	{
		nb_f[i] = divide_a_r(head_a, head_b, nbr, min + (max - min) * (i + 1) / DIVF);
		nbr = nbr - nb_f[i];
		i++;
	}
	i = i - 1;
	while (i >= 0)
	{
		divide_back(head_a, head_b, nb_f[i], min + (max - min) * ((DIVF * i) + 2) / (DIVF * DIVF));
		i--;
	}
}

void	divide_back(t_box **head_a, t_box **head_b, int nbr, int q)
{
	int		nb[2];
	int		max;
	int		min;
	t_box	*now;

	now = *head_b;
	min = now->value;
	max = now->value;
	while (1)
	{
		if (now->value > max)
			max = now->value;
		if (now->value < min)
			min = now->value;
		now = now->next;
		if (now == *head_b && *head_a != NULL)
			now = (*head_a)->next;
		else if (now == *head_b)
			break ;
		if (now == *head_a)
			break ;
	}
	nb[0] = divide_b_r(head_a, head_b, nbr, q);
	nb[1] = divide_b_rr(head_a, head_b, nbr - nb[0], q - (max - min) / 9);
	divide_b_r(head_a, head_b, nbr - nb[0] - nb[1], q - (max - min) * 2 / 9);
}
