/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 17:08:17 by cpollich          #+#    #+#             */
/*   Updated: 2019/02/16 17:54:12 by moriarty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*temp;

	temp = dst;
	while (len)
	{
		len--;
		if (dst > src)
			*((unsigned char *)dst + len) = *((unsigned char *)src + len);
		else
		{
			*(unsigned char *)dst = *(unsigned char *)src;
			dst++;
			src++;
		}
	}
	return (temp);
}
