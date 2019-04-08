/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 18:32:33 by cpollich          #+#    #+#             */
/*   Updated: 2019/02/11 14:10:22 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *tmp;

	if (!*s)
		return (NULL);
	tmp = NULL;
	while (*s)
	{
		if (*(unsigned char*)s == (unsigned char)c)
			tmp = (char*)s;
		s++;
	}
	if (*(unsigned char*)s == (unsigned char)c)
		return ((char*)s);
	else
		return ((char*)tmp);
}
