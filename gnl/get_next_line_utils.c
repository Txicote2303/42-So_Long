/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcarval <frcarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 23:22:18 by frcarval          #+#    #+#             */
/*   Updated: 2022/09/15 03:39:56 by frcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_slave(char *line, char *master, int line_size)
{
	t_slave	slave;

	slave.temp = line;
	slave.indx = -1;
	line = malloc(sizeof(char) * (line_size + 1));
	slave.counter = 0;
	while (slave.temp && slave.temp[slave.counter])
		line[slave.counter++] = slave.temp[slave.counter];
	slave.another_counter = 0;
	while (master[slave.another_counter])
	{
		if (slave.indx == -1)
		{
			line[slave.counter++] = master[slave.another_counter];
			if (master[slave.another_counter] == '\n')
				slave.indx++;
		}
		else
			master[slave.indx++] = master[slave.another_counter];
		master[slave.another_counter++] = 0;
	}
	if (slave.temp)
		free(slave.temp);
	line[line_size] = '\0';
	return (line);
}

int	ft_finder(char *str, char chr, int selector)
{
	int	counter;

	counter = 0;
	if (selector == -1)
	{
		while (str && str[counter])
		{
			if (str[counter] == chr)
				return (counter);
			counter++;
		}
		return (-1);
	}
	while (str && str[counter])
	{
		if (str[counter] == chr)
			return (counter + 1);
		counter++;
	}
	return (counter);
}
