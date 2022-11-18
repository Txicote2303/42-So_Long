/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcarval <frcarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 21:31:23 by frcarval          #+#    #+#             */
/*   Updated: 2022/11/15 14:51:19 by frcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*map(void)
{
	static	t_map var;
	
	return (&var);
}

t_mapcp	*mapcp(void)
{
	static	t_mapcp var;
	
	return (&var);
}

t_window	*window(void)
{
	static	t_window var;
	
	return (&var);
}

t_img	*img(void)
{
	static	t_img var;
	
	return (&var);
}
