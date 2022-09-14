/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcarval <frcarval@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:03:33 by frcarval          #+#    #+#             */
/*   Updated: 2022/09/14 19:02:58 by frcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_slave
{
	char	*temp;
	int		counter;
	int		another_counter;
	int		indx;
}	t_slave;

typedef struct s_gnl
{
	char	*line;
	int		counter;
	int		size;
}	t_gnl;

typedef	struct s_map {
	int		sizex;
	int		sizey;
	char	*mapline;
	char	**matrix;
}				t_map;

//general functions
void	error();
int	stringcmp(char	*str1, char	*str2);
//map functions
t_map	*map(void);
void	map_read(char	*path);
void	verification(char	*content, char	*extra);
void	ver_ber(char	*path);
void	ver_clean();
void	map_creator();
void	matrix_filler();
//GNL functions
char	*get_next_line(int fd);
char	*ft_slave(char *line, char *master, int line_size);
int	ft_finder(char *str, char chr, int selector);

#endif
/*

Needed Stuff
- win_ptr
- mlx_ptr

- map Verifications
	- is_ber 			V
	- has_path
	- size
	- has_wall
	- has_character
	- has_collectable
	- has_finish
	- is_clean			V

- map stats
	- images
	- sizeX/Y
	- map_matrix

- player Stuff
	
*/