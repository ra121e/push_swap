/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:30:48 by athonda           #+#    #+#             */
/*   Updated: 2024/07/10 20:07:32 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_box **head_a)
{
	t_box	*first_box;
	t_box	*second_box;

	first_box = *head_a;
	second_box = first_box->next;
	first_box->next = second_box->next;
	second_box->next = first_box;
	*head_a = second_box;
}

void	sb(void)
{

}

void	ss(void)
{

}