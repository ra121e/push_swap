/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:38:00 by athonda           #+#    #+#             */
/*   Updated: 2024/07/12 16:36:28 by athonda          ###   ########.fr       */
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
	printf("stack a\n");
	if (now != NULL)
	{
		i = 1;
		while (1)
		{
			printf("%d: %d @%p next->%p prev->%p\n", i, now->value, now, now->next, now->prev);
			now = now->next;
			i++;
			if (now == head_a)
				break;
		}
	}
	printf("\n");
	now = head_b;
	printf("stack b\n");
	if (now != NULL)
	{
		i = 1;
		while (1)
		{
			printf("%d: %d @%p next->%p prev->%p\n", i, now->value, now, now->next, now->prev);
			now = now->next;
			i++;
			if (now == head_b || now == NULL)
				break;
		}
	}
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
		printf("%s\n", argv[1]);
		nbrs = ft_split(argv[1], ' ');
		printf("%p\n", nbrs);
		printf("%s\n", nbrs[0]);
		head_a = make_list(head_a, nbrs);
		printf("%p\n", head_a);
		write_stack(head_a, head_b);
		printf("\n");
		sa(&head_a);
		write_stack(head_a, head_b);
		printf("\n");
		ra(&head_a);
		write_stack(head_a, head_b);
		printf("\n");
		sa(&head_a);
		write_stack(head_a, head_b);
		printf("\n");
		rra(&head_a);
		write_stack(head_a, head_b);
		printf("\n");
		pa(&head_a, &head_b);
		write_stack(head_a, head_b);
		printf("\n");
		pa(&head_a, &head_b);
		write_stack(head_a, head_b);
		printf("\n");
		pa(&head_a, &head_b);
		write_stack(head_a, head_b);
		printf("\n");
		pa(&head_a, &head_b);
		write_stack(head_a, head_b);
		printf("\n");
		rra(&head_a);
		write_stack(head_a, head_b);
	}

	return (0);
}
