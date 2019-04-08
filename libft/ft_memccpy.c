/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 15:12:27 by cpollich          #+#    #+#             */
/*   Updated: 2019/02/25 19:05:42 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	s;
	unsigned char	*su;
	unsigned char	*du;

	s = (unsigned char)c;
	du = (unsigned char *)dst;
	su = (unsigned char *)src;
	if (!n)
		return (NULL);
	while (n)
	{
		*du = *su;
		du++;
		if (*su == s)
			return ((void *)du);
		su++;
		n--;
	}
	return (NULL);
}
