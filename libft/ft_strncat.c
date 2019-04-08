/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 14:11:13 by cpollich          #+#    #+#             */
/*   Updated: 2018/12/01 17:13:01 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char *restrict	ret;
	size_t			i;

	i = 0;
	ret = s1;
	while (*s1)
		s1++;
	while (i < n && *s2)
	{
		*s1 = (char)*s2;
		s1++;
		s2++;
		i++;
	}
	*s1 = '\0';
	return (ret);
}
