/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moriarty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 21:38:18 by moriarty          #+#    #+#             */
/*   Updated: 2019/02/11 15:03:47 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char		*strtrimch(char *s, char c)
{
	char	*trim;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = -1;
	if (!s)
		return (NULL);
	while (*s == c)
		s++;
	if (!*s)
		return ((char *)s);
	len = ft_strlen(s) - 1;
	while (s[len - i] == c)
		i++;
	trim = (char *)malloc(sizeof(char) * (len - i + 2));
	if (trim == NULL)
		return (NULL);
	while (++j < (len - i + 1))
		trim[j] = s[j];
	trim[j] = '\0';
	return (trim);
}

static size_t	how_much_words(char *s, char c)
{
	size_t	i;

	i = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		while (*s != c && *s != '\0')
			s++;
		i++;
	}
	return (i);
}

static size_t	word_len(char *s, char c)
{
	size_t	len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

static char		*fillin_word(char *s, char c, char *str)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = word_len(s, c);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (*s != c && *s != '\0')
	{
		str[i] = *s;
		i++;
		s++;
	}
	str[i] = '\0';
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	array_len;

	if (!s)
		return (NULL);
	i = 0;
	s = strtrimch((char *)s, c);
	array_len = how_much_words((char *)s, c);
	str = (char **)malloc(sizeof(char *) * (array_len + 1));
	if (str == NULL)
		return (NULL);
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		str[i] = fillin_word((char *)s, c, str[i]);
		while (*s != c && *s != '\0')
			s++;
		i++;
	}
	str[i] = 0;
	return (str);
}
