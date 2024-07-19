/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 09:29:35 by athonda           #+#    #+#             */
/*   Updated: 2024/07/19 13:33:02 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **str)
{
	int	i;

	if (str == NULL)
		return ;
	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_array_l(long *nbrs)
{
	if (nbrs == NULL)
		return ;
	free(nbrs);
}

void	free_array_i(int *nbrs)
{
	if (nbrs == NULL)
		return ;
	free(nbrs);
}

void	free_lst(t_box **head)
{
	t_box	*tmp;

	if (*head == NULL)
		return ;
	((*head)->prev)->next = NULL;
	while (*head != NULL)
	{
		tmp = (*head)->next;
		(*head)->value = 0;
		free(*head);
		*head = tmp;
	}
}