/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquek <wquek@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 09:30:09 by wquek             #+#    #+#             */
/*   Updated: 2024/09/02 01:54:47 by wquek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	char_count(t_list *list)
{
	int	i;
	int	j;

	j = 0;
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n')
				return (++j);
			i++;
			j++;
		}
		list = list->next;
	}
	return (j);
}

t_list	*ft_lstlast(t_list *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

t_list	*ft_lstnew(t_list **lst, char *buf)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
	{
		free(buf);
		free_lst(lst);
		return (NULL);
	}
	list->content = buf;
	list->next = NULL;
	return (list);
}

void	add_to_lst(t_list **list, char *buf)
{
	t_list	*last;

	last = ft_lstlast(*list);
	if (!last)
		*list = ft_lstnew(list, buf);
	else
		last->next = ft_lstnew(list, buf);
}

int	find_nl(t_list *list)
{
	int	i;

	while (list)
	{
		i = 0;
		while (list->content[i])
			if (list->content[i++] == '\n')
				return (1);
		list = list->next;
	}
	return (0);
}
