/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 15:01:50 by athonda           #+#    #+#             */
/*   Updated: 2024/08/07 16:52:41 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file optimize3.c
 * @brief divide data with quantile
 */

#include "push_swap.h"

/**
 * @fn int	divide_a_r
 * @brief divide numbers with quatile in stack_a and push them to stack_b
 * @param[in] head_a
 * @param[in] head_b
 * @param[in] nbr number of data
 * @param[in] q quantile
 * @return nbr_push to subtract this number from the total number
 */

int	divide_a_r(t_box **head_a, t_box **head_b, int nbr, long long q)
{
	int	i;
	int	nbr_push;

	i = 0;
	nbr_push = 0;
	while (i < nbr)
	{
		if ((*head_a)->value <= q)
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

/**
 * @fn int	divide_b_r
 * @brief divide numbers with quatile in stack_b and push them to stack_a
 * @param[in] head_a
 * @param[in] head_b
 * @param[in] nbr number of data
 * @param[in] q quantile
 * @return nbr_push to subtract this number from the total number
 * @note r is for check the data located at top of stack_b
 */

int	divide_b_r(t_box **head_a, t_box **head_b, int nbr, long long *q)
{
	int			i;
	int			nbr_push;
	long long	median_q;

	median_q = (*q + *(q + 1)) / 2;
	i = 0;
	nbr_push = 0;
	while (i < nbr)
	{
		if ((*head_b)->value > *q)
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

/**
 * @fn int	divide_b_rr
 * @brief divide numbers with quatile in stack_b and push them to stack_a
 * @param[in] head_a
 * @param[in] head_b
 * @param[in] nbr number of data
 * @param[in] q quantile
 * @return nbr_push to subtract this number from the total number
 * @note rr is for check data located at bottom of stack_b
 */

int	divide_b_rr(t_box **head_a, t_box **head_b, int nbr, long long *q)
{
	int			i;
	int			nbr_push;
	long long	median_q;

	median_q = (*q + *(q + 1)) / 2;
	i = 0;
	nbr_push = 0;
	while (i < nbr)
	{
		if ((*head_b)->value > *q)
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

/**
 * @fn void	divide_conquer
 * @brief repeat dividing number with quantile forwarding and returning
 * @param[in] head_a
 * @param[in] head_b
 * @param[in] quantile address of the quantile
 */

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

/**
 * @fn void	divide_back
 * @brief check block and divid with quantile
 * @param[in] head_a
 * @param[in] head_b
 * @param[in] nbr number of data in block
 * @param[in] q address of quantile
 */

void	divide_back(t_box **head_a, t_box **head_b, int nbr, long long *q)
{
	int		nb[DIVB];
	int		j;

	j = 0;
	while (j < DIVB)
	{
		if (j % 2 == 0)
		{
			nb[j] = divide_b_r(head_a, head_b, nbr, q);
		}
		else if (j % 2 == 1)
		{
			nb[j] = divide_b_rr(head_a, head_b, nbr, q);
		}
		nbr = nbr - nb[j];
		j++;
		q--;
	}
}
