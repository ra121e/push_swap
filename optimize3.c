/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 15:01:50 by athonda           #+#    #+#             */
/*   Updated: 2024/08/05 22:03:47 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	divide_a_r(t_box **head_a, t_box **head_b, int nbr, long long quantile)
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

int	divide_b_r(t_box **head_a, t_box **head_b, int nbr, long long *quantile)
{
	int			i;
	int			nbr_push;
	long long	median_q;

	median_q = (*quantile + *(quantile + 1)) / 2;
	i = 0;
	nbr_push = 0;
	while (i < nbr)
	{
		if ((*head_b)->value > *quantile)
		{
			pa(head_b, head_a);
			if ((*head_a)->value > median_q)
				ra(head_a);
			nbr_push++;
		}
		else
			rb(head_b);
		i++;
	}
	return (nbr_push);
}

int	divide_b_rr(t_box **head_a, t_box **head_b, int nbr, long long *quantile)
{
	int			i;
	int			nbr_push;
	long long	median_q;

	median_q = (*quantile + *(quantile + 1)) / 2;
	i = 0;
	nbr_push = 0;
	while (i < nbr)
	{
		if ((*head_b)->value > *quantile)
		{
			pa(head_b, head_a);
			if ((*head_a)->value > median_q)
				ra(head_a);
			rrb(head_b);
			nbr_push++;
		}
		else
			rrb(head_b);
		i++;
	}
	return (nbr_push);
}

void	divide_conquer(t_box **head_a, t_box **head_b, long long *quatile)
{
	int		nb_f[DIVF];
	int		nbr;
	int		i;

	nbr = ft_lstsize(head_a);
	i = 0;
	while (i < (DIVF - BLOCK_NUM_NO_MOVE))
	{
		nb_f[i] = divide_a_r(head_a, head_b, nbr, quatile[(i + 1) * DIVB]);
		nbr = nbr - nb_f[i];
		i++;
	}
	i = i - 1;
	while (i >= 0)
	{
		divide_back(head_a, head_b, nb_f[i], &quatile[((i + 1) * (DIVB)) - 1]);
		i--;
	}
}

void	divide_back(t_box **head_a, t_box **head_b, int nbr, long long *quatile)
{
	int		nb[DIVB];
	int		j;

	j = 0;
	while (j < DIVB)
	{
		if (j % 2 == 0)
		{
			nb[j] = divide_b_r(head_a, head_b, nbr, quatile);
		}
		else if (j % 2 == 1)
		{
			nb[j] = divide_b_rr(head_a, head_b, nbr, quatile);
		}
		nbr = nbr - nb[j];
		j++;
		quatile--;
	}
}
