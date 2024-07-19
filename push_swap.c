/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:38:00 by athonda           #+#    #+#             */
/*   Updated: 2024/07/19 12:19:23 by athonda          ###   ########.fr       */
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
	t_box	*head_a;
	t_box	*head_b;

	head_a = NULL;
	head_b = NULL;
	if (argc == 1)
		return (0);
	if (argc == 2 && argv[1][0] != '\0')
		argv = ft_split(argv[1], ' ');
	else if (argc > 2)
		argv++;
	if (check_arg(argv, argc))
		return (0);
	head_a = make_list(head_a, argv);
	if (argc == 2)
		free_split(argv);
	turk_algo(&head_a, &head_b);
	write_stack(head_a, head_b);
	return (0);
}
