/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 20:50:09 by cpollich          #+#    #+#             */
/*   Updated: 2018/11/30 20:30:22 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *d;

	d = dst;
	while (len && *src)
	{
		*dst = *src;
		dst++;
		src++;
		len--;
	}
	while (len && *dst)
	{
		*dst = '\0';
		dst++;
		len--;
	}
	return (d);
}
