/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 13:16:22 by cpollich          #+#    #+#             */
/*   Updated: 2018/12/08 13:55:34 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	void *a;

	a = b;
	b = (unsigned char *)b;
	while (len)
	{
		*(unsigned char*)b = (unsigned char)c;
		b++;
		len--;
	}
	return (a);
}
