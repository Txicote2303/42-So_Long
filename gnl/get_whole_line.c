/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_whole_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcarval <frcarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 23:22:16 by frcarval          #+#    #+#             */
/*   Updated: 2022/09/15 22:10:34 by frcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_whole_line(int fd)
{
	static char	master[FOPEN_MAX][1];
	t_gnl		gnl;

	if (fd < 0 || 1 <= 0 || fd >= FOPEN_MAX)
		error("FD error");
		gnl.line = NULL;
		gnl.size = 0;
		gnl.counter = 0;
	while (1)
	{
		if (!master[fd][0])
			gnl.counter = read(fd, master[fd], 1);
		else
			gnl.counter = ft_finder(master[fd], '\0', 1);
		gnl.size += ft_finder(master[fd], '\0', 1);
		if (gnl.counter > 0)
			gnl.line = ft_slave(gnl.line, master[fd], gnl.size);
		if (ft_finder(gnl.line, '\0', -1) != -1 || gnl.counter <= 0)
			return (gnl.line);
	}
	return (gnl.line);
}
