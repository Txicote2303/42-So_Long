/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcarval <frcarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 04:26:06 by frcarval          #+#    #+#             */
/*   Updated: 2022/09/16 05:00:09 by frcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	new_window()
{
	window()->mlx_ptr = mlx_init();
	if(!window()->mlx_ptr)
		error("No mlx_ptr");
	window()->mlx_ptr = mlx_new_window(window()->mlx_ptr, map()->sizey * 16,  map()->sizex * 16, "so_long");
}