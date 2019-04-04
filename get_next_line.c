static t_list	get_list(int fd, t_list **start)
{
	t_list	*current;

	if (!start)
		return (NULL);
	current = *start;
	while (current)
	{
		if (current->content_size == (size_t)fd)
			return (current);
		current = current->next;
	}
	if (!current)
		return (NULL);
	ft_lstadd(start, current);
	return (current);
}

static int		ft_ret(t_list *file, t_list **start, int len, char **line)
{
	char	*strchr_tmp;

	if (file->content)
		strchr_tmp = ft_strchr(file->content, '\n');
	else
		strchr_tmp = NULL;
	if (strchr_tmp)
	{
		free(*line);
		*line = ft_strdup(file->content, strchr_tmp - file->content)
	}
}

int	get_next_line(int fd, char **line)
{
	static t_list	*start;
	t_list			file;
	char			buf[BUFF_SIZE + 1];
	size_t			len;
	char			*tmp;

	if (fd < 0 || !line || (read(fd, buff, 0) < 0))
		return (-1);
	len = 1;
	file = get_list(fd, &start);
	tmp = NULL;

	while (!(ft_strchr_safe(file->content, '\n')) && len)
	{
		free(tmp);
		tmp = NULL;
		len = read(file->content_size, buff, BUFF_SIZE);
		buff[len] = '\0';
		tmp = ft_strjoin((char *)(file->content), buff);
		free(file->content);
		if (file->content)
			file->content = ft_strdup(tmp);
	}
	*line = tmp;
	return (ft_ret(file, &start, len, line));
}
