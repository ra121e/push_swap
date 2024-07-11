/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:38:00 by athonda           #+#    #+#             */
/*   Updated: 2024/07/11 22:36:35 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file push_swap.c
 * @brief sort numbers from command line argument
 */

#include "push_swap.h"
#include <stdio.h>

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
	t_box	*now;
	int		i;

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
		sa(&head_a);
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
		ra(&head_a);
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
		sa(&head_a);
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
		rra(&head_a);
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
		pa(&head_a, &head_b);
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

	return (0);
}
