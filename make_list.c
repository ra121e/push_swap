/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:22:20 by athonda           #+#    #+#             */
/*   Updated: 2024/07/12 13:37:05 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file make_list.c
 * @brief make new node, store numbers in node, connect nodes, point head node
 */

#include "push_swap.h"

/**
 * @fn int ft_atoi(const char *nptr)
 * @brief combine the number characters into number value
 * @param[in] nptr
 * @return the value or 0 in case error
 * @sa ft_isdigit ft_isspace:inside the file
 * @note get string by pointer and check each char by 3 stage rocket
	- 1st stage ignore space
	- 2nd stage check + or -
	- 3rd stage get number and convert into a variable
	- finally put negative
*/

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n' || \
		c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	nbr;
	int	sign;
	int	i;

	sign = 1;
	nbr = 0;
	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		nbr = nbr * 10 + (nptr[i] - '0');
		i++;
	}
	return (nbr * sign);
}

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

t_box	*ft_lstcut_front(t_box **lst)
{
	t_box	*box1;
	t_box	*box2;
	t_box	*last_box;

	box1 = *lst;
	if (box1 == NULL)
		return(NULL);
	box2 = box1->next;
	if (box2 == NULL)
		*lst = NULL;
	else
	{
		last_box = box1->prev;
		if (last_box == box2)
		{
			box2->next = NULL;
			box2->prev = NULL;
		}
		else
		{
			box2->prev = last_box;
			last_box->next = box2;
		}
		*lst = box2;
	}
	box1->next = NULL;
	box1->prev = NULL;
	return (box1);
}
/**
 * @fn t_box	*make_list(t_box *head, char **nbrs)
 * @brief get numbers array and complete link list
 * @note How to initialize head node
	- lst functions check list existance by NULL of head node.
	- **head declare and NULL init hit NULL check in lst handles
	- *head declare and NULL init means &head itself is not NULL
 */

t_box	*make_list(t_box *head_a, char **nbrs)
{
	int	nbr;
	t_box	*node;

	head_a = NULL;
	while (*nbrs)
	{
		nbr = ft_atoi(*nbrs);
		node = ft_lstnew(nbr);
		ft_lstadd_back(&head_a, node);
		nbrs++;
	}
	return (head_a);
}