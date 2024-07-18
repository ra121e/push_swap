/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:10:32 by athonda           #+#    #+#             */
/*   Updated: 2024/07/18 10:59:38 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	check_digit(char **str, int *count)
{
	int		i;
	int		j;

	i = 0;
	while (str[i] != NULL)
	{
		j = 0;
		if (str[i][j] == '+' || str[i][j] == '-')
			j++;
		while (str[i][j] != '\0' && ft_isdigit(str[i][j]))
			j++;
		if (str[i][j] != '\0')
		{
			return(1);
		}
		i++;
	}
	*count = i;
	return (0);
}


int	check_dup(int *nbrs)
{
	int	i;
	int	j;

	i = 0;
	while (nbrs[i])
	{
		j = i + 1;
		while (nbrs[j])
		{
			if (nbrs[i] == nbrs[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_sort(int	*nbrs)
{
	int	i;

	i = 0;
	while (nbrs[i + 1])
	{
		if (nbrs[i] >= nbrs[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	check_arg(char **str)
{
	int	*tmp;
	int	count;
	int	i;

	count = 0;
	if (check_digit(str, &count))
	{
		write (2, "Error\n", 6);
		return (1);
	}
	tmp = (int *)malloc(sizeof(int) * count);
	if (tmp == NULL)
		return (1);
	i = 0;
	while (i < count)
	{
		tmp[i] = ft_atoi(str[i]);
		i++;
	}
	if (check_dup(tmp))
	{
		free (tmp);
		write (2, "Error\n", 6);
		return (1);
	}
	if (check_sort(tmp))
		return (1);
	return (0);
}