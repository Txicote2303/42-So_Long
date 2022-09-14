/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcarval <frcarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:22:34 by frcarval          #+#    #+#             */
/*   Updated: 2022/08/22 21:33:33 by frcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *wanna_be_counted)
{
	int	counter;

	counter = 0;
	while (wanna_be_counted[counter])
		counter++;
	return (counter);
}

char	*ft_substr(char *wanna_be_subed, int start, int len)
{
	char	*subed_one;
	int		i;

	if (!wanna_be_subed)
		return (0);
	i = 0;
	if (start >= ft_strlen(wanna_be_subed))
	{
		subed_one = malloc(sizeof(char));
		if (!subed_one)
			return (0);
		*subed_one = '\0';
		return (subed_one);
	}
	if (ft_strlen(wanna_be_subed) < len)
		return (ft_strdup((char *)wanna_be_subed + start));
	subed_one = (char *)malloc(len + 1 * sizeof(char));
	if (!subed_one)
		return (0);
	while (start < ft_strlen(wanna_be_subed) && i < len)
		subed_one[i++] = wanna_be_subed[start++];
	subed_one[i] = '\0';
	return (subed_one);
}

char	*ft_strdup(char *wanna_be_copied)
{
	int		counter;
	char	*clone;

	if (!wanna_be_copied)
		return (NULL);
	clone = (char *)malloc((ft_strlen(wanna_be_copied) + 1) * sizeof(char));
	counter = 0;
	while (wanna_be_copied[counter])
	{
		clone[counter] = wanna_be_copied[counter];
		counter++;
	}
	clone[counter] = '\0';
	return (clone);
}

int	ft_strchr(char *wanna_be_analyzed, char treasure)
{
	int	counter;
	int	size;

	size = ft_strlen(wanna_be_analyzed);
	counter = 0;
	while (counter <= size)
	{
		if (wanna_be_analyzed[counter] == treasure)
			return (counter);
		counter++;
	}
	return (-1);
}

char	*ft_strjoin(char *goku, char *vegeta)
{
	char	*gojeta;
	int		counter;
	int		another_counter;

	if (!goku || !vegeta)
		return (NULL);
	gojeta = malloc(sizeof(char) * (ft_strlen(goku) + ft_strlen(vegeta) + 1));
	counter = 0;
	while (goku[counter] != '\0')
	{
		gojeta[counter] = goku[counter];
		counter++;
	}
	another_counter = 0;
	while (vegeta[another_counter] != '\0')
	{
		gojeta[counter] = vegeta[another_counter];
		another_counter++;
		counter++;
	}
	gojeta[counter] = '\0';
	return (gojeta);
}
