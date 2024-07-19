/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 23:54:07 by athonda           #+#    #+#             */
/*   Updated: 2024/07/18 23:54:12 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
