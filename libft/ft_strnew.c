/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 17:39:40 by cpollich          #+#    #+#             */
/*   Updated: 2019/01/17 18:19:51 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*array;
	size_t	check;

	check = 0;
	if (size == check - 1)
		return (NULL);
	array = ft_memalloc((size + 1) * sizeof(char));
	if (!array)
		return (NULL);
	return (array);
}
