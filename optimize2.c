/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 18:30:07 by athonda           #+#    #+#             */
/*   Updated: 2024/08/07 16:06:21 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file optimize2.c
 * @brief double rotation and double reverse rotation
 */

#include "push_swap.h"

/**
 * @fn void double_prev
 * @brief double rr to prev direction
 * @param[in] head_a
 * @param[in] head_b
 * @param[in] prev_a number of rotation in stack_a to prev direction
 * @param[in] prev_b number of rotation in stack_b to prev direction
 */

void	double_prev(t_box **head_a, t_box **head_b, int prev_a, int prev_b)
{
	if (prev_a > prev_b)
	{
		repeat_rr(head_a, head_b, prev_b);
		repeat_ra(head_a, prev_a - prev_b);
	}
	else
	{
		repeat_rr(head_a, head_b, prev_a);
		repeat_rb(head_b, prev_b - prev_a);
	}
}

/**
 * @fn void double_next
 * @brief double rrr to next direction
 * @param[in] head_a
 * @param[in] head_b
 * @param[in] next_a number of rotation in stack_a to next direction
 * @param[in] next_b number of rotation in stack_b to next direction
 */

void	double_next(t_box **head_a, t_box **head_b, int next_a, int next_b)
{
	if (next_a > next_b)
	{
		repeat_rrr(head_a, head_b, next_b);
		repeat_rra(head_a, next_a - next_b);
	}
	else
	{
		repeat_rrr(head_a, head_b, next_a);
		repeat_rrb(head_b, next_b - next_a);
	}
}

/**
 * @fn void preva_nextb
 * @brief no use rr and rrr
 * @param[in] head_a
 * @param[in] head_b
 * @param[in] prev_a number of rotation in stack_a to prev direction
 * @param[in] next_b number of rotation in stack_b to next direction
 */

void	preva_nextb(t_box **head_a, t_box **head_b, int prev_a, int next_b)
{
	repeat_ra(head_a, prev_a);
	repeat_rrb(head_b, next_b);
}

/**
 * @fn void nexta_prevb
 * @brief no use rr and rrr
 * @param[in] head_a
 * @param[in] head_b
 * @param[in] next_a number of rotation in stack_a to next direction
 * @param[in] prev_b number of rotation in stack_b to prev direction
 */

void	nexta_prevb(t_box **head_a, t_box **head_b, int next_a, int prev_b)
{
	repeat_rra(head_a, next_a);
	repeat_rb(head_b, prev_b);
}
