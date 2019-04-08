/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 20:01:15 by cpollich          #+#    #+#             */
/*   Updated: 2019/02/14 21:56:58 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*cur_el;
	t_list	*first_el;
	t_list	*tmpf;

	if (!lst || !f)
		return (NULL);
	tmp = lst;
	cur_el = f(lst);
	if (!(first_el = ft_lstnew(cur_el->content, cur_el->content_size)))
		return (NULL);
	lst = tmp->next;
	tmpf = first_el;
	while (lst)
	{
		tmp = lst;
		cur_el = f(lst);
		if (!(first_el->next = ft_lstnew(cur_el->content,
						cur_el->content_size)))
			return (NULL);
		first_el = first_el->next;
		lst = tmp->next;
	}
	return (tmpf);
}
