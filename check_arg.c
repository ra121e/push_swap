/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:10:32 by athonda           #+#    #+#             */
/*   Updated: 2024/07/19 13:58:40 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_digit(char **str, int *count, int argc)
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
			write (2, "Error\n", 6);
			if (argc == 2)
				free_split(str);
			return (1);
		}
		i++;
	}
	*count = i;
	return (0);
}

int	check_dup(long *nbrs, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count - 1)
	{
		j = i + 1;
		while (nbrs[j])
		{
			if (nbrs[i] == nbrs[j] || nbrs[i] > 2147483647)
			{
				write (2, "Error\n", 6);
				free_array_l(nbrs);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_sort(long	*nbrs, int count)
{
	int	i;

	i = 0;
	while (i < count - 1)
	{
		if (nbrs[i] >= nbrs[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	check_arg(char **str, int argc)
{
	long	*tmp;
	int		count;
	int		i;

	count = 0;
	if (check_digit(str, &count, argc))
		return (1);
	tmp = (long *)malloc(sizeof(long) * (count + 1));
	if (tmp == NULL)
		return (1);
	i = 0;
	while (i < count)
	{
		tmp[i] = ft_atol(str[i]);
		i++;
	}
	tmp[i] = 0;
	if (check_dup(tmp, count))
	{
		if (argc == 2)
			free_split(str);
		return (1);
	}
	if (check_sort(tmp, count))
	{
		free_array_l(tmp);
		if (argc == 2)
			free_split(str);
		return (1);
	}
	free_array_l(tmp);
	return (0);
}
