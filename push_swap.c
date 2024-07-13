/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:38:00 by athonda           #+#    #+#             */
/*   Updated: 2024/07/13 00:45:38 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file push_swap.c
 * @brief sort numbers from command line argument
 */

#include "push_swap.h"
#include <stdio.h>

void	write_stack(t_box *head_a, t_box *head_b)
{
	t_box	*now;
	int		i;

	now = head_a;
	printf("stack a: %p\n", head_a);
	if (now != NULL)
	{
		i = 1;
		while (1)
		{
			printf("%d: %d %p next->%p prev->%p\n", i, now->value, now, now->next, now->prev);
			now = now->next;
			i++;
			if (now == head_a || now == NULL)
				break;
		}
	}
	printf("\n");
	now = head_b;
	printf("stack b: %p\n", head_b);
	if (now != NULL)
	{
		i = 1;
		while (1)
		{
			printf("%d: %d %p next->%p prev->%p\n", i, now->value, now, now->next, now->prev);
			now = now->next;
			i++;
			if (now == head_b || now == NULL)
				break;
		}
	}
	printf("\n");
}

/**
 * @fn int	main(int argc, char *argv[])
 * @brief preprocessing the numbers from argument to store in linked list
 * @param[in] argc number of argument should be 2
 * @param[in] argv string of numbers separeted by space
 */

int	main(int argc, char *argv[])
{
	char	**nbrs;
	t_box	*head_a;
	t_box	*head_b;

	nbrs = NULL;
	head_a = NULL;
	head_b = NULL;
	if (argc == 1)
		return (0);
	if (argc == 2 && argv[1][0] != '\0')
	{
		printf("arv[1]: %s\n", argv[1]);
		nbrs = ft_split(argv[1], ' ');
		printf("array nbrs after ft_split: %p\n", nbrs);
		printf("first array: %s\n", nbrs[0]);
		head_a = make_list(head_a, nbrs);
		printf("address of link list from array: %p\n\n", head_a);
		write_stack(head_a, head_b);
		turk_algo(&head_a, &head_b);
		write_stack(head_a, head_b);
	}

	return (0);
}
