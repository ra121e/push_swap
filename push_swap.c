/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:38:00 by athonda           #+#    #+#             */
/*   Updated: 2024/07/08 18:51:11 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file push_swap.c
 * @brief sort numbers from command line argument
 */

#include "push_swap.h"

/**
 * @fn int	main(int argc, char *argv[])
 * @brief preprocessing the numbers from argument to store in linked list
 * @param[in] argc number of argument should be 2
 * @param[in] argv string of numbers separeted by space
 */

int	main(int argc, char *argv[])
{
	char	**nbrs;

	if (argc == 1)
		return (0);
	if (argc == 2 || argv[1][0] != '\0')
	{
		nbrs = ft_split(argv[1]);
	}

	return (0);
}