/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:03:01 by cpollich          #+#    #+#             */
/*   Updated: 2019/02/16 18:19:00 by moriarty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	sym;

	str = (unsigned char *)s;
	sym = (unsigned char)c;
	while (n)
	{
		if (*str == sym)
			return ((void *)str);
		str++;
		n--;
	}
	return (NULL);
}
