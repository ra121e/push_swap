/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:34:03 by athonda           #+#    #+#             */
/*   Updated: 2024/08/07 16:25:40 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file preprocess.c
 * @brief select quantile to devide numbers
 */

#include "push_swap.h"

/**
 * @fn int	*sort_sample
 * @brief sampling numbers and insertion sort in array
 * @param[in] head_a population of the number data
 * @param[in] nbr number of data
 * @param[in, out] sample array of the sorted sample numbers
 * @return sample array
 */

int	*sort_sample(t_box **head_a, int nbr, int *sample)
{
	int		i;
	int		j;
	t_box	*now;

	now = *head_a;
	i = 0;
	while (1)
	{
		if (i % (nbr / SAMPLESIZE) == 0)
		{
			j = (i / (nbr / SAMPLESIZE)) - 1;
			while (j >= 0 && now->value < sample[j])
			{
				sample[j + 1] = sample[j];
				j--;
			}
			sample[j + 1] = now->value;
		}
		now = now->next;
		i++;
		if (now == *head_a)
			return (sample);
	}
}

/**
 * @fn void preprocess
 * @brief main process of preprocess
 * @param[in] head_a
 * @param[in] head_b
 * @note
	- get the total number of nodes
	- prepare the array of storage
	- sampling and insert sort the numbers into the array
	- select quantile
	- divide and conquer
 */

void	preprocess(t_box **head_a, t_box **head_b)
{
	int			nbr;
	long long	quantile[(DIVF * DIVB) + 1];
	int			i;
	int			*sample;

	nbr = ft_lstsize(head_a);
	sample = (int *)malloc(sizeof (int) * (SAMPLESIZE + 1));
	if (sample == NULL)
		return ;
	sample = sort_sample(head_a, nbr, sample);
	i = 1;
	while (i < (DIVF * DIVB))
	{
		quantile[i] = sample[SAMPLESIZE * i / (DIVF * DIVB)];
		i++;
	}
	quantile[0] = ft_lstminvalue(head_a);
	quantile[i] = ft_lstmaxvalue(head_a);
	free (sample);
	divide_conquer(head_a, head_b, quantile);
}
