/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wquek <wquek@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 17:27:41 by wquek             #+#    #+#             */
/*   Updated: 2024/09/02 01:24:57 by wquek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10 
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
int		count_till_nl(char *s);
int		char_count(t_list *list);
t_list	*ft_lstlast(t_list *list);
t_list	*ft_lstnew(t_list **lst, char *buf);
void	add_to_lst(t_list **list, char *buf);
int		find_nl(t_list *list);
void	duplicate(t_list *list, char *s);
void	free_lst(t_list **list);
void	residual(t_list **list);
void	create_list(t_list **list, int fd);
char	*get_lines(t_list *list);

#endif
