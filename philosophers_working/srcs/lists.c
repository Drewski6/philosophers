/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 23:00:36 by dpentlan          #+#    #+#             */
/*   Updated: 2023/09/24 14:56:32 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*  *** ft_lstnew (42 list new) ***
 *
 *  Allocates and returns a new node. The member variable 'content' is
 *  initialized with the value of the parameter 'content'. The variable 'next'
 *  is initialized to NULL.
 *  Returns 0 if allocation unsuccessful.
 *  Returns pointer to new list head if successful.
 */

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(1 * sizeof(t_list));
	if (!new)
		return (0);
	new->content = content;
	new->next = NULL;
	return (new);
}

/*  *** ft_lstlast (42 list last) ***
 *
 *  Returns the last node of the list.
 */

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current;

	current = lst;
	if (!current)
		return (0);
	while (current->next)
		current = current->next;
	return (current);
}

/*  *** ft_lstadd_back (42 list add back) ***
 *
 *  Adds the node 'new' at the end of the list.
 *  Returns nothing.
 */

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	current = 0;
	current = ft_lstlast(*lst);
	if (!current)
		*lst = new;
	else
		current->next = new;
}

/*  *** ft_lstsize (42 list size) ***
 *
 *  Counts the number of nodes in a list.
 *  Counts by moving to next node and count number of moves until lst->next
 *  equals NULL.
 *  Returns number of nodes as an int.
 */

int	ft_lstsize(t_list *lst)
{
	int	size;

	if (!lst)
		return (0);
	size = 1;
	while (lst->next)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

/*  *** ft_lstdelone (42 list delete one) ***
 *
 *  Takes as a parameter a node and frees the memory of the node's content using
 *  the function 'del' given as a parameter and free the node.
 *  The memory address 'next' is not freed.
 *  Returns nothing.
 */

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == 0 || del == 0)
		return ;
	del(lst->content);
	free(lst);
}
