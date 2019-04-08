/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moriarty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 00:52:17 by moriarty          #+#    #+#             */
/*   Updated: 2019/02/25 18:44:21 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*trim;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = -1;
	if (!s)
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	if (!*s)
		return ((char *)s);
	len = ft_strlen(s) - 1;
	while (s[len - i] == ' ' || s[len - i] == '\n' || s[len - i] == '\t')
		i++;
	if (!(trim = ft_memalloc(len - i + 2)))
		return (NULL);
	while (++j < (len - i + 1))
		trim[j] = s[j];
	trim[j] = '\0';
	return (trim);
}
