/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:34:03 by athonda           #+#    #+#             */
/*   Updated: 2024/08/05 11:19:43 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	preprocess(t_box **head_a, t_box **head_b)
{
	int		nbr;
	int		quatile[(DIVF * DIVB) + 1];
	int		i;
	int		*sample;

	nbr = ft_lstsize(head_a);
	sample = (int *)malloc(sizeof (int) * (SAMPLESIZE + 1));
	if (sample == NULL)
		return ;
	sample = sort_sample(head_a, nbr, sample);
	i = 1;
	while (i < (DIVF * DIVB))
	{
		quatile[i] = sample[SAMPLESIZE * i / (DIVF * DIVB)];
		i++;
	}
	quatile[0] = ft_lstminvalue(head_a);
	quatile[i] = ft_lstmaxvalue(head_a);
	free (sample);
	divide_conquer(head_a, head_b, quatile);
}
