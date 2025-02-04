/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 15:01:58 by cpollich          #+#    #+#             */
/*   Updated: 2019/02/25 18:50:14 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void *r;

	r = dst;
	if (!dst && !src)
		return (dst);
	while (n)
	{
		*(char*)dst = *(char*)src;
		dst++;
		src++;
		n--;
	}
	return ((void*)r);
}
