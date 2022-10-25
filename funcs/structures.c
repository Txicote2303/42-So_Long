/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcarval <frcarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 21:31:23 by frcarval          #+#    #+#             */
/*   Updated: 2022/10/25 11:30:12 by frcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*map(void)
{
	static	t_map var;
	
	return (&var);
}
t_map	*mapcp(void)
{
	static	t_map var;
	
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