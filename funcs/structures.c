/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcarval <frcarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 21:31:23 by frcarval          #+#    #+#             */
/*   Updated: 2022/09/16 04:06:12 by frcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*map(void)
{
	static	t_map var;
	
	return (&var);
}
t_window	*window(void)
{
	static	t_window var;
	
	return (&var);
}