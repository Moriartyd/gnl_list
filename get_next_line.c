/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:19:21 by moriarty          #+#    #+#             */
/*   Updated: 2019/04/08 20:47:43 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_lstdelfile(t_list **head, int fd)
{
	t_list	*now;
	t_list	*prev;

	if ((!head || !(now = *head) || fd < 0))
		return (0);
	if ((now->content_size == (size_t)fd) && !(prev = NULL))
	{
		free(now->content);
		*head = now->next;
		free(now);
		return (0);
	}
	while (now)
	{
		if (now->content_size == (size_t)fd)
		{
			free(now->content);
			prev ? (prev->next = now->next) : (0);
			free(now);
			return (0);
		}
		prev = now;
		now = now->next;
	}
	return (0);
}

static t_list	*t_list_create_file(int fd)
{
	t_list	*res;

	res = (t_list *)malloc(sizeof(t_list));
	if (!res)
		return (NULL);
	res->content = ft_strnew(0);
	if (!res->content)
	{
		free(res);
		return (NULL);
	}
	res->content_size = fd;
	res->next = NULL;
	return (res);
}

static t_list	*get_file(int fd, t_list **head)
{
	t_list	*now;

	if (!head)
		return (NULL);
	now = *head;
	while (now)
	{
		if (now->content_size == (size_t)fd)
			return (now);
		now = now->next;
	}
	now = t_list_create_file(fd);
	if (!now)
		return (NULL);
	ft_lstadd(head, now);
	return (now);
}

static int		fillin_line(char **line, char *tmp, t_list *file, t_list **start)
{
	size_t	len;
	char	*strchr_tmp;
	char	*removen;

	len = ft_strlen(tmp);
	free(file->content);
	if (!tmp)
		return (-1);
	tmp ? (strchr_tmp = ft_strchr(tmp, '\n')) : (strchr_tmp = NULL);
	strchr_tmp ? (len = strchr_tmp - tmp) : (len = ft_strlen(tmp));
	*line = ft_strnew(len);
	*line = ft_strncpy(*line, tmp, len);
	if (strchr_tmp)
	{
		removen = ft_strdup(strchr_tmp + 1);
		ft_strdel(&tmp);
		file->content = removen;
	}
	if (!file->content || ! *line)
		return (ft_lstdelfile(start, file->content_size));
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				len;
	char			*t;
	static t_list	*start;
	t_list			*file;

	if (fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	len = 1;
	file = get_file(fd, &start);
	if (!file)
		return (-1);
	while ((len = read(fd, buf, BUFF_SIZE)) > 0 || 
		(file->content && ((char *)file->content)[0]))
	{
		buf[len] = '\0';
		t = ft_strjoin(file->content, buf);
		ft_putstr(t);
	ft_putchar('\n');
		if (t && (ft_strchr(t, '\n') || ((!ft_strchr(t, '\n') && len <= 0))))
			return (fillin_line(line, t, file, &start));
		ft_putstr("im here\n");
		free(file->content);
		file->content = t;
		if (!file->content)
			return (-1);
	}
	return (0);
}
