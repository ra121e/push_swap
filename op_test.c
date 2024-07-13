/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 00:23:42 by athonda           #+#    #+#             */
/*   Updated: 2024/07/13 00:25:57 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_test(t_box **head_a, t_box **head_b)
{
	sa(&head_a);
	write_stack(head_a, head_b);
	ra(&head_a);
	write_stack(head_a, head_b);
	sa(&head_a);
	write_stack(head_a, head_b);
	rra(&head_a);
	write_stack(head_a, head_b);
	pa(&head_a, &head_b);
	write_stack(head_a, head_b);
	pa(&head_a, &head_b);
	write_stack(head_a, head_b);
	pa(&head_a, &head_b);
	write_stack(head_a, head_b);
	pa(&head_a, &head_b);
	write_stack(head_a, head_b);
	rra(&head_a);
	write_stack(head_a, head_b);
	rb(&head_b);
	write_stack(head_a, head_b);
	sb(&head_b);
	write_stack(head_a, head_b);
	pb(&head_b, &head_a);
	write_stack(head_a, head_b);
	rrb(&head_b);
	write_stack(head_a, head_b);
}