
#include "get_next_line.h"

static	char		*check(t_list *tmp, char **line)
{
	char *endl;
	char *ptr;

	if (tmp->remainder)
	{
		if ((endl = ft_strchr(tmp->remainder, '\n')) != NULL)
		{
			*endl = '\0';
			*line = ft_strdup(tmp->remainder);
			ptr = ft_strdup(endl + 1);
			free(tmp->remainder);
			return (ptr);
		}
		else
		{
			*line = ft_strdup(tmp->remainder);
			free(tmp->remainder);
		}
	}
	else
	{
		*line = malloc(sizeof(char) * 1);
		**line = '\0';
	}
	return (NULL);
}

static	void		listdel(t_list *tmp, t_list **info, t_list *tmp2)
{
	if (tmp->next == NULL)
	{
		if (tmp == *info)
			*info = NULL;
		else
		{
			while (tmp2->next != tmp)
				tmp2 = tmp2->next;
			tmp2->next = NULL;
		}
		free(tmp);
	}
	else if (tmp == *info && tmp->next != NULL)
	{
		*info = tmp->next;
		free(tmp);
	}
	else
	{
		while (tmp2->next != tmp)
			tmp2 = tmp2->next;
		tmp2->next = tmp->next;
		free(tmp);
	}
}

static	int			errors(int red, t_list *tmp, t_list **info)
{
	t_list	*tmp2;

	tmp2 = *info;
	if ((red == 0 && (tmp->remainder == NULL)) || red == -1)
	{
		listdel(tmp, info, tmp2);
		return (red == -1 ? -1 : 0);
	}
	return (1);
}

static	int			getl(char **line, t_list *tmp, int fd, char *buf)
{
	char	*endl;
	int		red;

	red = 0;
	while (!(tmp->remainder) && (red = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[red] = '\0';
		if ((endl = ft_strchr(buf, '\n')) != NULL)
		{
			*endl = '\0';
			if (*(endl + 1) != '\0')
				tmp->remainder = ft_strdup(endl + 1);
			else
			{
				endl = ft_strjoin(*line, buf);
				free(*line);
				*line = endl;
				break ;
			}
		}
		endl = ft_strjoin(*line, buf);
		free(*line);
		*line = endl;
	}
	return (red);
}

int					get_next_line(int fd, char **line)
{
	static	t_list	*info;
	t_list			*tmp;
	int				red;
	char			*buf;

	if (BUFFER_SIZE < 1 || !line || fd < 0)
		return (-1);
	tmp = info;
	while (tmp && tmp->fd != fd && tmp->next)
		tmp = tmp->next;
	if (!tmp || !(tmp->fd == fd))
		if (!(tmp = infonew(fd, &info)))
			return (-1);
	tmp->remainder = check(tmp, line);
	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	red = getl(line, tmp, fd, buf);
	free(buf);
	return (errors(red, tmp, &info));
}
