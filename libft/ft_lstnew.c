/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moriarty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 19:13:27 by moriarty          #+#    #+#             */
/*   Updated: 2019/02/14 21:58:27 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*el;

	el = (t_list *)malloc(sizeof(t_list));
	if (el == NULL)
		return (NULL);
	if (!content)
	{
		el->content = NULL;
		el->content_size = 0;
	}
	else
	{
		el->content_size = content_size;
		el->content = ft_memalloc(content_size);
		ft_memcpy(el->content, content, content_size);
	}
	el->next = NULL;
	return (el);
}
