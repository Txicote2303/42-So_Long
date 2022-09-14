/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcarval <frcarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:17:40 by frcarval          #+#    #+#             */
/*   Updated: 2022/06/21 02:11:53 by frcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*le_separateur(char **holy_one)
{
	char	*garbage;
	char	*trash;
	int		i;

	if (!*holy_one || **holy_one == '\0')
		return (0);
	i = ft_strchr(*holy_one, '\n');
	if (i >= 0)
	{
		trash = ft_substr(*holy_one, 0, i + 1);
		garbage = ft_substr(*holy_one, i + 1, ft_strlen(*holy_one));
		free (*holy_one);
		*holy_one = garbage;
		if (**holy_one != '\0')
			return (trash);
	}
	else
		trash = ft_strdup(*holy_one);
	free (*holy_one);
	*holy_one = 0;
	return (trash);
}

char	*get_next_line(int fd)
{
	static char	*holy_one;
	char		buffy_boy[1 + 1];
	char		*garbage;
	int			counter;

	if (fd < 0 || 1 <= 0 || fd > 4096)
		return (NULL);
	counter = read(fd, buffy_boy, 1);
	while (counter > 0)
	{
		if (!holy_one)
			holy_one = ft_strdup("");
		buffy_boy[counter] = '\0';
		garbage = ft_strjoin(holy_one, buffy_boy);
		free(holy_one);
		holy_one = garbage;
		counter = read(fd, buffy_boy, 1);
	}
	return (holy_one);
}
