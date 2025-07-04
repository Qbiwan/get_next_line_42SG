/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquek <wquek@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 09:28:17 by wquek             #+#    #+#             */
/*   Updated: 2024/09/02 01:54:24 by wquek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	duplicate(t_list *list, char *s)
{
	int	i;
	int	j;

	j = 0;
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			s[j] = list->content[i];
			if (list->content[i] == '\n')
			{
				s[++j] = '\0';
				return ;
			}
			i++;
			j++;
		}
		list = list->next;
	}
	s[j] = '\0';
}

void	free_lst(t_list **list)
{
	t_list	*temp;

	while (*list)
	{
		temp = (*list)-> next;
		free((*list)->content);
		free(*list);
		*list = temp;
	}
}

void	residual(t_list **list)
{
	t_list	*last;
	int		i;
	int		j;
	char	*buf;

	i = 0;
	j = 0;
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free_lst(list));
	last = ft_lstlast(*list);
	while (last->content[i] && last->content[i] != '\n')
		i++;
	while (last->content[i++])
	{
		if (last->content[i])
			buf[j++] = last->content[i];
	}		
	buf[j] = '\0';
	free_lst(list);
	if (!buf[0])
		free(buf);
	else
		*list = ft_lstnew(list, buf);
}

void	create_list(t_list	**list, int fd)
{
	char			*buf;
	int				num_char;

	while (!find_nl(*list))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return (free_lst(list));
		num_char = read(fd, buf, BUFFER_SIZE);
		if (!num_char)
			return (free(buf));
		if (num_char < 0)
			return (free(buf), free_lst(list));
		buf[num_char] = '\0';
		add_to_lst(list, buf);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*s;
	int				len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	create_list(&list, fd);
	if (!list)
		return (NULL);
	len = char_count(list);
	s = malloc(len + 1);
	if (!s)
	{
		free_lst(&list);
		return (NULL);
	}
	duplicate(list, s);
	residual(&list);
	return (s);
}
