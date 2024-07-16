/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:15:08 by athonda           #+#    #+#             */
/*   Updated: 2024/07/16 10:44:17 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lst_utils.c
 * @brief linked list operation functions
 * @note ft_lstcut_front is new for this project
 */

#include "push_swap.h"

/**
 * @fn l_list	*ft_lstnew(void *content)
 * @brief make memory area by malloc and set content in the member
 * @param[in]	content any pointer to be set in the list box
 * @return pointer to the beginning of the list
 * @sa malloc
 * @note
	- 1)malloc make 1 size of t_list and cast to t_list type
	- 2)store content in content place
	- 3)set NULL in the next member. its used for linking to other box
*/

t_box	*ft_lstnew(int nbr)
{
	t_box	*ptr;

	ptr = (t_box *)malloc(sizeof (t_box) * 1);
	if (!ptr)
		return (NULL);
	ptr->value = nbr;
	ptr->next = NULL;
	return (ptr);
}

/**
 * @fn void	ft_lstadd_front(t_list **lst, t_list *new)
 * @brief
 * @param[in]	lst special pointer to the first box address
 * @param[in]	new pointer to the new box to be added
 * @return none
 * @note applied on List (not node)
	- head and new node receive
	- result is in List(no need return)
*/

void	ft_lstadd_front(t_box **lst, t_box *new)
{
	t_box	*ptr;

	ptr = ft_lstlast(*lst);
	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		new->next = *lst;
		new->prev = ptr;
		(*lst)->prev = new;
		ptr->next = new;
		*lst = new;
	}
}

/**
 * @fn t_list	*ft_lstlast(t_list *lst)
 * @brief
 * @param[in]	lst pointer to the first box
 * @return pointer to the last box
 * @note lstlast is focusing on Node(Link List Rule)
	- 1st node is the clue To reach the last node
	- gives us node address same as lstnew
*/

t_box	*ft_lstlast(t_box *lst)
{
	t_box	*ptr;

	ptr = lst;
	if (ptr == NULL)
		return (NULL);
	while (ptr->next != NULL && ptr->next != lst)
	{
		ptr = ptr->next;
	}
	return (ptr);
}

/**
 * @fn void	ft_lstadd_back(t_list **lst, t_list *new)
 * @brief proceed to the tail box and link new box
 * @param[in]	lst the special pointer storeing the address of the first box
 * @param[in]	new the new node to be added
 * @return none
 * @sa ft_lstlast
 * @attention *(lst)->next == NULL
 * @note Why is 1st arge the HEAD pointer by double pointer?
	in case of no link list, the new will be the first one. HEAD point it
*/

void	ft_lstadd_back(t_box **lst, t_box *new)
{
	t_box	*ptr;
	t_box	*p;

	if (lst == NULL)
		return ;
	p = *lst;
	ptr = ft_lstlast(*lst);
	if (ptr == NULL)
	{
		*lst = new;
	}
	else
	{
		ptr->next = new;
		new->prev = ptr;
		new->next = *lst;
		p->prev = new;
	}
	return ;
}

/**
 * @fn t_box	*ft_lstcut_front(t_box **lst)
 * @brief separate the top node from the list
 * @param[in] lst address of the pointer to top node
 * @return box1 pointer to the separated node
 */

t_box	*ft_lstcut_front(t_box **lst)
{
	t_box	*box1;

	box1 = *lst;
	if (box1 == NULL)
		return(NULL);
	if (box1->next == NULL)
		*lst = NULL;
	else
	{
		if (box1->prev == box1->next)
		{
			(box1->next)->next = NULL;
			(box1->next)->prev = NULL;
		}
		else
		{
			(box1->next)->prev = (box1->prev);
			(box1->prev)->next = (box1->next);
		}
		*lst = box1->next;
	}
	box1->next = NULL;
	box1->prev = NULL;
	return (box1);
}
